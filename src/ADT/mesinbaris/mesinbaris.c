#include "mesinbaris.h"

void ADVBARIS() {
    while(currentChar != EOL) {
        ADV();
    }
    ADV();
}

void currentWordTillEOL() {
    char prev;
    int i = currentWord.Length;
    ADV();
    while(currentChar != EOL && currentChar != '#') {
        prev = currentChar;
        ADV();

        if(currentChar != '#') {
            currentWord.TabWord[i] = prev;
            i ++;
        }
    }
    if(currentChar != '#') {
        i ++;
        currentWord.TabWord[i] = currentChar;
    }
}