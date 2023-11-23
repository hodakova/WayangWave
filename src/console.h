#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "ADT/mesinbaris/mesinbaris.h"
#include "ADT/list/list.h"
#include "ADT/list/arraydin.h"
#include "ADT/currentlagu/currentlagu.h"
#include "ADT/stack/stack.h"
#include "ADT/queue/queue.h"
#include "ADT/listlinier/listlinier.h"
#include "ADT/user/user.h"

void Command_unknown();

void Command_forbidden();

void StartWW(List *Penyanyi, user *U);

void LoadWW(char* dirfile, List *Penyanyi, user *U);

void ListWW_Default(List Penyanyi);

void ListWW_Playlist(user U, int idxUser);

void PlayWW_Song(List Penyanyi, user *U, int idxUser);

void PlayWW_Playlist(user *U, int idxUser);

void QueueWW_Song(List Penyanyi, user *U, int idxUser);

void QueueWW_Playlist(user *U, int idxUser);

void QueueWW_Swap(user *U, int idxUser, int x, int y);

void QueueWW_Remove(user *U, int idxUser, int id);

void QueueWW_Clear(user *U, int idxUser);

void SongWW_Next(user *U, int idxUser);

void SongWW_Previous(user *U, int idxUser);

void PlaylistWW_Create(user *U, int idxUser);

void PlaylistWW_Add_Song(List Penyanyi, user *U, int idxUser);

void PlaylistWW_Add_Album(List Penyanyi, user *U, int idxUser);

void PlaylistWW_Swap(user *U, int idxUser, int id, int x, int y);

void PlaylistWW_Remove(user *U, int idxUser, int id, int n);

void PlaylistWW_Delete(user *U, int idxUser);

void StatusWW(user U, int idxUser);

void SaveWW(char* dirfile, List Penyanyi, user U);

void QuitWW(List Penyanyi, user U);

void HelpWW_before();

void HelpWW_after();

#endif