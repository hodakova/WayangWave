#include "ADT/mesinkar/mesinkarakterv2.c"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/mesinbaris/mesinbaris.c"
#include "ADT/list/list.c"
<<<<<<< Updated upstream
#include "ADT/wayangwave/config.c"
#include "ADT/wayangwave/commands/start.c"
=======
#include "ADT/stack/stack.c"
#include "ADT/queue/queue.c"
#include "ADT/set/set.c"
#include "ADT/map/map.c"
#include "ADT/listlinier/listlinier.c"
#include "ADT/currentlagu/currentlagu.c"
#include "console.c"
#include "art.c"
#include "ADT/user/user.c"
>>>>>>> Stashed changes
#include <stdio.h>


int main() {
<<<<<<< Updated upstream
    STARTWORD("../save/config.txt");
    /*TEST BARIS*/
    for(int i = 0; i < 30; i ++) {
        currentWordTillEOL();
        printWord(currentWord);
        printf("\n");
        ADVBARIS();
    }
    /*TEST WORD
    for(int i = 0; i < 100; i ++) {
        printWord(currentWord);
        printf(" ");
        ADVWORD();
    }*/
=======
    // currentLagu l1, l2;
    // l1.Album = str2Word("album biru");
    // l1.Lagu = str2Word("bleu");
    // l1.Penyanyi = str2Word("asep sadboy");


    // printf("%d\n", l2.fromPlaylist.Length);
    
    // l2.fromPlaylist = str2Word("chills");
    // printf("%d\n", l2.fromPlaylist.Length);
    // l2 = l1;
    // printf("%d\n", l2.fromPlaylist.Length);

    // if(l2.fromPlaylist.Length != 0)
    //     printf("oke\n");
    user U;

    CreateUser(&U);
    printf("y");

>>>>>>> Stashed changes
    return 0;
}