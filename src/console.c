#include "console.h"

void Command_unknown() {
    printf("\nCommand tidak diketahui!\n");
}

void Command_forbidden() {
    printf("\nCommand tidak bisa dieksekusi!\n");
}

void StartWW(List *Penyanyi, user *U) {
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
    (*U).Count = Word2int(currentWord);
    ADVBARIS;
    for (int i = 0; i < (*U).Count; i){
        currentWordTillEOL();
        (*U).Data[i].Username = currentWord;
        ADVBARIS();
    }
}

void LoadWW(char* dirfile, List *Penyanyi, user *U){
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
    (*U).Count = Word2int(currentWord);
    ADVBARIS;
    for (int i = 0; i < (*U).Count; i){
        currentWordTillEOL();
        (*U).Data[i].Username = currentWord;
        ADVBARIS();
        }
    for (int u = 0; u < (*U).Count; i)
    { 
        currentWordTillEOL();
        (*U).Data[u].Username = currentWord;
        ADVBARIS();
        // Current Song
        currentWordTillSC();
        (*U).Data[u].LaguNow.Penyanyi = currentWord; //printWord(LaguNow->Penyanyi); printf("\n");
        ADVWORD();
        currentWordTillSC();
        (*U).Data[u].LaguNow.Album = currentWord;// printWord(currentWord); printf("\n");
        ADVWORD();
        currentWordTillEOL();
        (*U).Data[u].LaguNow.Lagu = currentWord;// printWord(currentWord); printf("\n");
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

            enqueue(&((*U).Data[u].QueueLagu), tmp);

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

            Push(&((*U).Data[u].History), tmp);
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
            CreateListLinier(&(*U).Data[u].Playlist.A[i].DaftarLagu);
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
            ArrayDinInsertLast(&((*U).Data[u].Playlist), arraytmp);
        }
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

void ListWW_Playlist(user U, int idxUser) 
{
    printf("\n");
    printf("Daftar playlist yang kamu miliki:\n");
    if (!IsArrayDinEmpty(U.Data[idxUser].Playlist))
    {
        int x = ArrayDinLength(U.Data[idxUser].Playlist);
        for (int i = 0; i < x; i++) 
        {
        printf("   %d. ", i+1); printWord((U.Data[idxUser].Playlist).A[i].NamaPlaylist); printf("\n");
        }
    }
    else
    {
        printf("Kamu tidak memiliki playlist.\n");
    }

}

void PlayWW_Song(List Penyanyi, user *U, int idxUser) {
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
        printf("Masukkan ID Lagu yang dipilih : "); STARTWORD(); currentWordTillSC();
        int ID = Word2int(currentWord);

        printf("\n");
        if(ID > 0 && ID <= jumlah_lagu) {
            found = true;
            pickl = (Penyanyi).A[j].Album.Elements[a].Value.Lagu.Elements[ID-1];

            //define current song
            (*U).Data[idxUser].LaguNow.Album= picka;
            (*U).Data[idxUser].LaguNow.Penyanyi = pickp;
            (*U).Data[idxUser].LaguNow.Lagu = pickl;
            //mengosongkan queue dan stack
            CreateQueue(&((*U).Data[idxUser].QueueLagu));
            CreateStack(&((*U).Data[idxUser].History));
            printf("Memutar lagu \""); printWord(pickl); printf("\" oleh \""); printWord(pickp); printf("\".\n");

        }
        else {
            printf("ID Playlist tidak valid! Tidak ada lagu dengan ID = %d.\n", ID);
        }
        
    }
}

