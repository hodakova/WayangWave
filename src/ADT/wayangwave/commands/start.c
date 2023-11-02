#include "start.h"
#include "../../mesinkar/mesinkarakterv2.h"
#include "../../mesinkata/mesinkata.h"
#include "../../mesinbaris/mesinbaris.h"
#include "../config.h"

void StartWW() {
    int i, j, k, l;
    STARTWORD("../save/config.txt");

    Config.N = Word2int(currentWord);
    ADVBARIS(); // ^^ Jumlah Penyanyi ^^

    for(i = 0; i < Config.N; i ++) {
        Config.Penyanyi[i].M = Word2int(currentWord);
        ADVWORD(); // ^^ Jumlah Album ^^

        currentWordTillEOL();
        Config.Penyanyi[i].Nama = currentWord;
        ADVBARIS(); // ^^ Nama Penyanyi ^^

        for(j = 0; j < Config.Penyanyi[i].M; j ++) {
            l = Word2int(currentWord);
            ADVWORD(); // ^^ Jumlah Lagu ^^

            currentWordTillEOL();
            Config.Penyanyi[i].Album[j].Nama = currentWord;
            ADVBARIS(); // ^^ Nama Album ^^
            
            for(k = 0; k < l; k ++) {
                currentWordTillEOL();
                InsertLast(&(Config.Penyanyi[i].Album[j].Lagu), currentWord);
                ADVBARIS(); // ^^ Nama Lagu ^^
            }
        }
    }

}