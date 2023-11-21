#include "ADT/mesinkar/mesinkarakterv2.c"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/mesinbaris/mesinbaris.c"
#include "ADT/list/arraydin.c"
#include "ADT/list/list.c"
#include "ADT/stack/stack.c"
#include "ADT/queue/queue.c"
#include "ADT/set/set.c"
#include "ADT/map/map.c"
#include "ADT/listlinier/listlinier.c"
#include "ADT/currentlagu/currentlagu.c"
#include "console.c"
#include "art.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // currentLagu l1, l2;
    // l1.Album = str2Word("album biru");
    // l1.Lagu = str2Word("bleu");
    // l1.Penyanyi = str2Word("asep sadboy");


    // printf("%d\n", l2.fromPlaylist.Length);
    
    // l2.fromPlaylist = str2Word("chills");
    // printf("%d\n", l2.fromPlaylist.Length);
    // l2 = l1;
    // printf("%d\n", l2.fromPlaylist.Length);

    // if(l2.fromPlaylist.Length != 0)
    //     printf("oke\n");
    ListLinier list;
    CreateListLinier(&list);
    currentLagu h;
    h.Album = str2Word("A");
    h.Penyanyi = str2Word("P");
    h.Lagu = str2Word("L");
    ListLinierInsVLast(&list, h);
    ListLinierPrintInfo(list);
    return 0;
}