void PlayWW_Playlist(user *U, int idxUser) {
    printf("\n");
    if(IsArrayDinEmpty((*U).Data[idxUser].Playlist))
        printf("Kamu tidak memiliki playlist.\n");
    else {
        printf("Masukkan ID Playlist: "); STARTWORD(); currentWordTillSC();
        int id = Word2int(currentWord);

        printf("\n");
        if(id > 0 && id <= ArrayDinLength((*U).Data[idxUser].Playlist)) {
            CreateQueue(&((*U).Data[idxUser].QueueLagu));
            CreateStack(&((*U).Data[idxUser].History));

            addressListLinier P = (*U).Data[idxUser].Playlist.A[id-1].DaftarLagu.ListLinierFirst;
            if(P != ListLinierNil) {
                (*U).Data[idxUser].LaguNow = ListLinierInfo(P);
                (*U).Data[idxUser].LaguNow.fromPlaylist = (*U).Data[idxUser].Playlist.A[id-1].NamaPlaylist;
                P = ListLinierNext(P);

                currentLagu Ltmp;
                while(P != ListLinierNil) {
                    Ltmp = ListLinierInfo(P);
                    Ltmp.fromPlaylist = (*U).Data[idxUser].Playlist.A[id-1].NamaPlaylist;
                    enqueue(&((*U).Data[idxUser].QueueLagu), Ltmp);
                    Push(&((*U).Data[idxUser].History), Ltmp);
                    P = ListLinierNext(P);
                }
                (*U).Data[idxUser].History = ReverseStack((*U).Data[idxUser].History);
            }

            printf("Memutar playlist \""); printWord((*U).Data[idxUser].LaguNow.fromPlaylist); printf("\".\n");
        }

        else {
            printf("ID Playlist tidak valid! Tidak ada playlist dengan ID = %d.\n", id);
            printf("Tips: Ketik LIST PLAYLIST untuk melihat ID Playlist!\n");
        }
    }
}

void QueueWW_Song(List Penyanyi, user *U, int idxUser) {
    if(isQueueFull((*U).Data[idxUser].QueueLagu))
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
        enqueue(&((*U).Data[idxUser].QueueLagu), Lagu);
        
        printf("Berhasil menambahkan lagu \""); printWord(Lagu.Lagu); printf("\" oleh \""); printWord(Lagu.Penyanyi); printf("\" ke queue.\n");
    }
}

