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
    A = Word2int(currentWord); //printWord(currentWord); printf("\n");
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
            
            // ListLinierInsVLast(&arraytmp.DaftarLagu, tmp); // ini rusak
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

    printf("\n");
    boolean lanjut = false;
    while(!lanjut) {
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

            printf("\n");
            boolean lanjut2 = false;
            while(!lanjut2) {
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

void ListWW_Playlist(ArrayDin Playlist) 
{
    printf("\n");
    printf("Daftar playlist yang kamu miliki:\n");
    if (!IsArrayDinEmpty(Playlist))
    {
        int x = ArrayDinLength(Playlist);
        for (int i = 0; i < x; i++) 
        {
        printf("   %d. ", i+1); printWord((Playlist).A[i].NamaPlaylist); printf("\n");
        }
    }
    else
    {
        printf("Kamu tidak memiliki playlist.\n");
    }

}

void PlayWW_Song(List Penyanyi, Queue *QueueLagu, Stack *History, currentLagu *LaguNow) {}

void PlayWW_Playlist(ArrayDin Playlist, Queue *QueueLagu, Stack *History, currentLagu *LaguNow) {
    printf("\n");
    if(IsArrayDinEmpty(Playlist))
        printf("Kamu tidak memiliki playlist.\n");
    else {
        printf("Masukkan ID Playlist: "); STARTWORD(); currentWordTillSC();
        int id = Word2int(currentWord);

        printf("\n");
        if(id > 0 && id <= ArrayDinLength(Playlist)) {
            CreateQueue(QueueLagu);
            CreateStack(History);

            addressListLinier P = Playlist.A[id-1].DaftarLagu.ListLinierFirst;
            *LaguNow = ListLinierInfo(P);
            (*LaguNow).fromPlaylist = Playlist.A[id-1].NamaPlaylist;
            P = ListLinierNext(P);

            currentLagu Ltmp;
            while(P != ListLinierNil) {
                Ltmp = ListLinierInfo(P);
                Ltmp.fromPlaylist = Playlist.A[id-1].NamaPlaylist;
                enqueue(QueueLagu, Ltmp);
                Push(History, Ltmp);
                P = ListLinierNext(P);
            }
            *History = ReverseStack(*History);

            printf("Memutar playlist \""); printWord((*LaguNow).fromPlaylist); printf("\".\n");
        }

        else {
            printf("ID Playlist tidak valid! Tidak ada playlist dengan id = %d.\n", id);
            printf("Tips: Ketik LIST PLAYLIST untuk melihat ID Playlist!\n");
        }
    }
}

void QueueWW_Song(List Penyanyi, Queue *QueueLagu) {

    if(isQueueFull(*QueueLagu))
        printf("\nQueue penuh!\n");
    else {
        int i, j, k, n, m, l;
        boolean found;
        currentLagu Lagu;

        printf("\n");
        printf("Daftar Penyanyi :\n");
        n = ListLength(Penyanyi);
        for(i = 0; i < n; i ++) {
            printf("   %d. ", i + 1); printWord(Penyanyi.A[i].NamaPenyanyi); printf("\n");
        }
        
        printf("\n");
        found = false;
        while(!found) {
            printf("Masukkan Nama Penyanyi : "); STARTWORD(); currentWordTillSC();

            i = 0;
            while(i < n && !found) {
                if(isWordEqual(Penyanyi.A[i].NamaPenyanyi, currentWord)) {
                    found = true;
                    Lagu.Penyanyi = currentWord;
                }
                else
                    i ++;
            }

            if(!found)
                Command_unknown();
        }

        printf("\n");
        printf("Daftar Album oleh "); printWord(Lagu.Penyanyi); printf(" :\n");
        m = Penyanyi.A[i].Album.Count;
        for(j = 0; j < m; j ++) {
            printf("   %d. ", j + 1); printWord(Penyanyi.A[i].Album.Elements[j].Value.NamaAlbum); printf("\n");
        }


        printf("\n");
        found = false;
        while(!found) {
            printf("Masukkan Nama Album yang dipilih : "); STARTWORD(); currentWordTillSC();

            j = 0;
            while(j < m && !found) {
                if(isWordEqual(Penyanyi.A[i].Album.Elements[j].Value.NamaAlbum, currentWord)) {
                    found = true;
                    Lagu.Album = currentWord;
                }
                else
                    j ++;
            }

            if(!found)
                Command_unknown();
        }

        printf("\n");
        printf("Daftar Lagu Album "); printWord(Lagu.Album); printf(" oleh "); printWord(Lagu.Penyanyi); printf(" :\n");
        l = Penyanyi.A[i].Album.Elements[j].Value.Lagu.Count;
        for(k = 0; k < l; k ++) {
            printf("   %d. ", k + 1); printWord(Penyanyi.A[i].Album.Elements[j].Value.Lagu.Elements[k]); printf("\n");        
        }

        printf("\n");
        found = false;
        while(!found) {
            printf("Masukkan ID Lagu yang dipilih: "); STARTWORD(); currentWordTillSC();
            k = Word2int(currentWord) - 1;
            if(k >= 0 && k < l)
                found = true;

            if(!found)
                Command_unknown();
        }

        Lagu.Lagu = Penyanyi.A[i].Album.Elements[j].Value.Lagu.Elements[k];
        enqueue(QueueLagu, Lagu);
        
        printf("Berhasil menambahkan lagu \""); printWord(Lagu.Lagu); printf("\" oleh \""); printWord(Lagu.Penyanyi); printf("\" ke queue.\n");
    }
}

void QueueWW_Playlist(ArrayDin Playlist, Queue *QueueLagu) {
    if(isQueueFull(*QueueLagu))
        printf("\nQueue penuh!\n");
    else {
        int id, r, i;
        currentLagu Ltmp;
        addressListLinier P;
        boolean isFull = false;

        printf("\n");
        if(IsArrayDinEmpty(Playlist))
            printf("Kamu tidak memiliki playlist.\n");
        else {
            printf("Masukkan ID Playlist: "); STARTWORD(); currentWordTillSC();
            id = Word2int(currentWord) - 1;

            printf("\n");
            if(id >= 0 && id < ArrayDinLength(Playlist)) {
                P = Playlist.A[id].DaftarLagu.ListLinierFirst;
                while(P != ListLinierNil && !isFull) {
                    Ltmp = ListLinierInfo(P);
                    Ltmp.fromPlaylist = Playlist.A[id].NamaPlaylist; // penanda dari PlayList mana lagu yg sedang di-play
                    if(!isQueueFull(*QueueLagu))
                        enqueue(QueueLagu, Ltmp);
                    else
                        isFull = true;
                    P = ListLinierNext(P);
                }
                
                printf("Berhasil menambahkan playlist \""); printWord(Playlist.A[id].NamaPlaylist); printf(" ke queue.\n");
                if(isFull) {
                    printf("Karena Queue penuh, beberapa lagu mungkin tidak berhasil ditambahkan.\n");
                    printf("Tips: Ketik QUEUE CLEAR untuk mengosongkan Queue!\n");
                }
            }

            else {
                printf("ID Playlist tidak valid! Tidak ada playlist dengan id = %d.\n", id);
                printf("Tips: Ketik LIST PLAYLIST untuk melihat ID Playlist!\n");
            }
        }
    }
}

void QueueWW_Swap(Queue *QueueLagu, int x, int y) {
    boolean isXvalid = false, isYvalid = false;
    int l = QueueLength(*QueueLagu), iHead = QueueIdxHead(*QueueLagu);

    if(x > 0 && x <= l)
        isXvalid = true;
    if(y > 0 && y <= l)
        isYvalid = true;


    printf("\n");
    if(isXvalid && isYvalid) {
        currentLagu tmp = (*QueueLagu).buffer[y-1+iHead];
        (*QueueLagu).buffer[y-1+iHead] = (*QueueLagu).buffer[x-1+iHead];
        (*QueueLagu).buffer[x-1+iHead] = tmp;

        printf("Lagu \""); printWord((*QueueLagu).buffer[y-1+iHead].Lagu); printf("\" berhasil ditukar dengan \""); printWord(tmp.Lagu); printf("\"\n");
    }
    else {
        printf("Lagu dengan urutan ");
        if(!isXvalid)
            printf("ke %d", x);
        if(!isXvalid && !isYvalid)
            printf(" & ");
        if(!isYvalid)
            printf("ke %d", y);
        printf(" tidak terdapat dalam queue!\n");
    }
}

void QueueWW_Remove(Queue *QueueLagu, int id) {
    printf("\n");
    if(id > 0 && id <= QueueLength(*QueueLagu)) {
        Queue Qtmp; CreateQueue(&Qtmp);
        currentLagu Ltmp, Lrmv;
        int i = 1;

        while(!isQueueEmpty(*QueueLagu)) {
            dequeue(QueueLagu, &Ltmp);
            enqueue(&Qtmp, Ltmp);
        }

        while(!isQueueEmpty(Qtmp)) {
            dequeue(&Qtmp, &Ltmp);
            if(i != id)
                enqueue(QueueLagu, Ltmp);
            else
                Lrmv = Ltmp;
            i ++;
        }

        printf("Lagu \""); printWord(Lrmv.Lagu); printf("\" oleh \""); printWord(Lrmv.Penyanyi); printf("\" telah dihapus dari queue.\n");
    }

    else
        printf("Lagu dengan urutan ke %d tidak ada.\n", id);
}

void QueueWW_Clear(Queue *QueueLagu) {
    CreateQueue(QueueLagu);

    printf("\n");
    printf("Queue berhasil dikosongkan.\n");
}

void SongWW_Next(Stack *History, currentLagu *LaguNow, Queue *QueueLagu) {}

void SongWW_Previous(Stack *History, currentLagu *LaguNow, Queue *QueueLagu) {}

void PlaylistWW_Create(ArrayDin *Playlist) {}

void PlaylistWW_Add_Song(List Penyanyi, ArrayDin *Playlist) {}

void PlaylistWW_Add_Album(List Penyanyi, ArrayDin *Playlist) {}

void PlaylistWW_Swap(ArrayDin *Playlist, int id, int x, int y) {}

void PlaylistWW_Remove(ArrayDin *Playlist, int id, int n) {}

void PlaylistWW_Delete(ArrayDin *Playlist) {}

void StatusWW(currentLagu LaguNow, Queue QueueLagu) {
    printf("\n");
    if(LaguNow.fromPlaylist.Length != 0) {
        printf("Current Playlist : "); printWord(LaguNow.fromPlaylist); printf("\n");
        printf("\n");
    }

    printf("Now Playing:\n");
    if(LaguNow.Lagu.Length != 0) {
        printInfoLagu(LaguNow); printf(";\n");
    }
    else
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    
    printf("\n");
    printf("Queue:\n");
    if(isQueueEmpty(QueueLagu))
        printf("Your queue is empty.\n");
    else {
        int x = QueueLength(QueueLagu);
        for (int i = QueueIdxHead(QueueLagu); i <= QueueIdxTail(QueueLagu); i++) {
            printf("   %d. ", i+1); printInfoLagu(QueueLagu.buffer[i]); printf("\n");
        }
    }
}

void SaveWW(char* dirfile, List Penyanyi, currentLagu LaguNow, Queue QueueLagu, Stack History, ArrayDin Playlist) {
    FILE *file;
    file = fopen(dirfile, "w");
    fprintf(file,"%d\n", ListLength(Penyanyi));
    for (int i = 0; i < ListLength(Penyanyi); i++){
        fprintf(file, "%d %s\n", Penyanyi.A[i].Album.Count, Word2str(Penyanyi.A[i].NamaPenyanyi));
        for (int j = 0; j < Penyanyi.A[i].Album.Count; j++){
            fprintf(file, "%d %s\n", Penyanyi.A[i].Album.Elements[j].Value.Lagu.Count, Word2str(Penyanyi.A[i].Album.Elements[j].Value.NamaAlbum));
            for (int k = 0; k < Penyanyi.A[i].Album.Elements[j].Value.Lagu.Count; k++){
                fprintf(file, "%s\n", Word2str(Penyanyi.A[i].Album.Elements[j].Value.Lagu.Elements[k]));
            }
        }
    }
    // LaguNow
    fprintf(file, "%s;%s;%s\n", Word2str(LaguNow.Penyanyi), Word2str(LaguNow.Album), Word2str(LaguNow.Lagu));
    // Queue
    fprintf(file, "%d\n", QueueLength(QueueLagu));
    for (int i = QueueIdxHead(QueueLagu); i <= QueueIdxTail(QueueLagu); i++){
        fprintf(file, "%s;%s;%s\n",Word2str(QueueLagu.buffer[i].Penyanyi),Word2str(QueueLagu.buffer[i].Album),Word2str(QueueLagu.buffer[i].Lagu));
    }
    // History
    fprintf(file, "%d\n", (History.TOP+1));
    for (int i = 0; i <= History.TOP; i++){
        fprintf(file, "%s;%s;%s\n",Word2str(History.T[i].Penyanyi),Word2str(History.T[i].Album),Word2str(History.T[i].Lagu));
    }
    fclose(file);
}

void QuitWW() {}

void HelpWW_before() {}

void HelpWW_after() {}
