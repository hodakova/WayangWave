#ifndef __CURRENTLAGU_H__
#define __CURRENTLAGU_H__

#include "../mesinkata/mesinkata.h"

typedef struct
{
    Word Penyanyi;
    Word Album;
    Word Lagu;
    Word fromPlaylist;
} currentLagu;

void CreateInfoLagu(currentLagu *L);

void printInfoLagu(currentLagu L);

#endif