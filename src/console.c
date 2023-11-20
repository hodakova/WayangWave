#include "console.h"

void Command_unknown() {
    printf("\nCommand tidak diketahui!\n");
}

void Command_forbidden() {
    printf("\nCommand tidak bisa dieksekusi!\n");
}

void StartWW(List *Penyanyi) {
    int i, j, k, N, M, L;
    STARTWORDFILE("../save/config.txt");

    N = Word2int(currentWord);//printWord(currentWord); printf("\n");
    ADVBARIS();// ^^ Jumlah Penyanyi ^^

    for (i = 0; i < N; i++){
        M = Word2int(currentWord);//printWord(currentWord); printf("\n");
        (*Penyanyi).A[i].Album.Count = M;
        ADVWORD();// ^^ Jumlah Album ^^

        currentWordTillEOL();
        (*Penyanyi).A[i].NamaPenyanyi = currentWord;
        ADVBARIS();

        for (j = 0; j < M; j++) {
            L = Word2int(currentWord);
            ADVWORD();// ^^ Jumlah Lagu

            currentWordTillEOL();
            (*Penyanyi).A[i].Album.Elements[j].Key = i;
            (*Penyanyi).A[i].Album.Elements[j].Value.NamaAlbum = currentWord;
            ADVBARIS();
            for(k = 0; k < L; k ++) {
                currentWordTillEOL();
                SetInsert(&((*Penyanyi).A[i].Album.Elements[j].Value.Lagu), currentWord);
                ADVBARIS();
            }
        }
    }
}

void LoadWW(char* dirfile, List *Penyanyi, currentLagu *LaguNow, Queue *QueueLagu, Stack *History, ArrayDin *Playlist){
    int i, j, k, N, M, L;
    STARTWORDFILE(dirfile);

    N = Word2int(currentWord); //printWord(currentWord); printf("\n");
    ADVBARIS();// ^^ Jumlah Penyanyi ^^

    for (i = 0; i < N; i++){
        M = Word2int(currentWord);//printWord(currentWord); printf("\n");
        ADVWORD();// ^^ Jumlah Penyanyi ^^

        currentWordTillEOL();
        (*Penyanyi).A[i].NamaPenyanyi = currentWord;
        ADVBARIS();

        for (j = 0; j < M; j++){
            L = Word2int(currentWord);
            ADVWORD();

            currentWordTillEOL();
            (*Penyanyi).A[i].Album.Elements[j].Key = i;
            (*Penyanyi).A[i].Album.Elements[j].Value.NamaAlbum = currentWord;
            ADVBARIS();

            for(k = 0; k < L; k ++) {
                currentWordTillEOL();
                SetInsert(&((*Penyanyi).A[i].Album.Elements[j].Value.Lagu), currentWord);
                ADVBARIS();
            }
        }
    }
    // Current Song

    currentWordTillSC();
    (*LaguNow).Penyanyi = currentWord; //printWord(LaguNow->Penyanyi); printf("\n");
    ADVWORD();
    currentWordTillSC();
    (*LaguNow).Album = currentWord;// printWord(currentWord); printf("\n");
    ADVWORD();
    currentWordTillEOL();
    (*LaguNow).Lagu = currentWord;// printWord(currentWord); printf("\n");
    ADVBARIS();

    // Queue

    int A;
    A = Word2int(currentWord);//printWord(currentWord); printf("\n");
    ADVBARIS();
    for (int i = 0; i < A; i++){
        currentLagu tmp;
        currentWordTillSC();
        tmp.Penyanyi = currentWord; //printWord(currentWord); printf(";");
        ADVWORD();
        currentWordTillSC();
        tmp.Album = currentWord; //printWord(currentWord); printf(";");
        ADVWORD();
        currentWordTillEOL();
        tmp.Lagu = currentWord; //printWord(currentWord); printf("\n");

        enqueue(QueueLagu, tmp);

        ADVBARIS();
    }

    // History
    int B;
    B = Word2int(currentWord); 
    ADVBARIS();
    for (int i = 0; i < B; i++) {
        currentLagu tmp;
        currentWordTillSC();
        tmp.Penyanyi = currentWord;
        ADVWORD();
        currentWordTillSC();
        tmp.Album = currentWord;
        ADVWORD();
        currentWordTillEOL();
        tmp.Lagu = currentWord;

        Push(History, tmp);
        ADVBARIS();
    }

    // Playlist
    int C,D;
    C = Word2int(currentWord);
    ADVBARIS();
    for (int i = 0; i < C; i++) {
        D = Word2int(currentWord);
        ADVWORD();
        ArrayDinElType arraytmp;
        currentWordTillEOL();
        arraytmp.NamaPlaylist = currentWord;
        ADVBARIS();
        CreateListLinier(&((*Playlist).A[i].DaftarLagu));
        for (int j = 0; j < D; j++){
            currentLagu tmp;
            currentWordTillSC();
            tmp.Penyanyi = currentWord;
            ADVWORD();
            currentWordTillSC();
            tmp.Album = currentWord;
            ADVWORD();
            currentWordTillEOL();
            tmp.Lagu = currentWord;
            
            ListLinierInsVLast(&arraytmp.DaftarLagu, tmp);
            ADVBARIS();
        }
        ArrayDinInsertLast(Playlist, arraytmp);
    }
}

