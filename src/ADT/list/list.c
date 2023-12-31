#include "list.h"

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList() {
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas ListMaxEl */
    List L;
    for (int i = 0; i < ListMaxEl; i ++)
        L.A[i].NamaPenyanyi.Length = ListMark;
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsListEmpty(List L) {
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
    return L.A[0].NamaPenyanyi.Length == ListMark;
}

/* *** Menghasilkan sebuah elemen *** */
ListElType ListGet(List L, ListIdxType i) {
/* Prekondisi : list tidak kosong, i antara ListFirstIdx(T)..ListLastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
    return L.A[i];
}

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void ListSet(List *L, ListIdxType i, ListElType v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
    (*L).A[i] = v;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int ListLength(List L) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
    int i = 0;
    while (L.A[i].NamaPenyanyi.Length != ListMark)
        i++;
    return i;
}

/* *** Selektor INDEKS *** */
ListIdxType ListFirstIdx(List L) {
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
    return 0;
}

ListIdxType ListLastIdx(List L){
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    return ListLength(L) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxListValid (List L, ListIdxType i){
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
    return i >= ListFirstIdx(L) && i < ListMaxEl;
}

boolean IsIdxListEff (List L, ListIdxType i){
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara ListFirstIdx(L)..ListLastIdx(L) */
    return i >= ListFirstIdx(L) && i <= ListLastIdx(L);
}

/* ********** Operasi-operasi ********** */
boolean ListSearch(List L, Word X) {
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara ListFirstIdx(L)..ListLastIdx(L) */
    for(int i = ListFirstIdx(L); i <= ListLastIdx(L); i ++) {
        if(isWordEqual(L.A[i].NamaPenyanyi, X))
            return true;
    }
    return false;
}

void ListInsertFirst(List *L, ListElType X) {
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
    ListInsertAt(L, X, 0);  
}

void ListInsertAt(List *L, ListElType X, ListIdxType i) {
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
    for(int j = ListLastIdx(*L); j >= i; j--)
        (*L).A[j+1] = (*L).A[j];
    (*L).A[i] = X;
}

void ListInsertLast(List *L, ListElType X) {
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
    ListInsertAt(L, X, ListLength(*L));
}

void ListDeleteFirst(List *L) {
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
    ListDeleteAt(L, 0); 
}

void ListDeleteAt(List *L, ListIdxType i) {
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
    for(int j = i; j < ListLastIdx(*L); j ++)
        (*L).A[j] = (*L).A[j+1];
    (*L).A[ListLastIdx(*L)].NamaPenyanyi.Length = ListMark;
}

void ListDeleteLast(List *L) {
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
    ListDeleteAt(L, ListLastIdx(*L));   
}

List ListConcat(List L1, List L2) {
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
    List L3 = MakeList();
    for(int i = 0; i < ListLength(L1); i ++)
        ListInsertLast(&L3, ListGet(L1, i));
    for(int i = 0; i < ListLength(L2); i ++)
        ListInsertLast(&L3, ListGet(L2, i));
    return L3; 
}