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
    art_WayangWave5();
    printf("Selamat datang di aplikasi WayangWave, sebuah aplikasi yang bisa mensimulasikan service pemutaran musik.\n");
    printf("Ketik START untuk memulai WayangWave, atau ketik LOAD apabila sudah memiliki savefile.\n");

    List Penyanyi;
    Queue QueueLagu; CreateQueue(&QueueLagu);
    Stack History; CreateStack(&History);
    ArrayDin Playlist = MakeArrayDin();
    currentLagu LaguNow;

    int x, y, id, n;
    char* dirfile;
    boolean masukSesi = false, valid;


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
                    SongWW_Next(&History, &LaguNow, &QueueLagu);
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
                    if (isWordEqual(currentWord, str2Word("config.txt")))
                        printf("\nNama save file tidak bisa \"config.txt\".\n");
                    else if(n > 4) {
                        if(currentWord.TabWord[n-2]=='.' && currentWord.TabWord[n-3]=='t' && currentWord.TabWord[n-2]=='x' && currentWord.TabWord[n-1]=='t') {
                            valid = true;
                        }
                    }
                    if(!valid) {
                        printf("Silakan input nama save file : "); STARTWORD();
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
