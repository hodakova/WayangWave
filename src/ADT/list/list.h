/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */

#ifndef ADTList1
#define ADTList1

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../map/map.h"

/* Kamus Umum */
#define ListMaxEl 100
#define ListMark 0  /* Nilai tak terdefinisi */
#define ListInvalidIdx -1  /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define ListIdxType int
typedef struct {
	Word NamaPenyanyi;
	Map Album;
} ListElType;

typedef struct {
	ListElType A[ListMaxEl];  /* Memori tempat penyimpanan elemen (container) */
} List;

#define List(i) L.A(i)

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList();
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas ListMaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsListEmpty(List L);
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ListElType ListGet(List L, ListIdxType i);
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void ListSet(List *L, ListIdxType i, ListElType v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int ListLength(List L);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
ListIdxType ListFirstIdx(List L);
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

ListIdxType ListLastIdx(List L);
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxListValid (List L, ListIdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxListEff (List L, ListIdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean ListSearch(List L, Word X);
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void ListInsertFirst(List *L, ListElType X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void ListInsertAt(List *L, ListElType X, ListIdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void ListInsertLast(List *L, ListElType X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void ListDeleteFirst(List *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void ListDeleteAt(List *L, ListIdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void ListDeleteLast(List *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List ListConcat(List L1, List L2);
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */

#endif