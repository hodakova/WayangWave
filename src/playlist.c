#include "console.h"
#include <stdio.h>
#include <stdlib.h>

void playlist_create(ArrayDin *Playlist) {
   printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTWORD();
    currentWordTillSC();
    CreateEmpty(&(Playlist)->DaftarLagu[(Playlist)->Neff]);
    (Playlist)->Neff += 1;
    printf("\nOutput: Playlist %s berhasil dibuat!", (Playlist)->NamaPlaylist[(Playlist)->Neff].TabWord);
    printf("\nSilahkan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
}

void playlist_add_song(ArrayDin * playlist) {

}

void playlist_add_album(ArrayDin * playlist) {

}



