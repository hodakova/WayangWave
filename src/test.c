#include "ADT/mesinkar/mesinkarakterv2.c"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/mesinbaris/mesinbaris.c"
#include "ADT/list/list.c"
// #include "ADT/wayangwave/config.c"
// #include "ADT/wayangwave/commands/start.c"
#include <stdio.h>


int main() {
    /*
    STARTWORDFILE("../save/config.txt");*/
    /*TEST BARIS*//*
    for(int i = 0; i < 30; i ++) {
        currentWordTillEOL();
        printWord(currentWord);
        printf("\n");
        ADVBARIS();
    }
    */
    /*TEST WORD
    for(int i = 0; i < 100; i ++) {
        printWord(currentWord);
        printf(" ");
        ADVWORD();
    }*/
    STARTWORD();
    Word Kata = currentWord;
    printf("%s", Word2str(Kata));
    return 0;
}