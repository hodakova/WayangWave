#include "set.h"

/* Definisi Set S kosong : S.Count = SetNil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateSet(Set *S) {
    S->Count = SetNil;
}

/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas SetMaxEl */
/* Ciri Set kosong : count bernilai SetNil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsSetMember(Set S, SetInfoType Elmt) {
/* Mengembalikan true jika Elmt adalah member dari S */
    boolean found;
    int i=0;
    found = false;

    while (i<S.Count && !found) {
        if (S.Elements[i] == Elmt) {
            found = true;
        }
        else {
            i++;
        }
    }

    return found;
}

boolean IsSetEmpty(Set S) {
    return (S.Count==SetNil);
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai SetNil */

boolean IsSetFull(Set S) {
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai SetMaxEl */
    return (S.Count==SetMaxEl);
}
/* ********** Operator Dasar Set ********* */
void SetInsert(Set *S, SetInfoType Elmt) {
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
    S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
    if (S->Count == SetNil) {
        S->Elements[0] = Elmt;
        S->Count = 1;
    }
    else {
        if (!IsSetMember(*S, Elmt)) {
            if (S->Count != SetMaxEl) {
                S->Elements[S->Count] = Elmt;
                S->Count = S->Count + 1;
            }
        }
    }
}

void SetDelete(Set *S, SetInfoType Elmt) {
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
    boolean found;
    int i=0, j;
    found = false;
    if (IsSetMember(*S, Elmt)) {
        while (i<=S->Count && !found) {
            if (S->Elements[i] == Elmt) {
                for (j=i; j<SetMaxEl-1; j++) {
                    S->Elements[j] = S->Elements[j+1];
                }
                if (S->Count==1) {
                    S->Count = SetNil;
                }
                else {
                    S->Count--;
                }
                found = true;
            }
            else {
                i++;
            }
        }
    }
}

Set SetUnion(Set s1, Set s2) {
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]
    Set s3;
    int i=0;
    int j=0;

    CreateSet(&s3);

    for (i; i<s1.Count; i++) {
        SetInsert(&s3, s1.Elements[i]);
    }

    for (j; j<s2.Count; j++) {
        SetInsert(&s3, s2.Elements[j]);
    }

    return s3;
}

Set SetIntersection(Set s1, Set s2) {
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]
    Set s3;
    int i=0;
    CreateSet(&s3);

    for (i; i<s1.Count; i++) {
        if (IsSetMember(s2, s1.Elements[i])) {
            SetInsert(&s3, s1.Elements[i]);
        }
    }

    return s3;
}

Set SetSymmetricDifference(Set s1, Set s2) {
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]
    Set s3;
    int i=0;
    int j=0;

    CreateSet(&s3);

    for (i; i<s1.Count; i++) {
        if (!IsSetMember(s2, s1.Elements[i])) {
            SetInsert(&s3, s1.Elements[i]);
        }
    }

    for (j; j<s2.Count; j++) {
        if (!IsSetMember(s1, s2.Elements[j])) {
            SetInsert(&s3, s2.Elements[j]);
        }
    }

    return s3;
}

Set SetSubtract(Set s1, Set s2) {
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]
    Set s3;
    int i=0;
    CreateSet(&s3);

    for (i; i<s1.Count; i++) {
        if (!IsSetMember(s2, s1.Elements[i])) {
            SetInsert(&s3, s1.Elements[i]);
        }
    }

    return s3;
}