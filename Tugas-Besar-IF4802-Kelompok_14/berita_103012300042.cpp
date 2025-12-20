#include <iostream>
#include "berita.h"
#include "jurnalis.h"
using namespace std;

void deleteFirst_Berita(adrP P, adrBerita &B) {
    if (P->firstB == nullptr) {
        cout << "Tidak ada berita" << endl;
    } else {
        B = P->firstB;
        P->firstB = B->next;
        B->next = nullptr;
    }
}

void deleteLast_Berita(adrP P, adrBerita &B) {
    if (P->firstB == nullptr) {
        cout << "Tidak ada berita" << endl;
    } else if (P->firstB->next == nullptr) {
        B = P->firstB;
        P->firstB = nullptr;
    } else {
        adrBerita Q = P->firstB;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        B = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfter_Berita(adrP P, adrBerita prec, adrBerita &B) {
    if (prec == nullptr || prec->next == nullptr) {
        cout << "Tidak dapat menghapus" << endl;
    } else {
        B = prec->next;
        prec->next = B->next;
        B->next = nullptr;
    }
}

void deleteBerita(adrP P, adrBerita B) {
    if (B == nullptr) {
        cout << "Berita tidak ditemukan" << endl;
    } else if (P->firstB == B) {
        adrBerita temp;
        deleteFirst_Berita(P, temp);
    } else {
        adrBerita Q = P->firstB;
        while (Q != nullptr && Q->next != B) {
            Q = Q->next;
        }
        if (Q != nullptr) {
            adrBerita temp;
            deleteAfter_Berita(P, Q, temp);
        }
    }
}

adrBerita searchBerita(adrP P, string judul) {
    adrBerita B = P->firstB;
    while (B != nullptr) {
        if (B->info.judul_Berita == judul) return B;
        B = B->next;
    }
    return nullptr;
}

void showList_Berita(adrP P) {
    adrBerita B = P->firstB;
    if (B == nullptr) {
        cout << "Tidak ada berita\n";
        return;
    }
    while (B != nullptr) {
        cout << "Judul    : " << B->info.judul_Berita << endl;
        cout << "Tanggal  : " << B->info.tanggal << endl;
        cout << "Kategori : " << B->info.kategori << endl << endl;
        B = B->next;
    }
}

int countBerita(adrP P) {
    int count = 0;
    adrBerita B = P->firstB;
    while (B != nullptr) {
        count++;
        B = B->next;
    }
    return count;
}
