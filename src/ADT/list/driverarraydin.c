#include <stdio.h>
#include "arraydin.h"
#include "../mesinkata/mesinkata.h"

int main() {
    ArrayDin temp = MakeArrayDin();
    if (IsArrayDinEmpty(temp)) {
        printf("Array kosong \n");
    }
    ArrayDinElType el;
    STARTWORD(); currentWordTillSC();
    el.NamaPlaylist = currentWord;
    ArrayDinInsertLast(&temp, el);
    PrintArrayDin(temp); //bentuk awal setelah memasukkan elemen ke dalam arraydin
    ArrayDinDeleteLast(&temp);
    PrintArrayDin(temp); //bentuk akhir setelah dihapus
}