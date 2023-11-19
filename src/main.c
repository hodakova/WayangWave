#include "ADT/mesinkar/mesinkarakterv2.c"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/mesinbaris/mesinbaris.c"
#include "ADT/list/arraydin.c"
#include "ADT/list/list.c"
#include "ADT/stack/stack.c"
#include "ADT/queue/queue.c"
#include "ADT/set/set.c"
#include "ADT/map/map.c"
#include "ADT/wayangwave/console.c"
#include "ADT/listlinier/listlinier.h"
#include "ADT/currentlagu/currentlagu.h"
#include <stdio.h>


int main() {
Word currentOp;
List Penyanyi;
Queue QueueLagu;
Stack History;
ListLinier Playlist;
currentLagu LaguNow;

    
    do{
        STARTWORD();
        currentOp = currentWord;
        if(isWordEqual(currentOp, str2Word("START"))) {
            StartWW(&Penyanyi);
            printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
            }
        else if(isWordEqual(currentOp, str2Word("LOAD"))){
            STARTWORD();
            char* dirfile;
            dirfile = ConcateChar("../save/", Word2str(currentWord));
            LoadWW();
        }
        else
            printf("o: bukan start\n");
    }
    while(!isWordEqual(currentOp, str2Word("exit")));

    return 0;
}