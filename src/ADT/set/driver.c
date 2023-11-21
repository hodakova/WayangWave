#include <stdio.h>
#include "set.h"

int main() {
    Set s1, s2, s3;
    Word w1, w2, w3, w4;

    // Initialize
    w1 = str2Word("apple");
    w2 = str2Word("banana");
    w3 = str2Word("cherry");
    w4 = str2Word("date");

    // Create sets
    CreateSet(&s1);
    CreateSet(&s2);

    // Insert 
    SetInsert(&s1, w1);
    SetInsert(&s1, w2);
    SetInsert(&s2, w2);
    SetInsert(&s2, w3);

    // Print Initial
    printf("Set 1: ");
    for(int i = 0; i < s1.Count; i++) {
        printWord(s1.Elements[i]);
        printf(" ");
    }
    printf("\n");

    printf("Set 2: ");
    for(int i = 0; i < s2.Count; i++) {
        printWord(s2.Elements[i]);
        printf(" ");
    }
    printf("\n");

    // Union
    s3 = SetUnion(s1, s2);
    printf("Union of Set 1 and Set 2: ");
    for(int i = 0; i < s3.Count; i++) {
        printWord(s3.Elements[i]);
        printf(" ");
    }
    printf("\n");

    // Intersection
    s3 = SetIntersection(s1, s2);
    printf("Intersection of Set 1 and Set 2: ");
    for(int i = 0; i < s3.Count; i++) {
        printWord(s3.Elements[i]);
        printf(" ");
    }
    printf("\n");

    // Symmetric Difference
    s3 = SetSymmetricDifference(s1, s2);
    printf("Symmetric difference of Set 1 and Set 2: ");
    for(int i = 0; i < s3.Count; i++) {
        printWord(s3.Elements[i]);
        printf(" ");
    }
    printf("\n");

    // Subtraction
    s3 = SetSubtract(s1, s2);
    printf("Subtraction of Set 1 and Set 2: ");
    for(int i = 0; i < s3.Count; i++) {
        printWord(s3.Elements[i]);
        printf(" ");
    }
    printf("\n");

    return 0;
}
