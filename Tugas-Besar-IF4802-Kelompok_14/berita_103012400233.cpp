#include <iostream>
#include "berita.h"
#include "jurnalis.h"
using namespace std;

adrBerita createElmBerita(string judul_Berita, string tanggal, string kategori) {
    adrBerita B = new elmList_Berita;
    B->info.judul_Berita = judul_Berita;
    B->info.tanggal = tanggal;
    B->info.kategori = kategori;
    B->next = nullptr;
    return B;
}

void insertFirst_Berita(adrP P, adrBerita B) {
    if (P->firstB == nullptr) {
        P->firstB = B;
    } else {
        B->next = P->firstB;
        P->firstB = B;
    }
}

void insertLast_Berita(adrP P, adrBerita B) {
    if (P->firstB == nullptr) {
        P->firstB = B;
    } else {
        adrBerita Q = P->firstB;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = B;
    }
}

void insert_After(adrP P, adrBerita prec, adrBerita B) {
    if (prec == nullptr) {
        cout << "Berita sebelumnya tidak ditemukan" << endl;
    } else {
        B->next = prec->next;
        prec->next = B;
    }
}
