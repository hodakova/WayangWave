#include "arraydin.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.Capacity = InitialSize;
    array.Neff = 0;
    array.A = (ElType*)malloc(sizeof(ElType)*GetCapacity(array));
    return array;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array) {
    free((*array).A);
    (*array).Neff = 0;
    (*array).Capacity = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array) {
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array) {
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i) {
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array) {
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i) {
    int j;

    if(Length(*array) == GetCapacity(*array)) {
        ElType *arrtemp = (ElType*)malloc(sizeof(ElType) * GetCapacity(*array));
        for(j = 0; j < Length(*array); j ++)
            arrtemp[j] = Get(*array, j);
        free((*array).A);

        (*array).Capacity *= 2;
        (*array).A = (ElType*)malloc(sizeof(ElType) * GetCapacity(*array));
        for(j = 0; j < Length(*array); j ++)
            (*array).A[j] = arrtemp[j];
        free(arrtemp);
    }

    for(j = Length(*array); j > i; j --)
        (*array).A[j] = Get(*array, j-1);
    (*array).A[i] = el;
    (*array).Neff ++;

}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el) {
    InsertAt(array, el, Length(*array));
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el) {
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i) {
    int j;
    
    for(j = i; j < Length(*array) -1; j ++)
        (*array).A[j] = Get(*array, j +1);
    (*array).Neff --;

    if(Length(*array) +1 == GetCapacity(*array) /2 && GetCapacity(*array) /2 > InitialSize) {
        ElType *arrtemp = (ElType*)malloc(sizeof(ElType) * Length(*array));
        for(j = 0; j < Length(*array); j ++)
            arrtemp[j] = Get(*array, j);
        free((*array).A);
    
        (*array).Capacity /= 2;
        (*array).A = (ElType*)malloc(sizeof(ElType) * GetCapacity(*array));
        for(j = 0; j < Length(*array); j ++)
            (*array).A[j] = arrtemp[j];
        free(arrtemp);
    }
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array) {
    DeleteAt(array, Length(*array) -1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array) {
    DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array) {
    printf("[");
    int i, l = Length(array);
    for(i = 0; i < l; i ++) {
        printf("%d", Get(array, i));
        if(i < l -1)
            printf(", ");
    }
    printf("]\n");
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array) {
    ArrayDin arres = MakeArrayDin();
    for(int i = 0; i < Length(array); i ++)
        InsertLast(&arres, Get(array, i));
    return arres;
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array) {
    int i, l = Length(*array);
    ArrayDin arrev = MakeArrayDin();
    for(i = 0; i < l; i ++)
        InsertFirst(&arrev, Get(*array, i));
    DeallocateArrayDin(array);
    *array = CopyArrayDin(arrev);
    DeallocateArrayDin(&arrev);
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el) {
    IdxType r = -1;
    int i = 0;
    while(i < Length(array) && r == -1) {
        if(Get(array, i) == el)
            r = i;
        else
            i ++;
    }
    return r;
}