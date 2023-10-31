#ifndef __CONFIG__
#define __CONFIG__

#include "../mesinkata/mesinkata.h"
#include "../list/list.h"

typedef struct album {
    Word Nama;
    List Lagu;
} Album;

typedef struct penyanyi {
    Word Nama;
    Album Album[MaxEl];
    int M;
} Penyanyi;

typedef struct config {
    Penyanyi Penyanyi[MaxEl];
    int N;
} ListPenyanyi;

extern ListPenyanyi Config;

#endif