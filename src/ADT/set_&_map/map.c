#include "map.h"

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M) {
    M->Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M) {
    return (M.Count==Nil);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M) {
        return (M.Count==MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */

/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v) {
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    int i=0;

    if (IsEmpty(*M)) {
        M->Count = 1;
        M->Elements[0].Key = k;
        M->Elements[0].Value = v;
    }
    else {
        if (!IsMember(*M, k)) {
            M->Elements[M->Count].Value = v;
            M->Elements[M->Count].Key = k;
            M->Count++;
            }
        }
}


void Delete(Map *M, keytype k) {
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
    int i=0, j;
    boolean found;
    found = false;
    
    if (IsMember(*M, k)) {
        while (i<M->Count && !found) {
            if (M->Elements[i].Key == k) {
                    found = true;
            }
            else {
                i++;
            }     
        }

        for (j=i; j<M->Count-1; j++) {
            M->Elements[j].Key = M->Elements[j+1].Key;
            M->Elements[j].Value= M->Elements[j+1].Value;
        }
        M->Count--;
    }
}


boolean IsMember(Map M, keytype k) {
/* Mengembalikan true jika k adalah member dari M */
    int i=0;
    boolean found;
    found = false;

    while (i<M.Count && !found) {
        if (M.Elements[i].Key == k) {
            found = true;
        }
        else {
            i++;
        }
    }
    return found;
}

void printMap(Map M) {
    int i;
    for (i=0; i<M.Count; i++) {
        printf("Key:%d | Value: %d", M.Elements[i].Key, M.Elements[i].Value);
        printf("\n");
    }
}