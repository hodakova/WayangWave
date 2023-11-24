#include "console.h"

int random_number(int nMin, int nMax) {
    return nMin + rand() % (nMax + 1);
}

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
        CreateListLinier(&arraytmp.DaftarLagu);
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

    printf("\n");
    boolean lanjut = false;
    while(!lanjut) {
        printf("Ingin melihat album yang ada? (Y/N) : "); STARTWORD();

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
                printf("Ingin melihat lagu yang ada? (Y/N) : "); STARTWORD();

                if (isWordEqual(currentWord, str2Word("Y"))) {
                    lanjut2 = true;

                    found = false; int a;
                    printf("\n");
                    while(!found) {
                        printf("Pilih album untuk melihat lagu yang ada di album : "); STARTWORD(); currentWordTillSC();
                        
                        a = 0;
                        while(a < jumlah_album && !found) {
                            if (isWordEqual(currentWord, (Penyanyi).A[j].Album.Elements[a].Value.NamaAlbum))
                                found = true;
                            else
                                a++;
                        }

                        if(!found)
                            Command_unknown();
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
                
                else {
                    currentWordTillSC();
                    Command_unknown();
                }
            }
        }
    
        else if(isWordEqual(currentWord, str2Word("N")))
            lanjut = true;
        
        else {
            currentWordTillSC();
            Command_unknown();
        }
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

void PlayWW_Song(List Penyanyi, Queue *QueueLagu, Stack *History, currentLagu *LaguNow) {
    Word picka, pickl, pickp;

    printf("\n");
    printf("Daftar Penyanyi :\n");

    int x = ListLength(Penyanyi);
    for (int i = 0; i < x; i++) {
        printf("   %d. ", i+1); printWord((Penyanyi).A[i].NamaPenyanyi); printf("\n");
    }

    printf("\n");
    boolean found = false; int j;
    while(!found) {

        printf("Masukkan Nama Penyanyi yang dipilih : "); STARTWORD(); currentWordTillSC();

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
    pickp = currentWord;
    printf("Daftar Album oleh "); printWord(pickp); printf(" :\n");
    int jumlah_album = (Penyanyi).A[j].Album.Count;
    for (int k = 0; k < jumlah_album; k++) {
        printf("   %d. ", k+1); printWord((Penyanyi).A[j].Album.Elements[k].Value.NamaAlbum); printf("\n");
    }

    printf("\n");
    found = false; int a;
    while(!found) {
        printf("Masukkan Nama Album yang dipilih : "); STARTWORD(); currentWordTillSC();
        
        a = 0;
        while(a < jumlah_album && !found) {
            if (isWordEqual(currentWord, (Penyanyi).A[j].Album.Elements[a].Value.NamaAlbum))
                found = true;
            else
                a++;
        }

        if(!found)
            Command_unknown();
    }
    
    printf("\n");
    picka = currentWord;
    printf("Daftar Lagu Album "); printWord(picka); printf(" oleh "); printWord(pickp); printf(" :\n");

    int jumlah_lagu = (Penyanyi).A[j].Album.Elements[a].Value.Lagu.Count;
    for (int b = 0; b < jumlah_lagu;b++) {
        printf("   %d. ", b+1); printWord((Penyanyi).A[j].Album.Elements[a].Value.Lagu.Elements[b]); printf("\n");
    }

    printf("\n");
    found = false;
    while(!found) {
        printf("Masukkan ID Lagu yang dipilih : "); STARTWORD();
        int ID = Word2int(currentWord);

        printf("\n");
        if(ID > 0 && ID <= jumlah_lagu) {
            found = true;
            pickl = (Penyanyi).A[j].Album.Elements[a].Value.Lagu.Elements[ID-1];

            //define current song
            CreateInfoLagu(LaguNow);
            LaguNow->Album = picka;
            LaguNow->Penyanyi = pickp;
            LaguNow->Lagu = pickl;
            //mengosongkan queue dan stack
            CreateQueue(QueueLagu);
            CreateStack(History);
            printf("Memutar lagu \""); printWord(pickl); printf("\" oleh \""); printWord(pickp); printf("\".\n");

        }
        else {
            currentWordTillSC();
            printf("ID Playlist tidak valid! Tidak ada lagu dengan ID = %d.\n", ID);
        }
        
    }
}

void PlayWW_Playlist(ArrayDin Playlist, Queue *QueueLagu, Stack *History, currentLagu *LaguNow) {
    printf("\n");
    if(IsArrayDinEmpty(Playlist))
        printf("Kamu tidak memiliki playlist.\n");
    else {
        printf("Masukkan ID Playlist: "); STARTWORD();
        int id = Word2int(currentWord);

        printf("\n");
        if(id > 0 && id <= ArrayDinLength(Playlist)) {
            CreateQueue(QueueLagu);
            CreateStack(History);

            addressListLinier P = Playlist.A[id-1].DaftarLagu.ListLinierFirst;
            if(P != ListLinierNil) {
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
                printf("Tidak ada lagu pada playlist \""); printWord(Playlist.A[id-1].NamaPlaylist); printf("\". Playlist tidak dapat diputar!\n");
            }

        }

        else {
            currentWordTillSC();
            printf("ID Playlist tidak valid! Tidak ada playlist dengan ID = %d.\n", id);
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
        currentLagu Lagu; CreateInfoLagu(&Lagu);

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
            printf("Masukkan ID Lagu yang dipilih: "); STARTWORD();
            k = Word2int(currentWord) - 1;
            if(k >= 0 && k < l)
                found = true;

            if(!found) {
                currentWordTillEOL();
                Command_unknown();
            }
        }

        Lagu.Lagu = Penyanyi.A[i].Album.Elements[j].Value.Lagu.Elements[k];
        enqueue(QueueLagu, Lagu);
        
        printf("\n");
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
            printf("Masukkan ID Playlist: "); STARTWORD();
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
                currentWordTillSC();
                printf("ID Playlist tidak valid! Tidak ada playlist dengan id = %d.\n", id+1);
                printf("Tips: Ketik LIST PLAYLIST untuk melihat ID Playlist!\n");
            }
        }
    }
}

