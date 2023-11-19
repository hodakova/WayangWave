#include "ADT/mesinkar/mesinkarakterv2.c"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/mesinbaris/mesinbaris.c"
#include "ADT/list/list.c"
// #include "ADT/wayangwave/config.c"
// #include "ADT/wayangwave/commands/start.c"
#include <stdio.h>


int main() {
    STARTWORDFILE("../save/testsc.txt");

    currentWordTillSC();
    printWord(currentWord);
    printf("\n");
    ADVWORD();

    currentWordTillSC();
    printWord(currentWord);
    printf("\n");
    ADVWORD();

    currentWordTillEOL();
    printWord(currentWord);
    printf("\n");
    ADVBARIS();
    
    ADVBARIS();

    currentWordTillSC();
    printWord(currentWord);
    printf("\n");
    ADVWORD();

    currentWordTillSC();
    printWord(currentWord);
    printf("\n");
    ADVWORD();

    currentWordTillEOL();
    printWord(currentWord);
    printf("\n");
    ADVBARIS();

    return 0;
}