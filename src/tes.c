#include <stdio.h>
#include <stdlib.h>
#include "ADT/mesinkata/mesinkata.h"
#include "playlist.c"
#include "ADT/list/arraydin.c"
#include "ADT/listlinier/listlinier.c"

int main() {
    ArrayDin playlist = MakeArrayDin();
    playlist_create(&playlist);
}