#include <stdio.h>
#include "listlinier.h"

int main() {
    // membuat list
    ListLinier myList;
    CreateListLinier(&myList);

    // Test IsListLinierEmpty
    printf("Is the list empty? %s\n", IsListLinierEmpty(myList) ? "Yes" : "No");

    // Test ListLinierInsVFirst and ListLinierInsVLast
    ListLinierInfoType song1 = {"Singer1", "Album1", "Song1"};
    ListLinierInfoType song2 = {"Singer2", "Album2", "Song2"};
    ListLinierInsVFirst(&myList, song1);
    ListLinierInsVLast(&myList, song2);

    // Test ListLinierPrintInfo
    printf("List contents: ");
    ListLinierPrintInfo(myList);

    // Test ListLinierSearch
    ListLinierInfoType searchSong = {"Singer1", "Album1", "Song1"};
    addressListLinier result = ListLinierSearch(myList, searchSong);
    if (result != ListLinierNil) {
        printf("Found the song: ");
        printInfoLagu(ListLinierInfo(result));
        printf("\n");
    } else {
        printf("Song not found.\n");
    }

    // Test ListLinierDelVFirst
    ListLinierInfoType deletedSong;
    ListLinierDelVFirst(&myList, &deletedSong);
    printf("Deleted song: ");
    printInfoLagu(deletedSong);
    printf("\n");

    // Test ListLinierPrintInfo after deletion
    printf("List contents after deletion: ");
    ListLinierPrintInfo(myList);

    // Test ListLinierInversList
    ListLinierInversList(&myList);
    printf("List contents after inversion: ");
    ListLinierPrintInfo(myList);

    // Test ListLinierNbElmt
    printf("Number of elements in the list: %d\n", ListLinierNbElmt(myList));

    // Test ListLinierKonkat1
    ListLinier myList2;
    CreateListLinier(&myList2);
    ListLinierInfoType song3 = {"Singer3", "Album3", "Song3"};
    ListLinierInsVFirst(&myList2, song3);

    ListLinierKonkat1(&myList, &myList2, &myList);
    printf("List contents after concatenation: ");
    ListLinierPrintInfo(myList);

    return 0;
}
