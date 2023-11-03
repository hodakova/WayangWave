#include "mesinbaris.h"

void ADVBARIS() {
    while(currentChar != EOL)
        ADV();
    IgnoreEOL();
    ADVWORD();
}

void currentWordTillEOL() {
    int i = currentWord.Length;
    if(i > 0) {    
        currentWord.TabWord[i] = ' ';
        i ++;
        ADV();
    }
    while(currentChar != EOL && currentChar != CR) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i ++;
    }
    currentWord.Length = i;
}