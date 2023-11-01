#include "start.h"
#include "../../mesinkata/mesinkata.h"
#include "../config.c"

void StartWW() {
    int i;
    STARTWORD("../../../../save/config.txt");
    Config.N = Word2int(currentWord);
    /*ADVBARIS();
    for(i = 0; i < Config.N; i ++) {
        Config.Penyanyi[i].M = Word2int(currentWord);
        Config.Penyanyi[i].Nama = currentWord;
    }*/
    printf("%d", Config.N);
}