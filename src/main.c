#include "ADT/mesinkar/mesinkarakterv2.c"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/mesinbaris/mesinbaris.c"
/*#include "ADT/list/arraydin.c"
#include "ADT/list/list.c"
#include "ADT/stack/stack.c"
#include "ADT/queue/queue.c"
#include "ADT/set/set.c"
#include "ADT/map/map.c"
#include "ADT/wayangwave/config.c"
#include "ADT/wayangwave/record.c"
#include "ADT/wayangwave/commands/start.c"*/
#include <stdio.h>

Word currentOp;




int main() {
    
    do{
        STARTWORD();
        currentOp = currentWord;
        if(isWordEqual(currentOp, str2Word("start")))
            printf("o: start\n");
        else
            printf("o: bukan start\n");
    }
    while (!isWordEqual(currentOp, str2Word("exit")));

    return 0;
}