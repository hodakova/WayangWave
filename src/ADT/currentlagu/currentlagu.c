#include "currentlagu.h"

void printInfoLagu(currentLagu L) {
    printWord(L.Lagu); printf(";");
    printWord(L.Album); printf(";");
    printWord(L.Penyanyi);
}