#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "../mesinbaris/mesinbaris.h"
#include "../list/list.h"
#include "../map/map.h"
#include "../list/arraydin.h"
#include "../currentlagu/currentlagu.h"
#include "../stack/stack.h"
#include "../queue/queue.h"
#include "../listlinier/listlinier.h"

void StartWW(List *Penyanyi);

void LoadWW(char* dirfile, List *Penyanyi, currentLagu *LaguNow, Queue *QueueLagu, Stack *History, ArrayDin *Playlist);

void ListDefaultWW();

void ListPlaylistWW();

void SongNext();

void SongPrevious();
#endif