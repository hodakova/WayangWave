#include <stdio.h>
#include "mesinbaris.h"

int main() {
        // File path
    char fileAddress[] = "input.txt";

    // pilih jika ingin membaca dari file atau dari terminal
    STARTWORDFILE(fileAddress);
    // atau
    //STARTWORD();

    // Process lines until the end of the input
    while (!isEndWord()) {
        // Print the current word until End Of Line
        printf("Current Word Till EOL: ");
        currentWordTillEOL();
        printWord(currentWord);
        printf("\n");

        // adv ke baris selanjutnya
        ADVBARIS();
    }

    return 0;
}