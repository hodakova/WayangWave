#include <stdio.h>
#include "mesinkata.h"

Word currentWord;
boolean EndWord;

void IgnoreBlanks() {
    while((currentChar==BLANK) && (currentChar!=MARK)) {
        ADV();
    }
}

void IgnoreCR() {
    while((currentChar==CR) && (currentChar!=MARK)) {
        ADV();
    }
}

void IgnoreEOL() {
    if((currentChar==EOL) && (currentChar!=MARK)) {
        ADV();
    }
}

void STARTWORD(char* fileaddress) {
    START(fileaddress);
    IgnoreBlanks();
    IgnoreCR();
    if(currentChar==MARK) EndWord=true;
    else {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    IgnoreCR();
    if(currentChar == MARK)
        EndWord = true;
    else {
        EndWord = false;
        CopyWord();
    }
}

void CopyWord() {
    int i = 0;
    while(currentChar!=BLANK && currentChar!=MARK && currentChar!=EOL && currentChar!=CR) {
        if(i < WordNMax) {
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

boolean isWordEqual(Word K1, Word K2) {
    if(K1.Length == K2.Length) {
        for(int i = 0; i < K1.Length; i ++) {
            if(K1.TabWord[i] != K2.TabWord[i]) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

void printWord(Word Kata) {
    for(int i = 0; i < Kata.Length; i ++)
        printf("%c", Kata.TabWord[i]);
}

int Word2int(Word Kata) {
    int r = 0, i = Kata.Length, pengali = 1;
    while(i--) {
        r += (Kata.TabWord[i] - '0') * pengali;
        pengali *= 10;
    }
    return r;
}

Word int2Word(int Angka);

Word str2Word(char* String);