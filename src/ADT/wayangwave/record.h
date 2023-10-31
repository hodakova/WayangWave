#ifndef __RECORD__
#define __RECORD__

#include "../mesinkata/mesinkata.h"
#include "../queue/queue.h"
#include "../stack/stack.h"
#include "../list/arraydin.h"

typedef Queue RecordQueue;
typedef Stack RecordHistory;

typedef struct playlist {
    Word Nama;
    ArrayDin Record;
} Playlist;
typedef struct recordplaylist {
    Playlist* Playlist[MaxEl];
    int P;
} RecordPlaylist;

/*
typedef struct user {
    Word Username;
    Word Password;
    RecordHistory History;
    RecordQueue Queue;
    RecordPlaylist Playlist;
} User;
typedef struct users {
    User* User[MaxEl];
    int U;
} Users;
*/

#endif