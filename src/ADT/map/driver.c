#include <stdio.h>
#include "map.h"

int main() {
    Map M;
    MapKeyType k1 = 1, k2 = 2, k3 = 3;
    MapValueType v1, v2, v3;

    // Initialize some values
    v1.NamaAlbum = str2Word("Album1");
    v2.NamaAlbum = str2Word("Album2");
    v3.NamaAlbum = str2Word("Album3");

    // Create a map
    CreateMap(&M);

    // Insert key-value pairs into the map
    MapInsert(&M, k1, v1);
    MapInsert(&M, k2, v2);
    MapInsert(&M, k3, v3);

    // Print the map
    printMap(M);

    // Test MapValue
    printf("Value for key 1: ");
    printWord(MapValue(M, k1).NamaAlbum);
    printf("\n");

    // Test MapDelete
    MapDelete(&M, k2);
    printf("After deleting key 2: ");
    printMap(M);

    return 0;
}
