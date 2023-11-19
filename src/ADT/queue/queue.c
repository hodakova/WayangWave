#include "queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai QueueIdxUndef */
/* - Index tail bernilai QueueIdxUndef */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    QueueIdxHead(*q) = QueueIdxUndef;
    QueueIdxTail(*q) = QueueIdxUndef;
}


/* ********* Prototype ********* */
boolean isQueueEmpty(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return QueueIdxHead(q) == QueueIdxUndef && QueueIdxTail(q) == QueueIdxUndef;
}

boolean isQueueFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu QueueIdxTail akan selalu di belakang QueueIdxHead dalam buffer melingkar*/
{
    boolean res;
    if(QueueIdxTail(q) >= QueueIdxHead(q))
        res = QueueIdxTail(q) - QueueIdxHead(q) == QueueCapacity - 1;
    else
        res = QueueIdxHead(q) - QueueIdxTail(q) == 1;
    return res;
}

int QueueLength(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    int res;
    if(isQueueEmpty(q))
        res = 0;
    else if(QueueIdxTail(q) >= QueueIdxHead(q))
        res = QueueIdxTail(q) - QueueIdxHead(q) + 1;
    else
        res = QueueIdxTail(q) - QueueIdxHead(q) + 1 + QueueCapacity;
    return res;
}

void enqueue(Queue *q, QueueElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi QueueTail yang baru, QueueIdxTail "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi QueueTail baru  */
{
    if(isQueueEmpty(*q)) {
        QueueIdxHead(*q) = 0;
        QueueIdxTail(*q) = 0;
    }
    else {
        if(QueueIdxTail(*q) + 1 == QueueCapacity) {
            for(int i = 0; i < QueueLength(*q); i ++)
                (*q).buffer[i] = (*q).buffer[i + QueueIdxHead(*q)];
            QueueIdxTail(*q) -= QueueIdxHead(*q);
            QueueIdxHead(*q) = 0;
        }
        QueueIdxTail(*q) ++;
    }
    QueueTail(*q) = val;
}

void dequeue(Queue *q, QueueElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., QueueIdxHead "mundur";
        q mungkin kosong */
{
    *val = QueueHead(*q);
    if(QueueIdxHead(*q) == QueueIdxTail(*q)) {
        QueueIdxHead(*q) = QueueIdxUndef;
        QueueIdxTail(*q) = QueueIdxUndef;
    }
    else {
        QueueIdxHead(*q) ++;
        QueueIdxHead(*q) %= QueueCapacity;
    }
}