#include "currentlagu.h"

void printInfoLagu(currentLagu L) {
    printWord(L.Penyanyi); printf(" - ");
    printWord(L.Lagu); printf(" - ");
    printWord(L.Album);
}