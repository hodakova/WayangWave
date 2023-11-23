#include <stdio.h>
#include "queue.h"

int main() {
    // Create a queue
    Queue q;
    CreateQueue(&q);

    // Check if the queue is empty
    if (isQueueEmpty(q)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }

    // Check the length of the queue
    printf("The length of the queue is %d.\n", QueueLength(q));

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

    // Enqueue the songs
    enqueue(&q, song1);
    enqueue(&q, song2);
    enqueue(&q, song3);

    // Check if the queue is full
    if (isQueueFull(q)) {
        printf("The queue is full.\n");
    } else {
        printf("The queue is not full.\n");
    }

    // Check the length of the queue
    printf("The length of the queue is %d.\n", QueueLength(q));

    return 0;
}
