#include "stack.h"


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas StackMaxEl */
/* jadi indeksnya antara 0..StackMaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai StackNil */
{
    StackTop(*S) = StackNil;
}


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return StackTop(S) == StackNil;
}

boolean IsStackFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return StackTop(S) == StackMaxEl -1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, StackInfoType X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */
{
    if(IsEmpty(*S))
        StackTop(*S) = 0;
    else
        StackTop(*S) ++;
    StackInfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack* S, StackInfoType* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = StackInfoTop(*S);
    if(StackTop(*S) == 0)
        CreateStack(S);
    else
        StackTop(*S) --;
}
