#include "console.h"
#include <stdio.h>
#include <stdlib.h>
void playlist_create(ArrayDin *playlist) {
   printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTWORD();
    currentWordTillSC();
    CreateEmpty(&(Playlist)->A[(Playlist)->Neff]);
    (Playlist)->Nama[(Playlist)->Neff] = playlist_name;
    (Playlist)->Neff += 1;
    printf("\nOutput: Playlist %s berhasil dibuat!", playlist_name.TabWord);
    printf("\nSilahkan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
}

void playlist_add_song(ArrayDin * playlist) {

}

void playlist_add_album(ArrayDin * playlist) {

}



