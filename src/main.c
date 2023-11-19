#include "ADT/mesinkar/mesinkarakterv2.c"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/mesinbaris/mesinbaris.c"
#include "ADT/list/arraydin.c"
#include "ADT/list/list.c"
#include "ADT/stack/stack.c"
#include "ADT/queue/queue.c"
#include "ADT/set/set.c"
#include "ADT/map/map.c"
#include "ADT/wayangwave/console.c"
#include <stdio.h>

Word currentOp;
List Penyanyi;

int main() {
    
    do{
        STARTWORD();
        currentOp = currentWord;
        if(isWordEqual(currentOp, str2Word("START"))) {
            printf("Mulai start\n");
            StartWW(&Penyanyi);
            printWord(Penyanyi.A[0].NamaPenyanyi);
            printf("\n");
            }
        else
            printf("o: bukan start\n");
    }
    while(!isWordEqual(currentOp, str2Word("exit")));

    return 0;
}