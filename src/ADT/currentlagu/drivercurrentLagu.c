#include <stdio.h>
#include "currentlagu.h"

int main() {
    currentLagu testLagu;

    // Assigning values to the fields of testLagu
    testLagu.Penyanyi = str2Word("Artist Name");
    testLagu.Album = str2Word("Album Name");
    testLagu.Lagu = str2Word("Song Name");
    testLagu.fromPlaylist = str2Word("Playlist Name");

    // Printing the information of the song
    printInfoLagu(testLagu);

    return 0;
}
