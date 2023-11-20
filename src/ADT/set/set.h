#ifndef set_H
#define set_H
#include <stdio.h>
#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define SetNil 0
#define SetMaxEl 10

typedef Word SetInfoType;
typedef int SetAddress;

typedef struct
{
    SetInfoType Elements[SetMaxEl];
    SetAddress Count;
} Set;

/* Definisi Set S kosong : S.Count = SetNil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateSet(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas SetMaxEl */
/* Ciri Set kosong : count bernilai SetNil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsSetEmpty(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai SetNil */

boolean IsSetFull(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai SetMaxEl */

/* ********** Operator Dasar Set ********* */
void SetInsert(Set *S, SetInfoType Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void SetDelete(Set *S, SetInfoType Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsSetMember(Set S, SetInfoType Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

Set SetUnion(Set s1, Set s2);
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]

Set SetIntersection(Set s1, Set s2);
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]

Set SetSymmetricDifference(Set s1, Set s2);
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]

Set SetSubtract(Set s1, Set s2);
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]

#endif 