void ListWW_Default(List Penyanyi) {
    printf("\n");
    printf("Daftar Penyanyi :\n");

    int x = ListLength(Penyanyi);
    for (int i = 0; i < x; i++) {
        printf("   %d. ", i+1); printWord((Penyanyi).A[i].NamaPenyanyi); printf("\n");
    }

    boolean lanjut = false;
    while(!lanjut) {
        printf("\n");
        printf("Ingin melihat album yang ada? (Y/N) : "); STARTWORD(); currentWordTillSC();

        if(isWordEqual(currentWord, str2Word("Y"))) {
            lanjut = true;

            boolean found = false; int j;
            while(!found) {

                printf("Pilih penyanyi untuk melihat album mereka : "); STARTWORD(); currentWordTillSC();

                j = 0;
                while(j < x && !found) {
                    if (isWordEqual(currentWord, (Penyanyi).A[j].NamaPenyanyi))
                        found = true;
                    else
                        j++;
                }

                if(!found)
                    Command_unknown();
            }
        
            printf("\n");
            printf("Daftar Album oleh "); printWord(currentWord); printf(" :\n");
            int jumlah_album = (Penyanyi).A[j].Album.Count;
            for (int k = 0; k < jumlah_album; k++) {
                printf("   %d. ", k+1); printWord((Penyanyi).A[j].Album.Elements[k].Value.NamaAlbum); printf("\n");
            }

            boolean lanjut2 = false;
            while(!lanjut2) {

                printf("\n");
                printf("Ingin melihat lagu yang ada? (Y/N) : "); STARTWORD(); currentWordTillSC();

                if (isWordEqual(currentWord, str2Word("Y"))) {
                    lanjut2 = true;

                    found = false; int a;
                    while(!found) {
                        printf("\n");
                        printf("Pilih album untuk melihat lagu yang ada di album : "); STARTWORD(); currentWordTillSC();
                        
                        a = 0;
                        while(a < jumlah_album && !found) {
                            if (isWordEqual(currentWord, (Penyanyi).A[j].Album.Elements[a].Value.NamaAlbum))
                                found = true;
                            else
                                a++;
                        }
                    }
                    
                    printf("\n");
                    printf("Daftar Lagu di "); printWord(currentWord); printf(":\n");

                    int jumlah_lagu = (Penyanyi).A[j].Album.Elements[a].Value.Lagu.Count;
                    for (int b = 0; b < jumlah_lagu;b++) {
                        printf("   %d. ", b+1); printWord((Penyanyi).A[j].Album.Elements[a].Value.Lagu.Elements[b]); printf("\n");
                    }
                }

                else if(isWordEqual(currentWord, str2Word("N")))
                    lanjut2 = true;
                
                else
                    Command_unknown();
            }
        }
    
        else if(isWordEqual(currentWord, str2Word("N")))
            lanjut = true;
        
        else
            Command_unknown();
    }
}

void ListWW_Playlist(ArrayDin Playlist) {
    printf("\n");
    printf("Daftar playlist yang kamu miliki:\n");

}

void PlayWW_Song(List Penyanyi, Queue *QueueLagu, Stack *History, currentLagu *LaguNow) {}

void PlayWW_Playlist(ArrayDin Playlist, Queue *QueueLagu, Stack *History, currentLagu *LaguNow) {}

void QueueWW_Song() {}

void QueueWW_Playlist() {}

void QueueWW_Swap() {}

void QueueWW_Remove() {}

void QueueWW_Clear() {}

void SongWW_Next() {}

void SongWW_Previous() {}

void PlaylistWW_Create() {}

void PlaylistWW_Add_Song() {}

void PlaylistWW_Add_Album() {}

void PlaylistWW_Swap() {}

void PlaylistWW_Remove() {}

void PlaylistWW_Delete() {}

void StatusWW() {}

void SaveWW() {}

void QuitWW() {}

void HelpWW_before() {}

void HelpWW_after() {}
