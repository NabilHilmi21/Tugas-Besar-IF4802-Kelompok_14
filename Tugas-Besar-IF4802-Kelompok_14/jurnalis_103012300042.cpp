#include <iostream>
#include "jurnalis.h"
using namespace std;

void createList(List_jurnal &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrP createElmP(string nama, string media, string jenis_kelamin, int jurnalis_id, int tahun_pengalaman) {
    adrP P = new elmList_jurnal;
    P->info.nama = nama;
    P->info.media = media;
    P->info.jenis_kelamin = jenis_kelamin;
    P->info.jurnalis_id = jurnalis_id;
    P->info.tahun_pengalaman = tahun_pengalaman;
    P->next = nullptr;
    P->prev = nullptr;
    P->firstB = nullptr;
    return P;
}

void insertFirst_jurnalis(List_jurnal &L, adrP P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast_jurnalis(List_jurnal &L, adrP P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfter_jurnalis(List_jurnal &L, adrP prec, adrP P) {
    if (prec == nullptr) {
        cout << "Jurnalis tidak ditemukan" << endl;
    } else if (prec == L.last) {
        insertLast_jurnalis(L, P);
    } else {
        P->next = prec->next;
        prec->next->prev = P;
        P->prev = prec;
        prec->next = P;
    }
}
