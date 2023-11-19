#include "arraydin.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran ArrayDinInitialSize
 */
ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.Capacity = ArrayDinInitialSize;
    array.Neff = 0;
    array.A = (ArrayDinElType*)malloc(sizeof(ArrayDinElType)*ArrayDinGetCapacity(array));
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
boolean IsArrayDinEmpty(ArrayDin array) {
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int ArrayDinLength(ArrayDin array) {
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..ArrayDinLength(array).
 */
ArrayDinElType ArrayDinGet(ArrayDin array, ArrayDinIdxType i) {
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int ArrayDinGetCapacity(ArrayDin array) {
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..ArrayDinLength(array).
 */
void ArrayDinInsertAt(ArrayDin *array, ArrayDinElType el, ArrayDinIdxType i) {
    int j;

    if(ArrayDinLength(*array) == ArrayDinGetCapacity(*array)) {
        ArrayDinElType *arrtemp = (ArrayDinElType*)malloc(sizeof(ArrayDinElType) * ArrayDinGetCapacity(*array));
        for(j = 0; j < ArrayDinLength(*array); j ++)
            arrtemp[j] = ArrayDinGet(*array, j);
        free((*array).A);

        (*array).Capacity *= 2;
        (*array).A = (ArrayDinElType*)malloc(sizeof(ArrayDinElType) * ArrayDinGetCapacity(*array));
        for(j = 0; j < ArrayDinLength(*array); j ++)
            (*array).A[j] = arrtemp[j];
        free(arrtemp);
    }

    for(j = ArrayDinLength(*array); j > i; j --)
        (*array).A[j] = ArrayDinGet(*array, j-1);
    (*array).A[i] = el;
    (*array).Neff ++;

}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void ArrayDinInsertLast(ArrayDin *array, ArrayDinElType el) {
    ArrayDinInsertAt(array, el, ArrayDinLength(*array));
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void ArrayDinInsertFirst(ArrayDin *array, ArrayDinElType el) {
    ArrayDinInsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..ArrayDinLength(array).
 */
void ArrayDinDeleteAt(ArrayDin *array, ArrayDinIdxType i) {
    int j;
    
    for(j = i; j < ArrayDinLength(*array) -1; j ++)
        (*array).A[j] = ArrayDinGet(*array, j +1);
    (*array).Neff --;

    if(ArrayDinLength(*array) +1 == ArrayDinGetCapacity(*array) /2 && ArrayDinGetCapacity(*array) /2 > ArrayDinInitialSize) {
        ArrayDinElType *arrtemp = (ArrayDinElType*)malloc(sizeof(ArrayDinElType) * ArrayDinLength(*array));
        for(j = 0; j < ArrayDinLength(*array); j ++)
            arrtemp[j] = ArrayDinGet(*array, j);
        free((*array).A);
    
        (*array).Capacity /= 2;
        (*array).A = (ArrayDinElType*)malloc(sizeof(ArrayDinElType) * ArrayDinGetCapacity(*array));
        for(j = 0; j < ArrayDinLength(*array); j ++)
            (*array).A[j] = arrtemp[j];
        free(arrtemp);
    }
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void ArrayDinDeleteLast(ArrayDin *array) {
    ArrayDinDeleteAt(array, ArrayDinLength(*array) -1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void ArrayDinDeleteFirst(ArrayDin *array) {
    ArrayDinDeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array) {
    printf("[");
    int i, l = ArrayDinLength(array);
    for(i = 0; i < l; i ++) {
        printf("%d", ArrayDinGet(array, i));
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
    for(int i = 0; i < ArrayDinLength(array); i ++)
        ArrayDinInsertLast(&arres, ArrayDinGet(array, i));
    return arres;
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array) {
    int i, l = ArrayDinLength(*array);
    ArrayDin arrev = MakeArrayDin();
    for(i = 0; i < l; i ++)
        ArrayDinInsertFirst(&arrev, ArrayDinGet(*array, i));
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
ArrayDinIdxType SearchArrayDin(ArrayDin array, ArrayDinElType el) {
    // ArrayDinIdxType r = -1;
    // int i = 0;
    // while(i < ArrayDinLength(array) && r == -1) {
    //     if(ArrayDinGet(array, i) == el)
    //         r = i;
    //     else
    //         i ++;
    // }
    // return r;
}