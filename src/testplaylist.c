#include <stdio.h>
#include <stdlib.h>
#include "ADT/mesinkata/mesinkata.h"
#include "playlist.c"
#include "ADT/list/arraydin.h"
#include "ADT/listlinier/listlinier.h"

int main() {
    ArrayDin playlist = MakeArrayDin();
    playlist_create(&playlist);
}