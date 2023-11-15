#include "start.h"

void StartWW() {
    int i, j, k;
    STARTWORD("../save/config.txt");
    int temp;
    temp = Word2int(currentWord);// printWord(currentWord); printf("\n");
    ADVBARIS();// ^^ Jumlah Penyanyi ^^

    for (i = 0; i < temp; i++){
        int temp2;
        temp2 = Word2int(currentWord);// printWord(currentWord); printf("\n");
        ADVWORD();// ^^ Jumlah Penyanyi ^^
        Penyanyi.A[i] = currentWord;
        ADVBARIS();
        for (j = 0; j < temp2; j++){
            int temp3;
            temp3 = Word2int(currentWord);
            ADVWORD();
            Album.Elements[j].Key = i;
            Album.Elements[j].Value.NamaAlbum 
        }
    }

    // idUser = 0;
    // dtUsers.U = idUser;
    // dtUsers.User[idUser].Username = str2Word("user1");
    // dtUsers.User[idUser].Password = str2Word("password1");
    // dtUsers.User[idUser].Playlist.P = 0;
    // CreateQueue(&(dtUsers.User[idUser].Queue));
    // CreateStack(&(dtUsers.User[idUser].History));

}