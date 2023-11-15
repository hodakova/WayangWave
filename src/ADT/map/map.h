#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define MapNil 0
#define MapMaxEl 10
#define MapUndefined -999

// typedef int bool;
typedef int MapKeyType;
typedef int MapValueType;
typedef int MapAddress;

typedef struct
{
	MapKeyType Key;
	MapValueType Value;
} MapInfotype;

typedef struct
{
	MapInfotype Elements[MapMaxEl];
	MapAddress Count;
} Map;

/* Definisi Map M kosong : M.Count = MapNil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MapMaxEl */
/* Ciri Map kosong : count bernilai MapNil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmpty(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai MapNil */

boolean IsMapFull(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MapMaxEl */

/* ********** Operator Dasar Map ********* */
MapValueType MapValue(Map M, MapKeyType k);
/* Mengembalikan nilai MapValueTdengan key k dari MapA */

void MapInsert(Map *M, MapKeyType k, MapValueType v);
/* Menambahkan Elmt MapVabagTi elemen Map M. */
/* I.S. M mungkin koMapAong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void MapDelete(Map *M, MapKeyType k);
/* Menghapus Elmt daMapVa MaT M. */
/* I.S. M tidak kMapAsong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMapMember(Map M, MapKeyType k);
/* Mengembalikan true jiMapVa k Tdalah member dari MapA */

void printMap(Map M);

#endif