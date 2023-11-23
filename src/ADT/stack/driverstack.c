#include <stdio.h>
#include "stack.h"

int main() {
    // Create a stack
    Stack S;
    CreateStack(&S);

    // Create some songs
    currentLagu song1, song2, song3;

    song1.Penyanyi = str2Word("Artist 1");
    song1.Album = str2Word("Album 1");
    song1.Lagu = str2Word("Song 1");
    song1.fromPlaylist = str2Word("Playlist 1");

    song2.Penyanyi = str2Word("Artist 2");
    song2.Album = str2Word("Album 2");
    song2.Lagu = str2Word("Song 2");
    song2.fromPlaylist = str2Word("Playlist 2");

    song3.Penyanyi = str2Word("Artist 3");
    song3.Album = str2Word("Album 3");
    song3.Lagu = str2Word("Song 3");
    song3.fromPlaylist = str2Word("Playlist 3");

    // Push the songs onto the stack
    Push(&S, song1);
    Push(&S, song2);
    Push(&S, song3);

    // Print the stack
    printStack(S);

    // Pop a song from the stack
    currentLagu poppedSong;
    Pop(&S, &poppedSong);

    // Print the popped song
    printf("Popped song: ");
    printInfoLagu(poppedSong);
    printf("\n");

    // Print the stack after popping
    printStack(S);

    return 0;
}
