#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "ADT/mesinbaris/mesinbaris.h"
#include "ADT/list/list.h"
#include "ADT/list/arraydin.h"
#include "ADT/currentlagu/currentlagu.h"
#include "ADT/stack/stack.h"
#include "ADT/queue/queue.h"
#include "ADT/listlinier/listlinier.h"

void Command_unknown();

void Command_forbidden();

void StartWW(List *Penyanyi);

void LoadWW(char* dirfile, List *Penyanyi, currentLagu *LaguNow, Queue *QueueLagu, Stack *History, ArrayDin *Playlist);

void ListWW_Default(List Penyanyi);

void ListWW_Playlist(ArrayDin Playlist);

void PlayWW_Song(List Penyanyi, Queue *QueueLagu, Stack *History, currentLagu *LaguNow);

void PlayWW_Playlist(ArrayDin Playlist, Queue *QueueLagu, Stack *History, currentLagu *LaguNow);

void QueueWW_Song(List Penyanyi, Queue *QueueLagu);

void QueueWW_Playlist(ArrayDin Playlist, Queue *QueueLagu);

void QueueWW_Swap(Queue *QueueLagu, int x, int y);

void QueueWW_Remove(Queue *QueueLagu, int id);

void QueueWW_Clear(Queue *QueueLagu);

void SongWW_Next(Stack *History, currentLagu *LaguNow, Queue *QueueLagu);

void SongWW_Previous(Stack *History, currentLagu *LaguNow, Queue *QueueLagu);

void PlaylistWW_Create(ArrayDin *Playlist);

void PlaylistWW_Add_Song(List Penyanyi, ArrayDin *Playlist);

void PlaylistWW_Add_Album(List Penyanyi, ArrayDin *Playlist);

void PlaylistWW_Swap(ArrayDin *Playlist, int id, int x, int y);

void PlaylistWW_Remove(ArrayDin *Playlist, int id, int n);

void PlaylistWW_Delete(ArrayDin *Playlist);

void StatusWW(currentLagu LaguNow, Queue QueueLagu);

void SaveWW(char *dirfile, List Penyanyi, currentLagu LaguNow, Queue QueueLagu, Stack History, ArrayDin Playlist);

void QuitWW();

void HelpWW_before();

void HelpWW_after();

#endif