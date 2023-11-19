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
#include "ADT/listlinier/listlinier.c"
#include "ADT/currentlagu/currentlagu.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Mulai Program\n");
    Word currentOp;
    List Penyanyi;
    Queue QueueLagu;
    CreateQueue(&QueueLagu);
    Stack History;
    CreateStack(&History);
    ArrayDin Playlist;
    Playlist = MakeArrayDin();
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
            dirfile = Word2str(ConcatWord(str2Word("../save/"), currentWord));

            if (isFileExist(dirfile)){ 
                printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.");
                LoadWW(dirfile, &Penyanyi, &LaguNow, &QueueLagu, &History, &Playlist);
            }
            else
                printf("Save file tidak ditemukan. WayangWave gagal dijalankan.");

        }
        else
            printf("o: bukan start\n");
    }
    while(!isWordEqual(currentOp, str2Word("exit")));

    return 0;
}