#ifndef __USER_H__
#define __USER_H__


#include "../mesinkata/mesinkata.h"
#include "../queue/queue.h"
#include "../set/set.h"
#include "../map/map.h"
#include "../listlinier/listlinier.h"
#include "../currentlagu/currentlagu.h"
#include "../stack/stack.h"
#include "../list/arraydin.h"
#include "../../boolean.h"

#define MaxElTypeUser 10

typedef struct
{
    Word Username;
    currentLagu LaguNow;
    ArrayDin Playlist;
    Queue QueueLagu;
    Stack History;
} ElTypeUser;

typedef struct
{
    int Count;
    ElTypeUser Data[MaxElTypeUser];
} user;

int idxUserExist(user U, Word username);
void CreateUser(user *U);

void Login(user U, int *idxUser);


#endif  