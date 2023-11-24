#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListLinierEmpty (ListLinier L)
/* Mengirim true jika list kosong */
{
    return ListLinierFirst(L) == ListLinierNil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinier (ListLinier *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    ListLinierFirst(*L) = ListLinierNil;
}

/****************** Manajemen Memori ******************/
addressListLinier ListLinierAlokasi (ListLinierInfoType X)
/* Mengirimkan addressListLinier hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressListLinier tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, ListLinierNext(P)=ListLinierNil */
/* Jika alokasi gagal, mengirimkan ListLinierNil */
{
    addressListLinier P = (addressListLinier)malloc(sizeof(ElmtListLinier));
    if(P != ListLinierNil) {
        ListLinierInfo(P) = X;
        ListLinierNext(P) = ListLinierNil;
    }
    return P;
}
void ListLinierDealokasi (addressListLinier *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressListLinier P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressListLinier ListLinierSearch (ListLinier L, ListLinierInfoType X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressListLinier elemen tersebut. */
/* Jika tidak ada, mengirimkan ListLinierNil */
{
    boolean found = false;
    addressListLinier P = ListLinierFirst(L);
    while(P != ListLinierNil && !found) {
        if(isWordEqual(ListLinierInfo(P).Penyanyi, X.Penyanyi) && isWordEqual(ListLinierInfo(P).Album, X.Album) && isWordEqual(ListLinierInfo(P).Lagu, X.Lagu))
            found = true;
        else
            P = ListLinierNext(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void ListLinierInsVFirst (ListLinier *L, ListLinierInfoType X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressListLinier P = ListLinierAlokasi(X);
    if(P != ListLinierNil)
        ListLinierInsertFirst(L, P);
}
void ListLinierInsVLast (ListLinier *L, ListLinierInfoType X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressListLinier P = ListLinierAlokasi(X);
    if(P != ListLinierNil)
        ListLinierInsertLast(L, P);
}

/*** PENGHAPUSAN ELEMEN ***/
void ListLinierDelVFirst (ListLinier *L, ListLinierInfoType *X)
/* I.S. ListLinier L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    addressListLinier P;
    ListLinierDelFirst(L, &P);
    *X = ListLinierInfo(P);
    ListLinierDealokasi(&P);
}
void ListLinierDelVLast (ListLinier *L, ListLinierInfoType *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressListLinier P;
    ListLinierDelLast(L, &P);
    *X = ListLinierInfo(P);
    ListLinierDealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void ListLinierInsertFirst (ListLinier *L, addressListLinier P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressListLinier P sebagai elemen pertama */
{
    ListLinierNext(P) = ListLinierFirst(*L);
    ListLinierFirst(*L) = P;
}
void ListLinierInsertAfter (ListLinier *L, addressListLinier P, addressListLinier Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    ListLinierNext(P) = ListLinierNext(Prec);
    ListLinierNext(Prec) = P;
}
void ListLinierInsertLast (ListLinier *L, addressListLinier P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if(IsListLinierEmpty(*L))
        ListLinierInsertFirst(L, P);
    else {
        addressListLinier last = ListLinierFirst(*L);
        while(ListLinierNext(last) != ListLinierNil)
            last = ListLinierNext(last);
        ListLinierInsertAfter(L, P, last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void ListLinierDelFirst (ListLinier *L, addressListLinier *P)
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* ListLinierFirst element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = ListLinierFirst(*L);
    ListLinierFirst(*L) = ListLinierNext(*P);
    ListLinierNext(*P) = ListLinierNil;
}
void ListLinierDelP (ListLinier *L, ListLinierInfoType X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* ListLinier mungkin menjadi kosong karena penghapusan */
{
    addressListLinier P = ListLinierSearch(*L, X), Prec = ListLinierFirst(*L);
    if(P != ListLinierNil) {
        if(Prec == P)
            ListLinierDelFirst(L, &P);
        else {
            while(ListLinierNext(Prec) != P)
                Prec = ListLinierNext(Prec);
            ListLinierDelAfter(L, &P, Prec);
        } 
        ListLinierDealokasi(&P);
    }
}
void ListLinierDelLast (ListLinier *L, addressListLinier *P)
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    addressListLinier Prec = ListLinierNil, last = ListLinierFirst(*L);
    while(ListLinierNext(last) != ListLinierNil) {
        Prec = last;
        last = ListLinierNext(last);
    }
    *P = last;
    if(Prec == ListLinierNil) // P merupakan addressListLinier element pertama
        ListLinierFirst(*L) = ListLinierNil;
    else
        ListLinierNext(Prec) = ListLinierNil;

}
void ListLinierDelAfter (ListLinier *L, addressListLinier *Pdel, addressListLinier Prec)
/* I.S. ListLinier tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus ListLinierNext(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = ListLinierNext(Prec);
    if(ListLinierNext(Prec) != ListLinierNil) {
        ListLinierNext(Prec) = ListLinierNext(*Pdel);
        ListLinierNext(*Pdel) = ListLinierNil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void ListLinierPrintInfo (ListLinier L)
/* I.S. ListLinier mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
{
    addressListLinier P = ListLinierFirst(L);
    printf("[");
    while(P != ListLinierNil) {
        if(P != ListLinierFirst(L))
            printf(",");
        printInfoLagu(ListLinierInfo(P));
        P = ListLinierNext(P);
    }
    printf("]\n");
}
int ListLinierNbElmt (ListLinier L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    addressListLinier P = ListLinierFirst(L);
    while(P != ListLinierNil) {
        count ++;
        P = ListLinierNext(P);
    }
    return count;
}

/****************** PROSES TERHADAP LIST ******************/
void ListLinierInversList (ListLinier *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    addressListLinier P = ListLinierFirst(*L), Prec = ListLinierNil, loc;
    Prec = ListLinierNext(P);
    while(Prec != ListLinierNil) {
        loc = Prec;
        Prec = ListLinierNext(Prec);
        ListLinierInsertFirst(L, loc);
        ListLinierNext(P) = Prec;
    }
}
boolean isListLinierMember(ListLinier L, ListLinierInfoType Lagu) {
    addressListLinier P = L.ListLinierFirst;
    while(P != ListLinierNil) {
        if(isInfoLaguEqual(ListLinierInfo(P), Lagu))
            return true;
        P = ListLinierNext(P);
    }
    return false;
}

void ListLinierKonkat1 (ListLinier *L1, ListLinier *L2, ListLinier *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    CreateListLinier(L3);
    if(IsListLinierEmpty(*L1))
        ListLinierFirst(*L3) = ListLinierFirst(*L2);
    else {
        addressListLinier lastL1 = ListLinierFirst(*L1);
        ListLinierFirst(*L3) = ListLinierFirst(*L1);
        while(ListLinierNext(lastL1) != ListLinierNil)
            lastL1 = ListLinierNext(lastL1);
        ListLinierNext(lastL1) = ListLinierFirst(*L2);
    }
    CreateListLinier(L1);
    CreateListLinier(L2);
}