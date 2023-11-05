#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "../mesinkata/mesinkata.h"
#include "../list/list.h"

#define MaxEl 100

typedef struct album {
    Word Nama;
    List Lagu;
    int L;
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

#endif