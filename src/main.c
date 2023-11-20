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
#include "ADT/currentlagu/currentlagu.h"
#include "console.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Mulai Program\n");

    List Penyanyi;
    Queue QueueLagu; CreateQueue(&QueueLagu);
    Stack History; CreateStack(&History);
    ArrayDin Playlist = MakeArrayDin();
    currentLagu LaguNow;
    
    boolean masukSesi = false;

    while(!masukSesi) {
        printf(">> "); STARTWORD();

        if(isWordEqual(currentWord, str2Word("START"))) {
            StartWW(&Penyanyi);
            printf("\nFile konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
            masukSesi = true;
        }

        else if(isWordEqual(currentWord, str2Word("LOAD"))) {
            ADVWORD();
            char* dirfile;
            dirfile = Word2str(ConcatWord(str2Word("../save/"), currentWord));
            if (isFileExist(dirfile)) { 
                LoadWW(dirfile, &Penyanyi, &LaguNow, &QueueLagu, &History, &Playlist);
                printf("\nSave file berhasil dibaca. WayangWave berhasil dijalankan.\n");
                masukSesi = true;
            }
            else
                printf("\nSave file tidak ditemukan. WayangWave gagal dijalankan.\n");
        }

        else if(isWordEqual(currentWord, str2Word("HELP")))
            HelpWW_before();

        else
            Command_unknown();
    }
    

    while(true) {
        printf(">> "); STARTWORD();

        if(isWordEqual(currentWord, str2Word("LIST"))) {
            ADVWORD();

            if(isWordEqual(currentWord, str2Word("DEFAULT")))
                ListWW_Default(Penyanyi);

            else if(isWordEqual(currentWord, str2Word("PLAYLIST")))
                ListWW_Playlist(Playlist);
        }

        else
            Command_unknown();
    }

    return 0;
}