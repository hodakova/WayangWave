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

void QueueWW_Song();

void QueueWW_Playlist();

void QueueWW_Swap();

void QueueWW_Remove();

void QueueWW_Clear();

void SongWW_Next();

void SongWW_Previous();

void PlaylistWW_Create();

void PlaylistWW_Add_Song();

void PlaylistWW_Add_Album();

void PlaylistWW_Swap();

void PlaylistWW_Remove();

void PlaylistWW_Delete();

void StatusWW();

void SaveWW();

void QuitWW();

void HelpWW_before();

void HelpWW_after();

#endif