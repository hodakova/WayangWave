/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressListLinier dengan pointer */
/* ListLinierInfoType adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "../../boolean.h"
#include "../currentlagu/currentlagu.h"

#define ListLinierNil NULL

typedef currentLagu ListLinierInfoType;
typedef struct tElmtListLinier *addressListLinier;
typedef struct tElmtListLinier { 
	ListLinierInfoType ListLinierInfo;
	addressListLinier ListLinierNext;
} ElmtListLinier;
typedef struct {
	addressListLinier ListLinierFirst;
} ListLinier;

/* Definisi list : */
/* ListLinier kosong : ListLinierFirst(L) = ListLinierNil */
/* Setiap elemen dengan addressListLinier P dapat diacu ListLinierInfo(P), ListLinierNext(P) */
/* Elemen terakhir list : jika addressnya Last, maka ListLinierNext(Last)=ListLinierNil */
#define ListLinierInfo(P) (P)->ListLinierInfo
#define ListLinierNext(P) (P)->ListLinierNext
#define ListLinierFirst(L) ((L).ListLinierFirst)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListLinierEmpty (ListLinier L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinier (ListLinier *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressListLinier ListLinierAlokasi (ListLinierInfoType X);
/* Mengirimkan addressListLinier hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressListLinier tidak nil, dan misalnya */
/* menghasilkan P, maka ListLinierInfo(P)=X, ListLinierNext(P)=ListLinierNil */
/* Jika alokasi gagal, mengirimkan ListLinierNil */
void ListLinierDealokasi (addressListLinier *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressListLinier P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressListLinier ListLinierSearch (ListLinier L, ListLinierInfoType X);
/* Mencari apakah ada elemen list dengan ListLinierInfo(P)= X */
/* Jika ada, mengirimkan addressListLinier elemen tersebut. */
/* Jika tidak ada, mengirimkan ListLinierNil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void ListLinierInsVFirst (ListLinier *L, ListLinierInfoType X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void ListLinierInsVLast (ListLinier *L, ListLinierInfoType X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void ListLinierDelVFirst (ListLinier *L, ListLinierInfoType *X);
/* I.S. ListLinier L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai ListLinierInfo disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void ListLinierDelVLast (ListLinier *L, ListLinierInfoType *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai ListLinierInfo disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void ListLinierInsertFirst (ListLinier *L, addressListLinier P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressListLinier P sebagai elemen pertama */
void ListLinierInsertAfter (ListLinier *L, addressListLinier P, addressListLinier Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void ListLinierInsertLast (ListLinier *L, addressListLinier P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void ListLinierDelFirst (ListLinier *L, addressListLinier *P);
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* ListLinierFirst element yg baru adalah suksesor elemen pertama yang lama */
void ListLinierDelP (ListLinier *L, ListLinierInfoType X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan ListLinierInfo(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan ListLinierInfo(P)=X, maka list tetap */
/* ListLinier mungkin menjadi kosong karena penghapusan */
void ListLinierDelLast (ListLinier *L, addressListLinier *P);
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void ListLinierDelAfter (ListLinier *L, addressListLinier *Pdel, addressListLinier Prec);
/* I.S. ListLinier tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus ListLinierNext(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void ListLinierPrintInfo (ListLinier L);
/* I.S. ListLinier mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int ListLinierNbElmt (ListLinier L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
boolean isListLinierMember(ListLinier L, ListLinierInfoType Lagu);

/****************** PROSES TERHADAP LIST ******************/
void ListLinierInversList (ListLinier *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
void ListLinierKonkat1 (ListLinier *L1, ListLinier *L2, ListLinier *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif