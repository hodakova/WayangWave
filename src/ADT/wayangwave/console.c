#include "console.h"

void StartWW(List *Penyanyi) {
    int i, j, k, N, M, L;
    STARTWORDFILE("../save/config.txt");

    N = Word2int(currentWord);//printWord(currentWord); printf("\n");
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
}

void LoadWW(char* dirfile, List *Penyanyi, currentLagu *LaguNow, Queue *QueueLagu, Stack *History, ArrayDin *Playlist){
    int i, j, k, N, M, L;
    STARTWORDFILE(dirfile);

    N = Word2int(currentWord);//printWord(currentWord); printf("\n");
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
    currentWordTillSC();
    (*LaguNow).Penyanyi = currentWord;
    ADVWORD();
    currentWordTillSC();
    (*LaguNow).Album = currentWord;
    ADVWORD();
    currentWordTillEOL();
    (*LaguNow).Lagu = currentWord;
    ADVBARIS();

    // Queue

    int A;
    A = Word2int(currentWord);
    ADVBARIS;
    for (int i = 0; i < A; i++){
        currentLagu tmp;
        currentWordTillSC();
        tmp.Penyanyi = currentWord;
        ADVWORD();
        currentWordTillSC();
        tmp.Album = currentWord;
        ADVWORD();
        currentWordTillEOL();
        tmp.Lagu = currentWord;

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

    *History = ReverseStack(*History);

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

void ListDefaultWW(List Penyanyi)
{
    printf("\n");
    printf("Daftar Penyanyi:\n");
    int x = ListLength(Penyanyi);
    for (int i = 0; i < x; i++)
    {
        printf("   %d. ", i+1);
        printWord((Penyanyi).A[i].NamaPenyanyi);
        printf("\n");
    }
    printf("\n");
    printf("Ingin melihat album yang ada? (Y/N): ");
    STARTWORD();
    printf("\n");
    if(isWordEqual(currentWord, str2Word("Y")))
    {
        printf("Pilih penyanyi untuk melihat album mereka:");
        STARTWORD();
        currentWordTillSC();
        int j = 0;
        boolean found = false;
        while(j < x && !found)
        {
            if (isWordEqual(currentWord, (Penyanyi).A[j].NamaPenyanyi))
            {
                found = true;
            }
            j++;
        }
        if (found)
        {
            int jumlah_album = (Penyanyi).A[j].Album.Count;
            for (int k = 0; k<jumlah_album;k++)
            {
                printf("   %d. ", k+1);
                printWord((Penyanyi).A[j].Album.Elements[j].Value.NamaAlbum);
                printf("\n");
            }
            printf("\n");
            printf("Ingin melihat lagu yang ada? (Y/N): ");
            STARTWORD();
            printf("\n");
            if (isWordEqual(currentWord, str2Word("Y")))
            {
                printf("Pilih album untuk melihat lagu yang ada di album :");
                STARTWORD();
                currentWordTillSC();
                found = false;
                int a = 0;
                while (a < jumlah_album && !found)
                {
                    if (isWordEqual(currentWord, (Penyanyi).A[j].Album.Elements[a].Value.NamaAlbum))
                    {
                        found = true;
                    }
                    j++;
                }
                if (found)
                {
                    int jumlah_lagu = (Penyanyi).A[j].Album.Elements[a].Value.Lagu.Count;
                    print("\n");
                    printf("Daftar Lagu di ");
                    printWord(currentWord);
                    print(":\n");
                    for (int b = 0; b<jumlah_album;b++)
                    {
                        printf("   %d. ", b+1);
                        printWord((Penyanyi).A[j].Album.Elements[a].Value.Lagu.Elements[b]);
                        printf("\n");
                    }
                } 
            }
        }
    }
}


