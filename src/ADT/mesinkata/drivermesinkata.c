#include <stdio.h>
#include "mesinkata.h"

int main() {
    // File path
    char fileAddress[] = "input.txt";

    // pilih jika ingin membaca dari file atau dari terminal
    // STARTWORDFILE(fileAddress);
    // atau
    STARTWORD();

    // Process words until the end of the input
    while (!isEndWord()) {
        // Print the current word
        printf("Current Word: ");
        printWord(currentWord);
        printf("\n");

        // cek isWordEqual
        Word targetWord = str2Word("target");
        if (isWordEqual(currentWord, targetWord)) {
            printf("Found the target word!\n");
        }

        // adv ke kata selanjutnya
        ADVWORD();
    }
    printf("Last Word: ");
    printWord(currentWord);
    printf("\n");

    return 0;
}
