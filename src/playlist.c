#include "console.h"
#include <stdio.h>
#include <stdlib.h>

void playlist_create(ArrayDin *Playlist) {
    printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTWORD();
    currentWordTillSC();

    CreateListLinier(&Playlist->A[Playlist->Neff].DaftarLagu);
    Playlist->A[Playlist->Neff - 1].NamaPlaylist = CurrentWord; 
    Playlist->Neff += 1;
    printf("\nOutput: Playlist %s berhasil dibuat!", (Playlist)->A[(Playlist)->Neff].NamaPlaylist.TabWord);
    printf("\nSilahkan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
}

void Playlist_Add_Song(List *Penyanyi, ArrayDin * Playlist) {
    printf("\nDaftar Penyanyi: \n");
    for (int i = 0; i < Penyanyi->ListLength; i++) {
        printf("%s\n", Penyanyi.A[i].NamaPenyanyi);
    }
    printf("Masukkan Nama Penyanyi yang dipilih: ");
    STARTWORD();
    currentWordTillSC();
    boolean exist = ListSearch(Penyanyi, currentWord);
    if (exist) {
        printf("Daftar Album oleh %s : ", currentWord.TabWord);
        printf("Masukkan Judul Album yang dipilih: ");
        for (int i = 0; i < Penyanyi.A[].Album.Count; i++) {

        }
        STARTWORD();
        currentWordTillSC();
        if () {
            printf("Masukkan ID Lagu yang dipilih : ");
            STARTWORD();
            currentWordTillSC();
            if () {
                printf("Masukkan ID Playlist yang dipilih : ");
                STARTWORD();
                currentWordTillSC();
                if () {

                }
                else {

                }
            }
            else {
                printf("ID lagu tidak ada dalam daftar. Silakan coba lagi.", )
            }
        }
        else {
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.", )
        }
    }
    else {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.", )
    }
}

void Playlist_Add_Album(List *Penyanyi, ArrayDin * Playlist) {
    printf("\nDaftar Penyanyi: \n");
    for (int i = 0; i < Penyanyi->ListLength; i++) {
        printf("%s\n", Penyanyi->A[i].NamaPenyanyi);
    }
    printf("Masukkan Nama Penyanyi yang dipilih: ");
    STARTWORD();
    currentWordTillSC();
}

void PlaylistWW_Swap(ArrayDin *Playlist, int id, int x, int y) {

}

void PlaylistWW_Remove(ArrayDin *Playlist, int id, int n) {

}

void PlaylistWW_Delete(ArrayDin *Playlist) {

}




