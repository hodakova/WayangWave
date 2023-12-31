#include "ADT/mesinkar/mesinkarakterv2.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mesinbaris/mesinbaris.h"
#include "ADT/list/arraydin.h"
#include "ADT/list/list.h"
#include "ADT/stack/stack.h"
#include "ADT/queue/queue.h"
#include "ADT/set/set.h"
#include "ADT/map/map.h"
#include "ADT/listlinier/listlinier.h"
#include "ADT/currentlagu/currentlagu.h"
#include "console.h"
#include "art.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y, id, n;
    char* dirfile;
    boolean masukSesi = false, isSaved = false, valid;
    srand(time(NULL)); // inisialisasi seed untuk random

    n = random_number(0, 5); // sengaja biar chanse dapat art_WayangWave5() lebih tinggi ^_^
    switch (n) {
    case 1:
        art_WayangWave1();
        break;
    case 2:
        art_WayangWave2();
        break;
    case 3:
        art_WayangWave3();
        break;
    case 4:
        art_WayangWave4();
        break;
    default:
        art_WayangWave5();
        break;
    }

    printf("Selamat datang di aplikasi WayangWave, sebuah aplikasi yang bisa mensimulasikan service pemutaran musik.\n");
    printf("Ketik HELP untuk menunjukkan Menu Help WayangWave\n");

    List Penyanyi = MakeList();
    Queue QueueLagu; CreateQueue(&QueueLagu);
    Stack History; CreateStack(&History);
    ArrayDin Playlist = MakeArrayDin();
    currentLagu LaguNow; CreateInfoLagu(&LaguNow);

    while(true) {
        printf(">> "); STARTWORD();

        if(isWordEqual(currentWord, str2Word("START"))) {
            if(!masukSesi) {
                StartWW(&Penyanyi);
                printf("\nFile konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
                masukSesi = true;
            }
            else
                Command_forbidden();
        }

        else if(isWordEqual(currentWord, str2Word("LOAD"))) {
            ADVWORD();

            if(!masukSesi) {
                dirfile = Word2str(ConcatWord(str2Word("../save/"), currentWord));
                if (isFileExist(dirfile)) { 
                    LoadWW(dirfile, &Penyanyi, &LaguNow, &QueueLagu, &History, &Playlist);
                    printf("\nSave file berhasil dibaca. WayangWave berhasil dijalankan.\n");
                    masukSesi = true;
                }
                else
                    printf("\nSave file tidak ditemukan. WayangWave gagal dijalankan.\n");
            }
            else
                Command_forbidden();
        }

        else if(isWordEqual(currentWord, str2Word("LIST"))) {
            ADVWORD();

            if(isWordEqual(currentWord, str2Word("DEFAULT"))) {
                if(masukSesi)
                    ListWW_Default(Penyanyi);
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("PLAYLIST"))) {
                if(masukSesi)
                    ListWW_Playlist(Playlist);
                else
                    Command_forbidden();
            }
            
            else
                Command_unknown();
        }
        
        else if(isWordEqual(currentWord, str2Word("PLAY"))) {
            ADVWORD();

            if(isWordEqual(currentWord, str2Word("SONG"))) {
                if(masukSesi)
                    PlayWW_Song(Penyanyi, &QueueLagu, &History, &LaguNow);
                else
                    Command_forbidden();
            }
            
            else if(isWordEqual(currentWord, str2Word("PLAYLIST"))) {
                if(masukSesi)
                    PlayWW_Playlist(Playlist, &QueueLagu, &History, &LaguNow);
                else
                    Command_forbidden();
            }

            else
                Command_unknown();
        }

        else if(isWordEqual(currentWord, str2Word("QUEUE"))) {
            // printQueue(QueueLagu);
            ADVWORD();

            if(isWordEqual(currentWord, str2Word("SONG"))) {
                if(masukSesi)
                    QueueWW_Song(Penyanyi, &QueueLagu);
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("PLAYLIST"))) {
                if(masukSesi)
                    QueueWW_Playlist(Playlist, &QueueLagu);
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("SWAP"))) {
                ADVWORD();
                x = Word2int(currentWord);
                ADVWORD();
                y = Word2int(currentWord);
                if(masukSesi)
                    QueueWW_Swap(&QueueLagu, x, y);
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("REMOVE"))) {
                ADVWORD();
                id = Word2int(currentWord);
                if(masukSesi)
                    QueueWW_Remove(&QueueLagu, id);
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("CLEAR"))) {
                if(masukSesi)
                    QueueWW_Clear(&QueueLagu);
                else
                    Command_forbidden();
            }
                
            else
                Command_unknown();

            // printQueue(QueueLagu);  
        }

        else if(isWordEqual(currentWord, str2Word("SONG"))) {
            ADVWORD();

            if(isWordEqual(currentWord, str2Word("NEXT"))) {
                if(masukSesi)
                    SongWW_Next(&History, &LaguNow, &QueueLagu);
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("PREVIOUS"))) {
                if(masukSesi)
                    SongWW_Previous(&History, &LaguNow, &QueueLagu);
                else
                    Command_forbidden();
            }
            
            else
                Command_unknown();
        }

        else if(isWordEqual(currentWord, str2Word("PLAYLIST"))) {
            ADVWORD();

            if(isWordEqual(currentWord, str2Word("CREATE"))) {
                if(masukSesi)
                    PlaylistWW_Create(&Playlist);
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("ADD"))) {
                ADVWORD();

                if(isWordEqual(currentWord, str2Word("SONG"))) {
                    if(masukSesi)
                        PlaylistWW_Add_Song(Penyanyi, &Playlist);
                    else
                        Command_forbidden();
                }
                
                else if(isWordEqual(currentWord, str2Word("ALBUM"))) {
                    if(masukSesi)
                        PlaylistWW_Add_Album(Penyanyi, &Playlist);
                    else
                        Command_forbidden();
                }

                else
                    Command_unknown();
            }

            else if(isWordEqual(currentWord, str2Word("SWAP"))) {
                ADVWORD();
                id = Word2int(currentWord);
                ADVWORD();
                x = Word2int(currentWord);
                ADVWORD();
                y = Word2int(currentWord);
                if(masukSesi)
                    PlaylistWW_Swap(&Playlist, id, x, y);
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("REMOVE"))) {
                ADVWORD();
                id = Word2int(currentWord);
                ADVWORD();
                n = Word2int(currentWord);
                if(masukSesi)
                    PlaylistWW_Remove(&Playlist, id, n);
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("DELETE"))) {
                if(masukSesi)
                    PlaylistWW_Delete(&Playlist);
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("ENHANCE"))) {
                if(masukSesi)
                    PlaylistWW_Enhance(&Playlist, Penyanyi);
                else
                    Command_forbidden();
            }

            else
                Command_unknown();
        }

        else if(isWordEqual(currentWord, str2Word("STATUS"))) {
            if(masukSesi)
                StatusWW(LaguNow, QueueLagu);
            else
                Command_unknown();
        }

        else if(isWordEqual(currentWord, str2Word("SAVE"))) {
            ADVWORD();

            if(masukSesi) {
                valid = false;
                while(!valid) {
                    n = currentWord.Length;
                    if(n > 4 && !isWordEqual(currentWord, str2Word("config.txt"))) {
                        if(currentWord.TabWord[n-4]=='.' && currentWord.TabWord[n-3]=='t' && currentWord.TabWord[n-2]=='x' && currentWord.TabWord[n-1]=='t') {
                            valid = true;
                        }
                    }
                    if(!valid) {
                        printf("\nNama file tidak valid, ");
                        if (isWordEqual(currentWord, str2Word("config.txt")))
                            printf("Nama save file tidak bisa \"config.txt\".");
                        else
                            printf("gunakan format \"<namafile>.txt\".");
                        printf(" Silakan input nama save file : "); STARTWORD();
                    }
                }
                dirfile = Word2str(ConcatWord(str2Word("../save/"), currentWord));
                if (isFileExist(dirfile)) { 
                    SaveWW(dirfile, Penyanyi, LaguNow, QueueLagu, History, Playlist);
                    printf("\nSave file berhasil disimpan.\n");
                }
                else{
                    printf("\nFile tidak ditemukan, apakah ingin membuat file baru dengan nama %s? (Y/N) : ", Word2str(currentWord)); STARTWORD();
                    while (!(isWordEqual(currentWord, str2Word("Y")) || (isWordEqual(currentWord, str2Word("N"))))){ 
                        printf("\nSilahkan input (Y) untuk membuat file baru dan (N) untuk membatalkan save. (Y/N) : "); STARTWORD();
                    }
                    if ((isWordEqual(str2Word("Y"), currentWord))){
                        SaveWW(dirfile, Penyanyi, LaguNow, QueueLagu, History, Playlist);
                        printf("\nSave file berhasil disimpan.\n");
                    }
                    else{
                        printf("\nSave file gagal disimpan.\n");
                    }
                }
            }
            else
                Command_forbidden();
        }

        else if(isWordEqual(currentWord, str2Word("QUIT"))) {
            if(masukSesi)
                QuitWW(Penyanyi,LaguNow,QueueLagu,History,Playlist);
            else
                Command_forbidden();
        }

        else if(isWordEqual(currentWord, str2Word("HELP"))) {
            if(masukSesi)
                HelpWW_after();
            else
                HelpWW_before();
        }

        else
            Command_unknown();
    }

    return 0;
}
