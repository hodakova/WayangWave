#include <stdio.h>
#include "mesinkata.h"

Word currentWord;
boolean EndWord;

void IgnoreBlanks() {
    while((currentChar==BLANK) && (currentChar!=MARK)) {
        ADV();
    }
}

void STARTWORD(char* fileaddress) {
    START(fileaddress);
    IgnoreBlanks();
    if(currentChar==MARK) EndWord=true;
    else {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if(currentChar == EOL)
        ADV();
    if(currentChar == MARK)
        EndWord = true;
    else {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    int i = 0;
    while(currentChar!=BLANK && currentChar!=MARK && currentChar!=EOL) {
        if(i<NMax) {
            currentWord.TabWord[i] = currentChar;
            i++;     
        }
        ADV();
    }
    currentWord.Length = i;
}

boolean isEndWord() {
    return EndWord;
}