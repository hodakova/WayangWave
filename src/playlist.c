#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mesinbaris/mesinbaris.h"
#include "ADT/list/arraydin.h"
#include "ADT/listlinier/listlinier.h"
#include "playlist.h"

void playlist_create(ArrayDin *Playlist) {
    printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTWORD();
    currentWordTillSC();
    CreateEmpty(&(Playlist)->A[(Playlist)->Neff]);
    (Playlist)->Nama[(Playlist)->Neff] = playlist_name;
    (Playlist)->Neff += 1;
    printf("\nOutput: Playlist %s berhasil dibuat!", playlist_name.TabWord);
    printf("\nSilahkan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
}

void playlist_add_song(ArrayDin *Playlist, List *Penyanyi) {

}

void playlist_add_album(ArrayDin *Playlist, List *Penyanyi) {

}



