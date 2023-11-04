#include "start.h"

void StartWW() {
    int i, j, k;
    STARTWORD("../save/config.txt");

    Config.N = Word2int(currentWord);// printWord(currentWord); printf("\n");
    ADVBARIS();// ^^ Jumlah Penyanyi ^^

    for(i = 0; i < Config.N; i ++) {
        Config.Penyanyi[i].M = Word2int(currentWord);// printWord(currentWord); printf(", ");
        ADVWORD();// ^^ Jumlah Album ^^

        currentWordTillEOL();
        Config.Penyanyi[i].Nama = currentWord;// printWord(currentWord); printf("\n");
        ADVBARIS();// ^^ Nama Penyanyi ^^


        for(j = 0; j < Config.Penyanyi[i].M; j ++) {
            Config.Penyanyi[i].Album[j].L = Word2int(currentWord);// printWord(currentWord); printf(", ");
            ADVWORD();// ^^ Jumlah Lagu ^^

            currentWordTillEOL();
            Config.Penyanyi[i].Album[j].Nama = currentWord;// printWord(currentWord); printf("\n");
            ADVBARIS();// ^^ Nama Album ^^
            
            for(k = 0; k < Config.Penyanyi[i].Album[j].L; k ++) {
                currentWordTillEOL();// printWord(currentWord); printf("\n");
                ListInsertLast(&(Config.Penyanyi[i].Album[j].Lagu), currentWord);
                ADVBARIS();// ^^ Nama Lagu ^^
            }
        }
    }
}