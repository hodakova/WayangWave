#include <stdio.h>

int main() {
    FILE* pita = fopen("../save/config.txt", "r");
    char line[100];
    char cur[2];
    while(fgets(cur, sizeof(cur), pita)) {
        printf("%s", cur, cur);
    }
}