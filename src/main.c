#include "ADT/mesinkar/mesinkarakterv2.c"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/mesinbaris/mesinbaris.c"
#include "ADT/list/arraydin.c"
#include "ADT/list/list.c"
#include "ADT/stack/stack.c"
#include "ADT/queue/queue.c"
#include "ADT/set/set.c"
#include "ADT/map/map.c"
<<<<<<< Updated upstream
#include "ADT/wayangwave/config.c"
#include "ADT/wayangwave/record.c"
#include "ADT/wayangwave/commands/start.c"
=======
#include "ADT/listlinier/listlinier.c"
#include "ADT/currentlagu/currentlagu.c"
#include "ADT/user/user.c"
#include "console.c"
#include "art.c"
>>>>>>> Stashed changes
#include <stdio.h>


int main() {
<<<<<<< Updated upstream
    StartWW();
=======
    art_WayangWave5();
    printf("Selamat datang di aplikasi WayangWave, sebuah aplikasi yang bisa mensimulasikan service pemutaran musik.\n");
    printf("Ketik START untuk memulai WayangWave, atau ketik LOAD apabila sudah memiliki savefile.\n");

    List Penyanyi = MakeList();
    // user U; CreateUser(&U);
    user U;
    int idxUser = -1;

    int x, y, id, n;
    char* dirfile;
    boolean masukSesi = false, valid;

    while(true) {
        printf(">> "); STARTWORD();

        if(isWordEqual(currentWord, str2Word("START"))) {
            if(!masukSesi) {
                StartWW(&Penyanyi, &U);
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
                    LoadWW(dirfile, &Penyanyi, &U);
                    printf("\nSave file berhasil dibaca. WayangWave berhasil dijalankan.\n");
                    masukSesi = true;
                }
                else
                    printf("\nSave file tidak ditemukan. WayangWave gagal dijalankan.\n");
            }
            else
                Command_forbidden();
        }
        else if(isWordEqual(currentWord, str2Word("LOGIN"))) {
            if(masukSesi) {
                Login(U, &idxUser);
            }
            else Command_forbidden();

        }
        else if(isWordEqual(currentWord, str2Word("LOGOUT"))) {
            if(masukSesi) {
                if (idxUser != -1){ 
                    printf("Sampai jumpa %s!\n", Word2str(U.Data[idxUser].Username));
                    Logout(&idxUser);
                }  
                else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
            }
            else Command_forbidden();

        }
        else if(isWordEqual(currentWord, str2Word("LIST"))) {
            ADVWORD();

            if(isWordEqual(currentWord, str2Word("DEFAULT"))) {
                if(masukSesi){
                    if (idxUser != -1){ 
                        ListWW_Default(Penyanyi);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("PLAYLIST"))) {
                if(masukSesi){
                    if (idxUser != -1){ 
                        ListWW_Playlist(U, idxUser);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }
            
            else
                Command_unknown();
        }
        
        else if(isWordEqual(currentWord, str2Word("PLAY"))) {
            ADVWORD();

            if(isWordEqual(currentWord, str2Word("SONG"))) {
                if(masukSesi){
                    if (idxUser != -1){ 
                        PlayWW_Song(Penyanyi, &U, idxUser);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }
            
            else if(isWordEqual(currentWord, str2Word("PLAYLIST"))) {
                if(masukSesi){
                    if (idxUser != -1){ 
                        PlayWW_Playlist(&U, idxUser);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
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
                if(masukSesi){
                    if (idxUser != -1){ 
                        QueueWW_Song(Penyanyi, &U, idxUser);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("PLAYLIST"))) {
                if(masukSesi){
                    if (idxUser != -1){ 
                        QueueWW_Playlist(&U, idxUser);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("SWAP"))) {
                ADVWORD();
                x = Word2int(currentWord);
                ADVWORD();
                y = Word2int(currentWord);
                if(masukSesi){
                    if (idxUser != -1){ 
                        QueueWW_Swap(&U, idxUser, x, y);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("REMOVE"))) {
                ADVWORD();
                id = Word2int(currentWord);
                if(masukSesi){
                    if (idxUser != -1){ 
                        QueueWW_Remove(&U, idxUser, id);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("CLEAR"))) {
                if(masukSesi){
                    if (idxUser != -1){ 
                        QueueWW_Clear(&U, idxUser);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
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
                if(masukSesi){
                    if (idxUser != -1){ 
                        SongWW_Next(&U, idxUser);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("PREVIOUS"))) {
                if(masukSesi){
                    if (idxUser != -1){ 
                        SongWW_Next(&U, idxUser);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }
            
            else
                Command_unknown();
        }

        else if(isWordEqual(currentWord, str2Word("PLAYLIST"))) {
            ADVWORD();

            if(isWordEqual(currentWord, str2Word("CREATE"))) {
                if(masukSesi){
                    if (idxUser != -1){ 
                        PlaylistWW_Create(&U, idxUser);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("ADD"))) {
                ADVWORD();

                if(isWordEqual(currentWord, str2Word("SONG"))) {
                    if(masukSesi){
                        if (idxUser != -1){ 
                        PlaylistWW_Add_Song(Penyanyi, &U, idxUser);
                        }  
                        else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                    }
                        
                    else
                        Command_forbidden();
                }
                
                else if(isWordEqual(currentWord, str2Word("ALBUM"))) {
                    if(masukSesi){
                        if (idxUser != -1){ 
                        PlaylistWW_Add_Album(Penyanyi, &U, idxUser);
                        }  
                        else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                    }
                        
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
                if(masukSesi){
                    if (idxUser != -1){ 
                        PlaylistWW_Swap(&U, idxUser, id, x, y);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                    
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("REMOVE"))) {
                ADVWORD();
                id = Word2int(currentWord);
                ADVWORD();
                n = Word2int(currentWord);
                if(masukSesi){
                    if (idxUser != -1){ 
                        PlaylistWW_Remove(&U, idxUser, id, n);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                else
                    Command_forbidden();
            }

            else if(isWordEqual(currentWord, str2Word("DELETE"))) {
                if(masukSesi){
                    if (idxUser != -1){ 
                        PlaylistWW_Delete(&U, idxUser);
                    }  
                    else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
                }
                else
                    Command_forbidden();
            }

            else
                Command_unknown();
        }

        else if(isWordEqual(currentWord, str2Word("STATUS"))) {
            if(masukSesi){
                if (idxUser != -1){ 
                    StatusWW(U, idxUser);
                }  
                else printf("Anda belum Login, silahkan login dengan command LOGIN\n");
            }

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
                    SaveWW(dirfile, Penyanyi, U);
                    printf("\nSave file berhasil disimpan.\n");
                }
                else{
                    printf("\nFile tidak ditemukan, apakah ingin membuat file baru dengan nama %s? (Y/N) : ", Word2str(currentWord)); STARTWORD();
                    while (!(isWordEqual(currentWord, str2Word("Y")) || (isWordEqual(currentWord, str2Word("N"))))){ 
                        printf("\nSilahkan input (Y) untuk membuat file baru dan (N) untuk membatalkan save. (Y/N) : "); STARTWORD();
                    }
                    if ((isWordEqual(str2Word("Y"), currentWord))){
                        SaveWW(dirfile, Penyanyi, U);
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
                QuitWW(Penyanyi, U);
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

>>>>>>> Stashed changes
    return 0;
}