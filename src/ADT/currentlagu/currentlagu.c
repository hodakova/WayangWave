#include "currentlagu.h"

void CreateInfoLagu(currentLagu *L) {
    L->Penyanyi = str2Word("-");
    L->Lagu = str2Word("-");
    L->Album = str2Word("-");
}

boolean isInfoLaguEmpty(currentLagu L) {
    return isWordEqual(L.Penyanyi, str2Word("-")) && isWordEqual(L.Lagu, str2Word("-")) && isWordEqual(L.Album, str2Word("-"));
}

void printInfoLagu(currentLagu L) {
    printWord(L.Penyanyi); printf(" - ");
    printWord(L.Lagu); printf(" - ");
    printWord(L.Album);
}