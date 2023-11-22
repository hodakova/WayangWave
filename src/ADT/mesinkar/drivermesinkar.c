#include <stdio.h>
#include "mesinkarakterv2.h"

int main() {
    char* filename = "test.txt";

    if(isFileExist(filename)) {
        printf("File exists, starting to read the file.\n");
        STARTFILE(filename);

        while(!EOP) {
            printf("%c", currentChar);
            ADV();
        }
    } else {
        printf("File does not exist.\n");
    }

    return 0;
}
