#ifndef player
#define player

#include "../mesinkata/mesinkata.h"
#include "../list/list.h"


#define nMax 50

typedef Word Lagu;

typedef struct {
    Word Nama;
    Lagu Lagu[nMax];
    int L;
} Album;

typedef struct {
    Word Nama;
    Album Album[nMax];
    int M;
} Penyanyi;

typedef 

#endif