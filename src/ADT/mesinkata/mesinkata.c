#include <stdio.h>
#include "mesinkata.h"

Word currentWord;
boolean EndWord;

void IgnoreBlanks() {
    while((currentChar==BLANK) && (currentChar!=MARK)) {
        ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if(currentChar==MARK) EndWord=true;
    else {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if(currentChar == MARK) EndWord = true;
    else {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    int i = 0;
    while((currentChar!=BLANK) && (currentChar!=MARK)) {
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