void QueueWW_Swap(Queue *QueueLagu, int x, int y) {
    printf("\n");
    if(!isQueueEmpty(*QueueLagu)) {
        boolean isXvalid = false, isYvalid = false;
        int l = QueueLength(*QueueLagu), iHead = QueueIdxHead(*QueueLagu);

        if(x > 0 && x <= l)
            isXvalid = true;
        if(y > 0 && y <= l)
            isYvalid = true;

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
    else
        printf("Queue kosong!\n");
}

void QueueWW_Remove(Queue *QueueLagu, int id) {
    printf("\n");
    if(!isQueueEmpty(*QueueLagu)) {
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
    else 
        printf("Queue kosong!\n");
}

void QueueWW_Clear(Queue *QueueLagu) {
    printf("\n");
    if(!isQueueEmpty(*QueueLagu)) {
        CreateQueue(QueueLagu);
        printf("Queue berhasil dikosongkan.\n");
    }
    else
        printf("Queue sudah kosong!\n");
}

void SongWW_Next(Stack *History, currentLagu *LaguNow, Queue *QueueLagu) {
    printf("\n");
    if(!isQueueEmpty(*QueueLagu))
    {
        Push(History, *LaguNow);
        dequeue(QueueLagu,LaguNow);
        printf("Memutar lagu selanjutnya\n");
        
        printf("\""); printWord(LaguNow->Lagu); printf("\" oleh \""); printWord(LaguNow->Penyanyi);printf("\"\n");
    }
    else if ((!isInfoLaguEmpty(*LaguNow)))
    {
        printf("Queue kosong, memutar kembali lagu\n");
        printf("\""); printWord(LaguNow->Lagu); printf("\" oleh \""); printWord(LaguNow->Penyanyi);printf("\"\n");
    }
    else
    {
        printf("Queue kosong, Current Lagu kosong\n");
    }
}

void SongWW_Previous(Stack *History, currentLagu *LaguNow, Queue *QueueLagu) {
    printf("\n");
    if(!IsStackEmpty(*History))
    {
        Queue tempQueue; CreateQueue(&tempQueue);
        QueueElType temp;
        while(!isQueueEmpty(*QueueLagu)){
            dequeue(QueueLagu, &temp);
            enqueue(&tempQueue, temp);
        }
        enqueue(QueueLagu,*LaguNow);
        while(!isQueueEmpty(tempQueue)){
            dequeue(&tempQueue, &temp);
            enqueue(QueueLagu, temp);
        }
        Pop(History,LaguNow);
        printf("Memutar lagu sebelumnya\n");
        printf("\""); printWord(LaguNow->Lagu); printf("\" oleh \""); printWord(LaguNow->Penyanyi);printf("\"\n");
    }
    else if ((!isInfoLaguEmpty(*LaguNow)))
    {
        printf("Riwayat kosong, memutar kembali lagu\n");
        printf("\""); printWord(LaguNow->Lagu); printf("\" oleh \""); printWord(LaguNow->Penyanyi);printf("\"\n");
    }
    else
    {
        printf("Riwayat kosong, Current Lagu Kosong\n");
    }
}

void PlaylistWW_Create(ArrayDin *Playlist) {
    printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTWORD();
    currentWordTillSC();

    boolean valid = false;
    int charCount = 0, i = 0;
    //printWord(currentWord);
    while(!valid && i < currentWord.Length) {
        if(currentWord.TabWord[i] != BLANK)
            charCount ++;
        if(charCount == 3)
            valid = true;
        i ++;
    }

    if(valid) {
        ArrayDinElType el;
        el.NamaPlaylist = currentWord;
        CreateListLinier(&el.DaftarLagu);

        ArrayDinInsertLast(Playlist, el);
        printf("\nPlaylist "); printWord(el.NamaPlaylist); printf(" berhasil dibuat!\n");
        printf("Silahkan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
    }
    else 
        printf("\nMinimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
}

void PlaylistWW_Add_Song(List Penyanyi, ArrayDin *Playlist) {
    if(!IsArrayDinEmpty(*Playlist)) {
        int idPenyanyi = 0, lenPenyanyi = ListLength(Penyanyi);
        printf("\nDaftar Penyanyi: \n");
        for (int i = 0; i < lenPenyanyi; i++) {
            printf("   %d. ", i+1); printWord((Penyanyi).A[i].NamaPenyanyi); printf("\n");
        }
        printf("\nMasukkan Nama Penyanyi yang dipilih: "); STARTWORD(); currentWordTillSC();
        boolean penyanyiexist = false;
        while (idPenyanyi < lenPenyanyi && !penyanyiexist) {
            if(isWordEqual(Penyanyi.A[idPenyanyi].NamaPenyanyi, currentWord)) {
                penyanyiexist = true;
            }
            else {
                idPenyanyi++;
            }
        }
        if (penyanyiexist) {
            printf("\nDaftar Album oleh "); printWord(currentWord); printf(" :\n");
            int albumCount = Penyanyi.A[idPenyanyi].Album.Count;
            for (int i = 0; i < albumCount; i++) {
                printf("   %d. ", i+1); printWord((Penyanyi).A[idPenyanyi].Album.Elements[i].Value.NamaAlbum); printf("\n");
            }
            printf("\nMasukkan Judul Album yang dipilih: "); STARTWORD(); currentWordTillSC();
            boolean albumexist = false;
            int idAlbum = 0;
            while (idAlbum < albumCount && !albumexist) {
                if(isWordEqual((Penyanyi).A[idPenyanyi].Album.Elements[idAlbum].Value.NamaAlbum, currentWord)) {
                    albumexist = true;
                }
                else {
                    idAlbum++;
                }
            }
            if (albumexist) {
                printf("\nDaftar Lagu Album "); printWord(currentWord); printf(" oleh "); printWord(Penyanyi.A[idPenyanyi].NamaPenyanyi); printf(" :\n");
                int laguCount = (Penyanyi).A[idPenyanyi].Album.Elements[idAlbum].Value.Lagu.Count;
                for (int i = 0; i < laguCount; i++) {
                    printf("   %d. ", i+1); printWord((Penyanyi).A[idPenyanyi].Album.Elements[idAlbum].Value.Lagu.Elements[i]); printf("\n");
                }
                printf("\nMasukkan ID Lagu yang dipilih : ");
                STARTWORD();
                int idLagu = Word2int(currentWord);
                if (idLagu > 0 && idLagu < laguCount + 1) {
                    printf("\nDaftar Playlist Pengguna :\n");
                    int playlistCount = ArrayDinLength(*Playlist);
                    for (int i = 0; i < playlistCount; i++) {
                    printf("   %d. ", i+1); printWord(Playlist->A[i].NamaPlaylist); printf("\n");
                    }
                    printf("\nMasukkan ID Playlist yang dipilih : ");
                    STARTWORD();
                    int idPlaylist = Word2int(currentWord);

                    if (idPlaylist > 0 && idPlaylist <= playlistCount) {
                        int countLagu = 0, i, j, m, n = ListLength(Penyanyi);
                        for(i = 0; i < n; i ++) {
                            m = Penyanyi.A[i].Album.Count;
                            for(j = 0; j < m; j ++) {
                                countLagu += Penyanyi.A[i].Album.Elements[j].Value.Lagu.Count;
                            }
                        }

                        if(ListLinierNbElmt(Playlist->A[idPlaylist-1].DaftarLagu) < countLagu) {
                            currentLagu temp; CreateInfoLagu(&temp);
                            temp.Album = (Penyanyi).A[idPenyanyi].Album.Elements[idAlbum].Value.NamaAlbum;
                            temp.Penyanyi = Penyanyi.A[idPenyanyi].NamaPenyanyi;
                            temp.Lagu = (Penyanyi).A[idPenyanyi].Album.Elements[idAlbum].Value.Lagu.Elements[idLagu - 1];
                            printf("\nLagu dengan judul \""); printWord(temp.Lagu); printf("\" pada album "); printWord(temp.Album); printf(" oleh penyanyi "); printWord(temp.Penyanyi); 
                            if(!isListLinierMember(Playlist->A[idPlaylist - 1].DaftarLagu, temp)) {
                                ListLinierInsVLast(&Playlist->A[idPlaylist - 1].DaftarLagu, temp);
                                printf(" berhasil ditambahkan ke dalam playlist ");
                            }
                            else
                                printf(" sudah ada pada playlist ");
                            printWord(Playlist->A[idPlaylist - 1].NamaPlaylist); printf(".\n");
                            // ListLinierPrintInfo(Playlist->A[idPlaylist - 1].DaftarLagu);
                        }
                        else {
                            printf("Semua lagu yang tersedia sudah ada di dalam playlist pengguna \""); printWord(Playlist->A[idPlaylist-1].NamaPlaylist); printf("\".\n");
                        }
                    }
                    else {
                        currentWordTillSC();
                        printf("\nID playlist tidak ada dalam daftar, Silakan coba lagi.\n");
                    }
                }
                else {
                    currentWordTillSC();
                    printf("\nID lagu tidak ada dalam daftar. Silakan coba lagi.\n");
                }
            }
            else {
                printf("\nAlbum "); printWord(currentWord); printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        }
        else {
            printf("\nPenyanyi "); printWord(currentWord); printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    }
    else 
        printf("\nKamu tidak memiliki playlist.\n");
}

void PlaylistWW_Add_Album(List Penyanyi, ArrayDin *Playlist) {
    printf("\n");
    if(!IsArrayDinEmpty(*Playlist)) {
        int a, b, i, idP, n, m, p, l;
        boolean found, sudahAda, semuanyaAda = true;

        printf("Daftar Penyanyi :\n");
        n = ListLength(Penyanyi);
        for(i = 0; i < n; i ++) {
            printf("   %d. ", i+1); printWord(Penyanyi.A[i].NamaPenyanyi); printf("\n");
        }

        printf("\n");
        printf("Masukkan Nama Penyanyi yang dipilih : "); STARTWORD(); currentWordTillSC();

        found = false; a = 0;
        while(!found && a < n) {
            if(isWordEqual(Penyanyi.A[a].NamaPenyanyi, currentWord))
                found = true;
            else
                a ++;
        }

        printf("\n");
        if(found) {
            currentLagu Ltmp;
            Ltmp.Penyanyi = currentWord;

            printf("Daftar Album oleh "); printWord(Ltmp.Penyanyi); printf(" :\n");
            m = Penyanyi.A[a].Album.Count;
            for(i = 0; i < m; i ++) {
                printf("   %d. ", i+1); printWord(Penyanyi.A[a].Album.Elements[i].Value.NamaAlbum); printf("\n");
            }

            printf("\n");
            printf("Masukkan Judul Album yang dipilih : "); STARTWORD(); currentWordTillSC();

            found = false; b = 0;
            while(!found && b < m) {
                if(isWordEqual(Penyanyi.A[a].Album.Elements[b].Value.NamaAlbum, currentWord))
                    found = true;
                else
                    b ++;
            }

            printf("\n");
            if(found) {
                Ltmp.Album = currentWord;

                printf("Daftar Playlist Pengguna :\n");
                p = ArrayDinLength(*Playlist);
                for(i = 0; i < p; i ++) {
                    printf("   %d. ", i+1); printWord(Playlist->A[i].NamaPlaylist); printf("\n");
                }

                printf("\n");
                printf("Masukkan ID Playlist yang dipilih : "); STARTWORD();
                idP = Word2int(currentWord);

                printf("\n");
                if(idP > 0 && idP <= p) {
                    int countLagu = 0, j; n = ListLength(Penyanyi);
                    for(i = 0; i < n; i ++) {
                        m = Penyanyi.A[i].Album.Count;
                        for(j = 0; j < m; j ++) {
                            countLagu += Penyanyi.A[i].Album.Elements[j].Value.Lagu.Count;
                        }
                    }

                    if(ListLinierNbElmt(Playlist->A[idP-1].DaftarLagu) < countLagu) {
                        l = Penyanyi.A[a].Album.Elements[b].Value.Lagu.Count;
                        sudahAda = false; semuanyaAda = true;
                        for(i = 0; i < l; i ++) {
                            Ltmp.Lagu = Penyanyi.A[a].Album.Elements[b].Value.Lagu.Elements[i];
                            if(!isListLinierMember(Playlist->A[idP-1].DaftarLagu, Ltmp)) {
                                ListLinierInsVLast(&Playlist->A[idP-1].DaftarLagu, Ltmp);
                                semuanyaAda = false;
                            }
                            else
                                sudahAda = true;
                        }
                        if(!semuanyaAda) {
                            if(!sudahAda) {
                                printf("Album dengan judul \""); printWord(Ltmp.Album); printf("\" berhasil ditambahkan ke dalam playlist pengguna \""); printWord(Playlist->A[idP-1].NamaPlaylist); printf("\".\n");
                            }
                            else {
                                printf("Beberapa lagu pada album dengan judul \""); printWord(Ltmp.Album); printf("\" sudah ditambahkan ke dalam playlist pengguna \""); printWord(Playlist->A[idP-1].NamaPlaylist); printf("\".\n");
                                printf("Berhasil menambahkan sisanya.\n");
                            }
                        }
                        else {
                            printf("Semua lagu pada album dengan judul \""); printWord(Ltmp.Album); printf("\" sudah ada di dalam playlist pengguna \""); printWord(Playlist->A[idP-1].NamaPlaylist); printf("\".\n");
                        }
                    }
                    else {
                        printf("Semua lagu yang tersedia sudah ada di dalam playlist pengguna \""); printWord(Playlist->A[idP-1].NamaPlaylist); printf("\".\n");
                    }
                }
                else {
                    currentWordTillSC();
                    printf("Tidak ada playlist dengan playlist ID %d\n", idP);
                }
            }
            else {
                printf("Album "); printWord(currentWord); printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        }
        else {
            printf("Penyanyi "); printWord(currentWord); printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    }
    else  
        printf("Kamu tidak memiliki playlist.\n");
}

void PlaylistWW_Swap(ArrayDin *Playlist, int id, int x, int y) {
    printf("\n");
    if(!IsArrayDinEmpty(*Playlist)) {
        if(id > 0 && id <= ArrayDinLength(*Playlist)) {
            boolean xValid = false, yValid = false;
            int i, l = ListLinierNbElmt(Playlist->A[id-1].DaftarLagu);

            if(x > 0 && x <= l)
                xValid = true;
            if(y > 0 && x <= l)
                yValid = true;
            
            if(xValid && yValid) {
                // ListLinierPrintInfo(Playlist->A[id-1].DaftarLagu);
                addressListLinier P = Playlist->A[id-1].DaftarLagu.ListLinierFirst, Px, Py;
                i = 1;
                while(P != ListLinierNil) {
                    if(i == x)
                        Px = P;
                    if(i == y)
                        Py = P;
                    P = ListLinierNext(P);
                    i++;
                }
                currentLagu Ltmp = ListLinierInfo(Px);
                ListLinierInfo(Px) = ListLinierInfo(Py);
                ListLinierInfo(Py) = Ltmp;

                // ListLinierPrintInfo(Playlist->A[id-1].DaftarLagu);
                printf("Berhasil menukar lagu dengan nama \""); printWord(Ltmp.Lagu); printf("\" dengan \""); printWord(ListLinierInfo(Px).Lagu); printf("\" di playlist \""); printWord(Playlist->A[id-1].NamaPlaylist); printf("\"\n");
            }
            else {
                printf("Tidak ada lagu dengan ");
                if(!xValid)
                    printf("urutan %d", x);
                if(!xValid && !yValid)
                    printf(" dan ");
                if(!yValid)
                    printf("urutan %d", y);
                printf("di playlist \""); printWord(Playlist->A[id-1].NamaPlaylist); printf("\"\n");
            }
        }
        else
            printf("Tidak ada playlist dengan playlist ID %d\n", id);
    }
    else
        printf("Kamu tidak memiliki playlist.\n");
}

void PlaylistWW_Remove(ArrayDin *Playlist, int id, int n) {
    printf("\n");
    if(!IsArrayDinEmpty(*Playlist)) {
        if(id > 0 && id <= ArrayDinLength(*Playlist)) {
            if(n > 0 && n <= ListLinierNbElmt(Playlist->A[id-1].DaftarLagu)) {
                ListLinierPrintInfo(Playlist->A[id-1].DaftarLagu);

                addressListLinier P = Playlist->A[id-1].DaftarLagu.ListLinierFirst, Pdel;
                int i = 1;
                while(i < n-1)
                    P = ListLinierNext(P);
                // P = address lagu playlist ke n-1
                
                Pdel = ListLinierNext(P); 
                if(ListLinierNext(ListLinierNext(P)) != ListLinierNil)
                    ListLinierNext(P) = ListLinierNext(ListLinierNext(P));
                else
                    ListLinierNext(P) = ListLinierNil;

                printf("Lagu \""); printWord(ListLinierInfo(Pdel).Lagu); printf("\" oleh \""); printWord(ListLinierInfo(P).Penyanyi); printf("\" telah dihapus dari playlist \""); printWord(Playlist->A[id-1].NamaPlaylist); printf("\"!\n");
                ListLinierDealokasi(&Pdel);

                ListLinierPrintInfo(Playlist->A[id-1].DaftarLagu);
            }
            else {
                printf("Tidak ada lagu dengan urutan %d di playlist \"", n); printWord(Playlist->A[id-1].NamaPlaylist); printf("\"!\n");
            }
        }
        else
            printf("Tidak ada playlist dengan ID %d.", id);
    }
    else
        printf("Kamu tidak memiliki playlist.\n");
}

void PlaylistWW_Delete(ArrayDin *Playlist) {
    if(!IsArrayDinEmpty(*Playlist)) {
        printf("\nDaftar Playlist Pengguna :\n");
        int playlistCount = ArrayDinLength(*Playlist);
        for (int i = 0; i < playlistCount; i++) {
            printf("   %d. ", i+1); printWord(Playlist->A[i].NamaPlaylist); printf("\n");
        }
        printf("\nMasukkan ID Playlist yang dipilih: ");
        STARTWORD();
        int idP = Word2int(currentWord);
        if (idP > 0 && idP < playlistCount + 1) {
            Word temp = Playlist->A[idP - 1].NamaPlaylist;
            ArrayDinDeleteAt(Playlist, idP - 1);
            //PrintArrayDin(*Playlist);
            printf("\nPlaylist dengan ID %d dengan judul \"", idP); printWord(temp); printf("\" berhasil dihapus.\n");
        }
        else {
            currentWordTillSC();
            printf("\nTidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", idP);
        } 
    }
    else 
        printf("\nKamu tidak memiliki playlist.\n");
}

void PlaylistWW_Enhance(ArrayDin *Playlist, List Penyanyi) {
    printf("\n");
    if(!IsArrayDinEmpty(*Playlist)) {
        printf("Daftar Playlist Pengguna :\n");
        int playlistCount = ArrayDinLength(*Playlist);
        for (int i = 0; i < playlistCount; i++) {
            printf("   %d. ", i+1); printWord(Playlist->A[i].NamaPlaylist); printf("\n");
        }
        printf("\nMasukkan ID Playlist yang dipilih: ");
        STARTWORD();
        int id = Word2int(currentWord);

        printf("\n");
        if(id > 0 && id <= Playlist->Neff) {
            if(!IsListLinierEmpty(Playlist->A[id-1].DaftarLagu)) {
                int countLagu = 0, i, j, n = ListLength(Penyanyi), m, p;
                for(i = 0; i < n; i ++) {
                    m = Penyanyi.A[i].Album.Count;
                    for(j = 0; j < m; j ++) {
                        countLagu += Penyanyi.A[i].Album.Elements[j].Value.Lagu.Count;
                    }
                }
                j = ListLinierNbElmt(Playlist->A[id-1].DaftarLagu);
                if(j < countLagu) {
                    printf("Daftar lagu pada playlist pengguna "); printWord(Playlist->A[id-1].NamaPlaylist); printf(" :\n");
                    addressListLinier P = Playlist->A[id-1].DaftarLagu.ListLinierFirst, Q;
                    i = 1;
                    while(P != ListLinierNil) {
                        printf("   %d. ", i); printInfoLagu(ListLinierInfo(P)); printf("\n");
                        P = ListLinierNext(P);
                        i ++;
                    }
                    p = i;

                    printf("\n");
                    printf("Daftar lagu rekomendasi untuk playlist pengguna "); printWord(Playlist->A[id-1].NamaPlaylist); printf(" :\n");

                    ListLinier RecommendedSongs; CreateListLinier(&RecommendedSongs);
                    currentLagu tmpL; CreateInfoLagu(&tmpL);
                    boolean found;
                    int r = random_number(1, 5) + i, a, b, c, e[r], h = 0, k, g;

                    while(i < r && j < countLagu) {
                        a = random_number(0, n - 1);
                        tmpL.Penyanyi = Penyanyi.A[a].NamaPenyanyi;
                        b = random_number(0, Penyanyi.A[a].Album.Count - 1);
                        tmpL.Album = Penyanyi.A[a].Album.Elements[b].Value.NamaAlbum;
                        c = random_number(0, Penyanyi.A[a].Album.Elements[b].Value.Lagu.Count - 1);
                        tmpL.Lagu = Penyanyi.A[a].Album.Elements[b].Value.Lagu.Elements[c];
                        if(!isListLinierMember(Playlist->A[id-1].DaftarLagu, tmpL) && !isListLinierMember(RecommendedSongs, tmpL)) {
                            ListLinierInsVLast(&RecommendedSongs, tmpL);
                            printf("   %d. ", i); printInfoLagu(tmpL); printf("\n");
                            i ++;
                            j ++;
                        }
                    }
                    printf("\n");
                    printf("Pilih ID-ID lagu pada daftar lagu rekomendasi untuk ditambahkan ke playlist pengguna \""); printWord(Playlist->A[id-1].NamaPlaylist); printf("\" : "); STARTWORD();
                    h = 0;
                    while(currentChar != EOL) {
                        e[h] = Word2int(currentWord);
                        found = false;
                        if(e[h] >= p && e[h] < i) {
                            for(k = 0; k < h; k ++) {
                                if(e[h] == e[k])
                                    found = true;
                            }
                            if(!found)
                                h ++;
                        }
                        ADVWORD();
                    }     
                    e[h] = Word2int(currentWord);
                    found = false;
                    if(e[h] >= p && e[h] < i) {
                        for(k = 0; k < h; k ++) {
                            if(e[h] == e[k])
                                found = true;
                        }
                        if(!found)
                            h ++;
                    }

                    printf("\n");
                    if(h > 0) {
                        if(h == 1)
                            printf("Lagu rekomendasi dengan ID ");
                        else
                            printf("Lagu-lagu rekomendasi dengan ID-ID ");
                        for(k = 0; k < h; k ++) {
                            printf("%d", e[k]);
                            if(h > 2) {
                                if(k < h-1)
                                    printf(", ");
                            }
                            else if(h == 2) {
                                if(k==0)
                                    printf(" ");
                            }
                            if(h > 1) {
                                if(k==h-2)
                                    printf("dan ");
                            }
                            if(e[k] == p) {
                                ListLinierDelFirst(&RecommendedSongs, &P);
                                p ++;
                            }
                            else if(e[k] == i - 1)
                                ListLinierDelLast(&RecommendedSongs, &P);
                            else {
                                Q = RecommendedSongs.ListLinierFirst;
                                g = p;
                                while(ListLinierNext(Q) != ListLinierNil && g < e[k]) {
                                    Q = ListLinierNext(Q);
                                    g ++;
                                }
                                ListLinierDelAfter(&RecommendedSongs, &P, Q);
                            }
                            ListLinierInsertLast(&Playlist->A[id-1].DaftarLagu, P);
                        }
                        printf(" berhasil ditambahkan ke playlist pengguna \""); printWord(Playlist->A[id-1].NamaPlaylist); printf("\".\n");
                    }
                    else
                        printf("Gunakan format <a b c ...> untuk menuliskan ID-ID lagu rekomendasi.\n");

                    while(!IsListLinierEmpty(RecommendedSongs))
                        ListLinierDelVLast(&RecommendedSongs, &tmpL);
                }
                else {
                    printf("Tidak dapat meng-enhance playlist pengguna \""); printWord(Playlist->A[id-1].NamaPlaylist); printf("\".\n");
                    printf("Semua lagu yang tersedia sudah ada di dalam playlist.\n");
                }
            }
            else {
                printf("Tidak dapat meng-enhance playlist pengguna \""); printWord(Playlist->A[id-1].NamaPlaylist); printf("\".\n");
                printf("Playlist masih kosong. Silahkan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
            }
        }
        else {
            currentWordTillSC();
            printf("Tidak ada playlist dengan ID %d\n", id);
        }
    }
    else
        printf("Kamu tidak memiliki playlist.\n");
}

void StatusWW(currentLagu LaguNow, Queue QueueLagu) {
    printf("\n");
    if(!isWordEqual(LaguNow.fromPlaylist, str2Word("-"))) {
        printf("Current Playlist : "); printWord(LaguNow.fromPlaylist); printf("\n");
        printf("\n");
    }

    printf("Now Playing:\n");
    if(!isInfoLaguEmpty(LaguNow)) {
        printInfoLagu(LaguNow); printf("\n");
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
    int i, j, k, n;
    FILE *file;
    file = fopen(dirfile, "w");
    fprintf(file,"%d\n", ListLength(Penyanyi));
    for (i = 0; i < ListLength(Penyanyi); i++){
        fprintf(file, "%d ", Penyanyi.A[i].Album.Count); fprintWord(file, Penyanyi.A[i].NamaPenyanyi); fprintf(file, "\n");
        for (j = 0; j < Penyanyi.A[i].Album.Count; j++) {   
            fprintf(file, "%d ", Penyanyi.A[i].Album.Elements[j].Value.Lagu.Count); fprintWord(file, Penyanyi.A[i].Album.Elements[j].Value.NamaAlbum); fprintf(file, "\n");
            for (k = 0; k < Penyanyi.A[i].Album.Elements[j].Value.Lagu.Count; k++) {
                fprintWord(file, Penyanyi.A[i].Album.Elements[j].Value.Lagu.Elements[k]); fprintf(file, "\n");
            }
        }
    }
    // LaguNow
    fprintWord(file, LaguNow.Penyanyi); fprintf(file, ";"); fprintWord(file, LaguNow.Album); fprintf(file, ";"); fprintWord(file, LaguNow.Lagu); fprintf(file, "\n");
    // Queue
    fprintf(file, "%d\n", QueueLength(QueueLagu));
    if(!isQueueEmpty(QueueLagu)) {
        for (i = QueueLagu.idxHead; i <= QueueLagu.idxTail; i++) {
            fprintWord(file, QueueLagu.buffer[i].Penyanyi); fprintf(file, ";"); fprintWord(file, QueueLagu.buffer[i].Album); fprintf(file, ";"); fprintWord(file, QueueLagu.buffer[i].Lagu); fprintf(file, "\n");
        }
    }
    // History
    fprintf(file, "%d\n", (History.TOP+1));
    for (i = 0; i <= History.TOP; i++) {
        fprintWord(file, History.T[i].Penyanyi); fprintf(file, ";"); fprintWord(file, History.T[i].Album); fprintf(file, ";"); fprintWord(file, History.T[i].Lagu); fprintf(file, "\n");
    }
    // Playlist
    // currentLagu temp;
    addressListLinier P;
    fprintf(file, "%d\n", Playlist.Neff);
    for (i = 0; i < Playlist.Neff; i++) {
        n = ListLinierNbElmt(Playlist.A[i].DaftarLagu);
        fprintf(file, "%d ", n); fprintWord(file, Playlist.A[i].NamaPlaylist); fprintf(file, "\n");
        P = Playlist.A[i].DaftarLagu.ListLinierFirst;
        while(P != ListLinierNil) {
            fprintWord(file, ListLinierInfo(P).Penyanyi); fprintf(file, ";"); fprintWord(file, ListLinierInfo(P).Album); fprintf(file, ";"); fprintWord(file, ListLinierInfo(P).Lagu); fprintf(file, "\n");
            P = ListLinierNext(P);
        }
    }
    fclose(file);
}

void QuitWW(List Penyanyi, currentLagu LaguNow, Queue QueueLagu, Stack History, ArrayDin Playlist) {
    printf("\nApakah kamu ingin menyimpan data sesi sekarang? (Y/N) : "); STARTWORD();
    while (!(isWordEqual(currentWord, str2Word("Y")) || isWordEqual(currentWord, str2Word("N")))) {    
        printf("\nInput tidak valid. Silakan memasukkan 'Y' jika ingin menyimpan data sesi sekarang dan 'N' jika tidak ingin menyimpan data sesi sekarang (Y/N): "); STARTWORD();
    }
    if (isWordEqual(currentWord, str2Word("Y"))) {
        boolean valid = false; int n;
        printf("\nSilakan input nama file : "); STARTWORD();
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
        char* dirfile = Word2str(ConcatWord(str2Word("../save/"), currentWord));
        if (isFileExist(dirfile)) { 
            SaveWW(dirfile, Penyanyi, LaguNow, QueueLagu, History, Playlist);
            printf("\nSave file berhasil disimpan.\n");
        }
        else {
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
        printf("Thank you for using WayangWave!\n");
    }
    else if(isWordEqual(currentWord, str2Word("N")))
    {
        printf("\nKamu keluar dari WayangWave.\n");
        printf("Dadah ^_^/\n");
    }
    int n = ArrayDinLength(Playlist);
    currentLagu tmp;
    for(int i = 0; i < n; i ++) {
        while(!IsListLinierEmpty(Playlist.A[i].DaftarLagu))
            ListLinierDelVFirst(&Playlist.A[i].DaftarLagu, &tmp);
    }
    exit(0);
}

void HelpWW_before() {
    printf("\n");
    printf("=======================[ Menu Help WayangWave ]=======================\n");
    printf("1. START -> Untuk masuk sesi baru.\n");
    printf("2. LOAD <namafile.txt> -> Untuk memulai sesi berdasarkan file konfigurasi.\n");
}

void HelpWW_after() {
    printf("\n");
    printf("=========================================[ Menu Help WayangWave ]=========================================\n");
    printf("1. LIST\n");
    printf("        DEFAULT -> Untuk menampilkan daftar penyanyi, album, dan daftar lagu yang ada di album.\n");
    printf("        PLAYLIST -> Untuk menampilkan daftar playlist.\n");
    printf("2. PLAY\n");
    printf("        SONG -> Untuk memutar lagu yang dipilih.\n");
    printf("        PLAYLIST -> Untuk memutar seluruh satu di playlist yang dipilih.\n");
    printf("3. QUEUE\n");
    printf("        SONG -> Untuk menambahkan lagu yang dipilih ke dalam urutan pemutaran lagu. \n");
    printf("        PLAYLIST -> Untuk menambahkan seluruh lagu di suatu playlist yang dipilih ke dalam urutan pemutaran lagu.\n");
    printf("        SWAP <id1> <id2> -> Untuk menukar urutan pemutaran sebuah lagu.\n");
    printf("        REMOVE -> Untuk menghilangkan lagu yang dipilih dari urutan pemutaran lagu.\n");
    printf("        CLEAR -> Untuk mengosongkan urutan pemutaran lagu.\n");
    printf("4. SONG\n");
    printf("        NEXT -> Untuk memutar lagu berikutnya pada queue.\n");
    printf("        PREVIOUS -> Untuk memutar lagu sebelumnya pada queue.\n");
    printf("5. PLAYLIST -> Untuk melakukan command untuk playlist, yaitu create, add, swap, remove, dan delete.\n");
    printf("        CREATE -> Untuk membuat sebuah playlist baru dan menambahkannya ke daftar playlist.\n");
    printf("        ADD\n");
    printf("                SONG -> Untuk menambahkan lagu ke playlist yang ada.\n");
    printf("                ALBUM -> Untuk menambahkan semua lagu pada suatu album ke playlist yang ada.\n");
    printf("        SWAP <idplaylist> <idlagu1> <idlagu2> -> \n");
    printf("        REMOVE <idplaylist> <n> -> Untuk menghilangkan lagu urutan ke-n pada playlist.\n");
    printf("        DELETE -> Untuk menghapus playlist dan menghilangkan dari daftar playlist.\n");
    printf("        ENHANCE -> Untuk meng-enhance playlist dengan memberikan saran rekomendasi lagu yang dapat ditambahkan.\n");
    printf("6. STATUS -> Untuk menampilkan judul lagu yang sedang diputar, nama playlistnya, beserta dengan queue lagu-lagu berikutnya.\n");
    printf("7. SAVE <namafile.txt> -> Untuk menyimpan state aplikasi terbaru ke dalam sebuah file.\n");
    printf("8. QUIT -> Untuk keluar dari aplikasi WayangWave.\n");
    printf("9. HELP -> Untuk menampilkan daftar pilihan bantuan dan deskripsinya.\n");
}
