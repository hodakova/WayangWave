#include <stdio.h>
#include "list.h"

int main() {
    List L1 = MakeList();
    List L2 = MakeList();
    ListElType El1, El2;

    // Initialize El1 and El2
    El1.NamaPenyanyi = str2Word("Singer1");
    CreateMap(&El1.Album);
    El2.NamaPenyanyi = str2Word("Singer2");
    CreateMap(&El2.Album);

    // Test ListInsertFirst
    ListInsertFirst(&L1, El1);
    ListInsertFirst(&L2, El2);

    // Test ListInsertLast
    ListInsertLast(&L1, El2);
    ListInsertLast(&L2, El1);

    // Test ListLength
    printf("Length of L1: %d\n", ListLength(L1));  // Should print: 2
    printf("Length of L2: %d\n", ListLength(L2));  // Should print: 2

    // Test ListSearch
    printf("Is 'Singer1' in L1? %s\n", ListSearch(L1, str2Word("Singer1")) ? "Yes" : "No");  // Should print: Yes
    printf("Is 'Singer1' in L2? %s\n", ListSearch(L2, str2Word("Singer1")) ? "Yes" : "No");  // Should print: Yes

    // Test ListConcat
    List L3 = ListConcat(L1, L2);
    printf("Length of L3: %d\n", ListLength(L3));  // Should print: 4

    return 0;
}
