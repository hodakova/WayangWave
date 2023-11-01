#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/mesinkar/mesinkarakterv2.h"
#include "ADT/mesinkar/mesinkarakterv2.c"

int main() {
    Word test;
    test.Length = 3;
    test.TabWord[0] = '2';
    test.TabWord[1] = '1';
    test.TabWord[2] = '2';
    printf("%d\n", Word2int(test));
}