void QueueWW_Playlist(user *U, int idxUser) {
    if(isQueueFull((*U).Data[idxUser].QueueLagu))
        printf("\nQueue penuh!\n");
    else {
        int id, r, i;
        currentLagu Ltmp;
        addressListLinier P;
        boolean isFull = false;

        printf("\n");
        if(IsArrayDinEmpty((*U).Data[idxUser].Playlist))
            printf("Kamu tidak memiliki playlist.\n");
        else {
            printf("Masukkan ID Playlist: "); STARTWORD(); currentWordTillSC();
            id = Word2int(currentWord) - 1;

            printf("\n");
            if(id >= 0 && id < ArrayDinLength((*U).Data[idxUser].Playlist)) {
                P = (*U).Data[idxUser].Playlist.A[id].DaftarLagu.ListLinierFirst;
                while(P != ListLinierNil && !isFull) {
                    Ltmp = ListLinierInfo(P);
                    Ltmp.fromPlaylist = (*U).Data[idxUser].Playlist.A[id].NamaPlaylist; // penanda dari PlayList mana lagu yg sedang di-play
                    if(!isQueueFull((*U).Data[idxUser].QueueLagu))
                        enqueue(&((*U).Data[idxUser].QueueLagu), Ltmp);
                    else
                        isFull = true;
                    P = ListLinierNext(P);
                }
                
                printf("Berhasil menambahkan playlist \""); printWord((*U).Data[idxUser].Playlist.A[id].NamaPlaylist); printf(" ke queue.\n");
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

void QueueWW_Swap(user *U, int idxUser, int x, int y) {
    boolean isXvalid = false, isYvalid = false;
    int l = QueueLength((*U).Data[idxUser].QueueLagu), iHead = QueueIdxHead((*U).Data[idxUser].QueueLagu);

    if(x > 0 && x <= l)
        isXvalid = true;
    if(y > 0 && y <= l)
        isYvalid = true;


    printf("\n");
    if(isXvalid && isYvalid) {
        currentLagu tmp = ((*U).Data[idxUser].QueueLagu).buffer[y-1+iHead];
        ((*U).Data[idxUser].QueueLagu).buffer[y-1+iHead] = ((*U).Data[idxUser].QueueLagu).buffer[x-1+iHead];
        ((*U).Data[idxUser].QueueLagu).buffer[x-1+iHead] = tmp;

        printf("Lagu \""); printWord(((*U).Data[idxUser].QueueLagu).buffer[y-1+iHead].Lagu); printf("\" berhasil ditukar dengan \""); printWord(tmp.Lagu); printf("\"\n");
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

void QueueWW_Remove(user *U, int idxUser, int id) {
    printf("\n");
    if(id > 0 && id <= QueueLength((*U).Data[idxUser].QueueLagu)) {
        Queue Qtmp; CreateQueue(&Qtmp);
        currentLagu Ltmp, Lrmv;
        int i = 1;

        while(!isQueueEmpty((*U).Data[idxUser].QueueLagu)) {
            dequeue(&((*U).Data[idxUser].QueueLagu), &Ltmp);
            enqueue(&Qtmp, Ltmp);
        }

        while(!isQueueEmpty(Qtmp)) {
            dequeue(&Qtmp, &Ltmp);
            if(i != id)
                enqueue(&((*U).Data[idxUser].QueueLagu), Ltmp);
            else
                Lrmv = Ltmp;
            i ++;
        }

        printf("Lagu \""); printWord(Lrmv.Lagu); printf("\" oleh \""); printWord(Lrmv.Penyanyi); printf("\" telah dihapus dari queue.\n");
    }

    else
        printf("Lagu dengan urutan ke %d tidak ada.\n", id);
}

void QueueWW_Clear(user *U, int idxUser) {
    CreateQueue(&((*U).Data[idxUser].QueueLagu));

    printf("\n");
    printf("Queue berhasil dikosongkan.\n");
}

void SongWW_Next(user *U, int idxUser) {
    if (((*U).Data[idxUser].LaguNow.Lagu.Length != 0))
    {
        if(!isQueueEmpty((*U).Data[idxUser].QueueLagu))
        {
            Push(&((*U).Data[idxUser].History), (*U).Data[idxUser].LaguNow);
            dequeue(&((*U).Data[idxUser].QueueLagu), &((*U).Data[idxUser].LaguNow));
            printf("Memutar lagu selanjutnya\n");
            
            printf("\""); printWord((*U).Data[idxUser].LaguNow.Lagu); printf("\" oleh \""); printWord((*U).Data[idxUser].LaguNow.Penyanyi);printf("\"\n");
        }
        else
        {
            printf("Queue kosong, memutar kembali lagu\n");
            printf("\""); printWord((*U).Data[idxUser].LaguNow.Lagu); printf("\" oleh \""); printWord((*U).Data[idxUser].LaguNow.Penyanyi);printf("\"\n");
        }
    }else
    {
        printf("Queue kosong, Current Lagu kosong\n");
    }
}

void SongWW_Previous(user *U, int idxUser) {
    if(!IsStackEmpty((*U).Data[idxUser].History))
    {
        Queue tempQueue;
        QueueElType temp;
        while(!isQueueEmpty((*U).Data[idxUser].QueueLagu)){
            dequeue(&((*U).Data[idxUser].QueueLagu), &temp);
            enqueue(&tempQueue, temp);
        }
        enqueue(&((*U).Data[idxUser].QueueLagu),((*U).Data[idxUser].LaguNow));
        while(!isQueueEmpty(tempQueue)){
            dequeue(&tempQueue, &temp);
            enqueue(&((*U).Data[idxUser].QueueLagu), temp);
        }
        Pop(&((*U).Data[idxUser].History),&((*U).Data[idxUser].LaguNow));
        printf("Memutar lagu sebelumnya\n");
        printf("\""); printWord((*U).Data[idxUser].LaguNow.Lagu); printf("\" oleh \""); printWord((*U).Data[idxUser].LaguNow.Penyanyi);printf("\"\n");
    }
    else
    {
        printf("Riwayat kosong, memutar kembali lagu\n");
        printf("\""); printWord((*U).Data[idxUser].LaguNow.Lagu); printf("\" oleh \""); printWord((*U).Data[idxUser].LaguNow.Penyanyi);printf("\"\n");
    }
}

void PlaylistWW_Create(user *U, int idxUser) {
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

        ArrayDinInsertLast(&((*U).Data[idxUser].Playlist), el);
        printf("\nOutput: Playlist "); printWord(el.NamaPlaylist); ;printf(" berhasil dibuat!\n");
        printf("\nSilahkan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
    }
    else 
        printf("\nMinimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
}

void PlaylistWW_Add_Song(List Penyanyi, user *U, int idxUser) {
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
            STARTWORD(); currentWordTillSC();
            int idLagu = Word2int(currentWord);
            if (idLagu < laguCount + 1) {
                printf("\nDaftar Playlist Pengguna :\n");
                int playlistCount = ArrayDinLength((*U).Data[idxUser].Playlist);
                for (int i = 0; i < playlistCount; i++) {
                printf("   %d. ", i+1); printWord((*U).Data[idxUser].Playlist.A[i].NamaPlaylist); printf("\n");
                }
                printf("\nMasukkan ID Playlist yang dipilih : ");
                STARTWORD(); currentWordTillSC();
                int idPlaylist = Word2int(currentWord);

                if (idPlaylist < playlistCount + 1) {
                    currentLagu temp;
                    temp.Album = (Penyanyi).A[idPenyanyi].Album.Elements[idAlbum].Value.NamaAlbum;
                    temp.Penyanyi = Penyanyi.A[idPenyanyi].NamaPenyanyi;
                    temp.Lagu = (Penyanyi).A[idPenyanyi].Album.Elements[idAlbum].Value.Lagu.Elements[idLagu - 1];
                    ListLinierInsVLast(&((*U).Data[idxUser].Playlist.A[idPlaylist - 1].DaftarLagu), temp);
                    // ListLinierPrintInfo(Playlist->A[idPlaylist - 1].DaftarLagu);
                    printf("\nLagu dengan judul \""); printWord(temp.Lagu); printf("\" pada album "); printWord(temp.Album); printf(" oleh penyanyi ");  printWord(temp.Penyanyi); printf(" berhasil ditambahkan ke dalam playlist "); printWord((*U).Data[idxUser].Playlist.A[idPlaylist - 1].NamaPlaylist); printf(".\n");
                }
                else {
                    printf("\nID playlist tidak ada dalam daftar, Silakan coba lagi.\n");
                }
            }
            else {
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

void PlaylistWW_Add_Album(List Penyanyi, user *U, int idxUser) {
    printf("\n");
    if(IsArrayDinEmpty((*U).Data[idxUser].Playlist))
        printf("Playlist kosong! Buat playlist terlebih dahulu.\n");
    else {
        int a, b, i, idP, n, m, p, l;
        boolean found;

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
                p = ArrayDinLength((*U).Data[idxUser].Playlist);
                for(i = 0; i < p; i ++) {
                    printf("   %d. ", i+1); printWord((*U).Data[idxUser].Playlist.A[i].NamaPlaylist); printf("\n");
                }

                printf("\n");
                printf("Masukkan ID Playlist yang dipilih : "); STARTWORD(); currentWordTillSC();
                idP = Word2int(currentWord);

                printf("\n");
                if(idP > 0 && idP < p) {
                    l = Penyanyi.A[a].Album.Elements[b].Value.Lagu.Count;
                    for(i = 0; i < l; i ++) {
                        Ltmp.Lagu = Penyanyi.A[a].Album.Elements[b].Value.Lagu.Elements[i];
                        ListLinierInsVLast(&((*U).Data[idxUser].Playlist.A[idP-1].DaftarLagu), Ltmp);
                    }

                    printf("Album dengan judul \""); printWord(Ltmp.Album); printf("\" berhasil ditambahkan ke dalam pada playlist pengguna \""); printWord((*U).Data[idxUser].Playlist.A[idP-1].NamaPlaylist); printf("\".\n");
                }
                else {
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
}

void PlaylistWW_Swap(user *U, int idxUser, int id, int x, int y) {
    printf("\n");
    if(id > 0 && id <= ArrayDinLength((*U).Data[idxUser].Playlist)) {
        boolean xValid = false, yValid = false;
        int i, l = ListLinierNbElmt((*U).Data[idxUser].Playlist.A[id-1].DaftarLagu);

        if(x > 0 && x <= l)
            xValid = true;
        if(y > 0 && x <= l)
            yValid = true;
        
        if(xValid && yValid) {
            // ListLinierPrintInfo(Playlist->A[id-1].DaftarLagu);
            addressListLinier P = (*U).Data[idxUser].Playlist.A[id-1].DaftarLagu.ListLinierFirst, Px, Py;
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
            printf("Berhasil menukar lagu dengan nama \""); printWord(Ltmp.Lagu); printf("\" dengan \""); printWord(ListLinierInfo(Px).Lagu); printf("\" di playlist \""); printWord((*U).Data[idxUser].Playlist.A[id-1].NamaPlaylist); printf("\"\n");
        }
        else {
            printf("Tidak ada lagu dengan ");
            if(!xValid)
                printf("urutan %d", x);
            if(!xValid && !yValid)
                printf(" dan ");
            if(!yValid)
                printf("urutan %d", y);
            printf("di playlist \""); printWord((*U).Data[idxUser].Playlist.A[id-1].NamaPlaylist); printf("\"\n");
        }
    }
    else
        printf("Tidak ada playlist dengan playlist ID %d\n", id);
}

void PlaylistWW_Remove(user *U, int idxUser, int id, int n) {
    printf("\n");
    if(id > 0 && id <= ArrayDinLength((*U).Data[idxUser].Playlist)) {
        if(n > 0 && n <= ListLinierNbElmt((*U).Data[idxUser].Playlist.A[id-1].DaftarLagu)) {
            ListLinierPrintInfo((*U).Data[idxUser].Playlist.A[id-1].DaftarLagu);

            addressListLinier P = (*U).Data[idxUser].Playlist.A[id-1].DaftarLagu.ListLinierFirst, Pdel;
            int i = 1;
            while(i < n-1)
                P = ListLinierNext(P);
            // P = address lagu playlist ke n-1
            
            Pdel = ListLinierNext(P); 
            if(ListLinierNext(ListLinierNext(P)) != ListLinierNil)
                ListLinierNext(P) = ListLinierNext(ListLinierNext(P));
            else
                ListLinierNext(P) = ListLinierNil;

            printf("Lagu \""); printWord(ListLinierInfo(Pdel).Lagu); printf("\" oleh \""); printWord(ListLinierInfo(P).Penyanyi); printf("\" telah dihapus dari playlist \""); printWord((*U).Data[idxUser].Playlist.A[id-1].NamaPlaylist); printf("\"!\n");
            ListLinierDealokasi(&Pdel);

            ListLinierPrintInfo((*U).Data[idxUser].Playlist.A[id-1].DaftarLagu);
        }
        else {
            printf("Tidak ada lagu dengan urutan %d di playlist \"", n); printWord((*U).Data[idxUser].Playlist.A[id-1].NamaPlaylist); printf("\"!\n");
        }
    }
    else
        printf("Tidak ada playlist dengan ID %d.", id);
}

void PlaylistWW_Delete(user *U, int idxUser) {
    printf("\nDaftar Playlist Pengguna :\n");
    int playlistCount = ArrayDinLength((*U).Data[idxUser].Playlist);
    for (int i = 0; i < playlistCount; i++) {
        printf("   %d. ", i+1); printWord((*U).Data[idxUser].Playlist.A[i].NamaPlaylist); printf("\n");
    }
    printf("\nMasukkan ID Playlist yang dipilih: ");
    STARTWORD(); currentWordTillSC();
    int idP = Word2int(currentWord);
    if (idP < playlistCount + 1) {
        Word temp = (*U).Data[idxUser].Playlist.A[idP - 1].NamaPlaylist;
        ArrayDinDeleteAt(&((*U).Data[idxUser].Playlist), idP - 1);
        //PrintArrayDin(*Playlist);
        printf("\nPlaylist dengan ID %d dengan judul \"", idP); printWord(temp); printf("\" berhasil dihapus.\n");
    }
    else {
        printf("\nTidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", idP);
    } 
}

void StatusWW(user U, int idxUser) {
    printf("\n");
    if(U.Data[idxUser].LaguNow.fromPlaylist.Length != 0) {
        printf("Current Playlist : "); printWord(U.Data[idxUser].LaguNow.fromPlaylist); printf("\n");
        printf("\n");
    }

    printf("Now Playing:\n");
    if(!isInfoLaguEmpty(U.Data[idxUser].LaguNow)) {
        printInfoLagu(U.Data[idxUser].LaguNow); printf("\n");
    }
    else
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    
    printf("\n");
    printf("Queue:\n");
    if(isQueueEmpty(U.Data[idxUser].QueueLagu))
        printf("Your queue is empty.\n");
    else {
        int x = QueueLength(U.Data[idxUser].QueueLagu);
        for (int i = QueueIdxHead(U.Data[idxUser].QueueLagu); i <= QueueIdxTail(U.Data[idxUser].QueueLagu); i++) {
            printf("   %d. ", i+1); printInfoLagu(U.Data[idxUser].QueueLagu.buffer[i]); printf("\n");
        }
    }
}

void SaveWW(char* dirfile, List Penyanyi, user U) {
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
    fprintf(file, "%d\n", U.Count);
    for (int i = 0; i < U.Count; i++){
        fprintf(file, "%s\n", U.Data[i].Username);
    }
    for (int i = 0; i < U.Count; i++){
    // LaguNow
        fprintf(file, "%s;%s;%s\n", Word2str(U.Data[i].LaguNow.Penyanyi), Word2str(U.Data[i].LaguNow.Album), Word2str(U.Data[i].LaguNow.Lagu));
        // Queue
        fprintf(file, "%d\n", QueueLength(U.Data[i].QueueLagu));
        if(!isQueueEmpty(U.Data[i].QueueLagu)) {
            for (int i = U.Data[i].QueueLagu.idxHead; i <= U.Data[i].QueueLagu.idxTail; i++){
                fprintf(file, "%s;%s;%s\n",Word2str(U.Data[i].QueueLagu.buffer[i].Penyanyi),Word2str(U.Data[i].QueueLagu.buffer[i].Album),Word2str(U.Data[i].QueueLagu.buffer[i].Lagu));
            }
        }
        // History
        fprintf(file, "%d\n", (U.Data[i].History.TOP+1));
        for (int i = 0; i <= U.Data[i].History.TOP; i++){
            fprintf(file, "%s;%s;%s\n",Word2str(U.Data[i].History.T[i].Penyanyi),Word2str(U.Data[i].History.T[i].Album),Word2str(U.Data[i].History.T[i].Lagu));
        }
        // Playlist
        fprintf(file, "%d\n", U.Data[i].Playlist.Neff);
        for (int i = 0; i < U.Data[i].Playlist.Neff; i++){
            fprintf(file, "%d %s\n", ListLinierNbElmt(U.Data[i].Playlist.A[i].DaftarLagu), Word2str(U.Data[i].Playlist.A[i].NamaPlaylist));
            int n = ListLinierNbElmt(U.Data[i].Playlist.A[i].DaftarLagu);
            for (int j = 0 ;j < n; j++){
                currentLagu temp;
                ListLinierDelVFirst(&U.Data[i].Playlist.A[i].DaftarLagu, &temp);
                fprintf(file, "%s;%s;%s\n", Word2str(temp.Penyanyi), Word2str(temp.Album), Word2str(temp.Lagu));
            }
        }
    }
    fclose(file);
}

void QuitWW(List Penyanyi, user U) {
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
            SaveWW(dirfile, Penyanyi, U);
            printf("\nSave file berhasil disimpan.\n");
        }
        else {
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
        printf("Thank you for using WayangWave!\n");
    }
    else if(isWordEqual(currentWord, str2Word("N")))
    {
        printf("\nKamu keluar dari WayangWave.\n");
        printf("Dadah ^_^/\n");
    }
    exit(0);
}

void HelpWW_before() {
    printf("=======================[ Menu Help WayangWave ]=======================\n");
    printf("1. START -> Untuk masuk sesi baru.\n");
    printf("2. LOAD <namafile.txt> -> Untuk memulai sesi berdasarkan file konfigurasi.\n");
}

void HelpWW_after() {
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
    printf("            CREATE -> Untuk membuat sebuah playlist baru dan menambahkannya ke daftar playlist.\n");
    printf("            ADD\n");
    printf("                SONG -> Untuk menambahkan lagu ke playlist yang ada.\n");
    printf("                ALBUM -> Untuk menambahkan semua lagu pada suatu album ke playlist yang ada.\n");
    printf("            SWAP <idplaylist> <idlagu1> <idlagu2> -> \n");
    printf("            REMOVE <idplaylist> <n> -> Untuk menghilangkan lagu urutan ke-n pada playlist.\n");
    printf("            DELETE -> Untuk menghapus playlist dan menghilangkan dari daftar playlist.\n");
    printf("6. STATUS -> Untuk menampilkan judul lagu yang sedang diputar, nama playlistnya, beserta dengan queue lagu-lagu berikutnya.\n");
    printf("7. SAVE <namafile.txt> -> Untuk menyimpan state aplikasi terbaru ke dalam sebuah file.\n");
    printf("8. QUIT -> Untuk keluar dari aplikasi WayangWave.\n");
    printf("9. HELP -> Untuk menampilkan daftar pilihan bantuan dan deskripsinya.\n");
}
