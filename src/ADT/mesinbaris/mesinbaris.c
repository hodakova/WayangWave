#include "mesinbaris.h"

void ADVBARIS() {
    while(currentChar != EOL)
        ADV();
    IgnoreEOL();
    ADVWORD();
}

void currentWordTillEOL() {
    int foundCommentMark = 0;
    int i = currentWord.Length;
    if(i > 0 && currentChar != EOL && currentChar != CR) {    
        currentWord.TabWord[i] = BLANK;
        foundCommentMark ++;
        ADV();
        i ++;
    }
    while(currentChar != EOL && currentChar != CR && foundCommentMark < 3) {
        if(foundCommentMark == 0 && currentChar == BLANK)
            foundCommentMark ++;
        else if(foundCommentMark == 1 && currentChar == COMMENT)
            foundCommentMark ++;
        else if(foundCommentMark == 2 && currentChar == BLANK)
            foundCommentMark ++;
        else
            foundCommentMark = 0;

        currentWord.TabWord[i] = currentChar;
        ADV();
        i ++;
    }
    if(foundCommentMark == 3)
        i -= 3;
    currentWord.Length = i;
}