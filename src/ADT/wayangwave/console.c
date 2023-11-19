#include "console.h"

void StartWW(List *Penyanyi) {
    int i, j, k, N, M, L;
    STARTWORDFILE("../save/config.txt");

    N = Word2int(currentWord);//printWord(currentWord); printf("\n");
    ADVBARIS();// ^^ Jumlah Penyanyi ^^

    for (i = 0; i < N; i++){
        M = Word2int(currentWord);//printWord(currentWord); printf("\n");
        ADVWORD();// ^^ Jumlah Penyanyi ^^

        currentWordTillEOL();
        (*Penyanyi).A[i].NamaPenyanyi = currentWord;
        ADVBARIS();

        for (j = 0; j < M; j++){
            L = Word2int(currentWord);
            ADVWORD();

            currentWordTillEOL();
            (*Penyanyi).A[i].Album.Elements[j].Key = i;
            (*Penyanyi).A[i].Album.Elements[j].Value.NamaAlbum = currentWord;
            ADVBARIS();

            for(k = 0; k < L; k ++) {
                currentWordTillEOL();
                SetInsert(&((*Penyanyi).A[i].Album.Elements[j].Value.Lagu), currentWord);
                ADVBARIS();
            }
        }
    }
}