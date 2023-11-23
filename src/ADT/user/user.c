#include "user.h"

int idxUserExist(user U, Word username){
    for(int i = 0; i < U.Count; i++){
        if (isWordEqual(U.Data[i].Username, username)){
            return i;
        }
    }
    return -1;
}
void CreateUser(user *U){
    Queue QueueLagu; CreateQueue(&QueueLagu);
    Stack History; CreateStack(&History);
    ArrayDin Playlist = MakeArrayDin();
    currentLagu LaguNow; CreateInfoLagu(&LaguNow);

    U->Count = 0;
    CreateQueue(&((*U).Data->QueueLagu));
    CreateStack(&((*U).Data->History));
    CreateInfoLagu(&((*U).Data->LaguNow));
    (*U).Data->Playlist = MakeArrayDin();
}

void Login(user U, int *idxUser){
    printf("Masukkan username user WayangWave : "); STARTWORD(); printf("\n");
    currentWordTillEOL();

    while (idxUserExist(U, currentWord) == -1){
        printf("Tidak ada user dengan username \"%s\"\n", Word2str(currentWord));
        printf("Masukkan username user WayangWave : "); STARTWORD(); printf("\n");
        currentWordTillEOL();
    }
    printf("Berhasil masuk. Selamat datang, \"%s\"!", Word2str(currentWord));
    *idxUser = idxUserExist(U, currentWord);
}

void Logout(int *idxUser){
    *idxUser = -1;
}