#include <stdio.h>
#include "mesinkata.h"

Word currentWord;
boolean EndWord;
boolean isSC;

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

void IgnoreSC() {
    if((currentChar==SC) && (currentChar!=MARK)) {
        isSC = true;
        ADV();
    }
    else
        isSC = false;
}

void STARTWORDFILE(char* fileaddress) {
    STARTFILE(fileaddress);
    IgnoreBlanks();
    IgnoreCR();
    if(EOP)
        EndWord=true;
    else {
        EndWord = false;
        ADVWORD();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    IgnoreCR();
    if(EOP)
        EndWord=true;
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
    while(currentChar!=BLANK && currentChar!=MARK && currentChar!=EOL && currentChar!=CR && currentChar != SC) {
        if(i < WordNMax) {
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    currentWord.Length = i;
    IgnoreSC();
}

void currentWordTillSC() {
    if(!isSC) {
        int i = currentWord.Length;
        if(i > 0 && currentChar != SC && currentChar != CR && currentChar != EOL) {    
            currentWord.TabWord[i] = BLANK;
            ADV();
            i ++;
        }

        while(currentChar != SC && currentChar != CR && currentChar != EOL) {
            currentWord.TabWord[i] = currentChar;
            ADV();
            i ++;
        }

        currentWord.Length = i;
        IgnoreSC();
    }
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
    else
        return false;
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

Word int2Word(int Angka) {
    Word Kata;

    char tmpc;
    int tmp = Angka, l = 0, i;

    while(tmp > 0) {
        l ++;
        tmp /= 10;
        }

    tmp = Angka;
    for(i = l - 1; i >= 0; i --) {
        Kata.TabWord[i] = '0' + tmp % 10;
        tmp /= 10;
    }
    
    Kata.Length = l;

    return Kata;
}

Word str2Word(char* String){
    Word kata;
    int i = 0;
    while(String[i] != '\0') {
        kata.TabWord[i] = String[i];
        i++;
    }
    kata.Length = i;
    return kata;
}

char* Word2str(Word Kata) {
    int i, l = Kata.Length;
    char* str = malloc(Kata.Length * sizeof(char));

    for(i = 0; i < l; i ++)
        str[i] = Kata.TabWord[i];
    
    str[l] = '\0';
    return str;
}

Word ConcatWord(Word K1, Word K2)
{
    Word K3 = K1;
	int i, j = 0;
	int l = K1.Length + K2.Length;
	for (i = K1.Length; i < l; i++) {
		K3.TabWord[i] = K2.TabWord[j];
		K3.Length++;
		j++;
	}
	return K3;
}