#include "currentlagu.h"

void CreateInfoLagu(currentLagu *L) {
    L->Penyanyi = str2Word("-");
    L->Lagu = str2Word("-");
    L->Album = str2Word("-");
    L->fromPlaylist = str2Word("-");
}

boolean isInfoLaguEmpty(currentLagu L) {
    return isWordEqual(L.Lagu, str2Word("-"));
}

boolean isInfoLaguEqual(currentLagu L1, currentLagu L2) {
    return isWordEqual(L1.Penyanyi, L2.Penyanyi) && isWordEqual(L1.Lagu, L2.Lagu) && isWordEqual(L1.Album, L2.Album);
}

void printInfoLagu(currentLagu L) {
    printWord(L.Penyanyi); printf(" - ");
    printWord(L.Lagu); printf(" - ");
    printWord(L.Album);
}