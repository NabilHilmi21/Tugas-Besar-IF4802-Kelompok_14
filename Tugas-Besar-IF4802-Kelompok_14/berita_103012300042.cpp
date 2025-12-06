#include <iostream>
#include "berita.h"
#include "jurnalis.h"
using namespace std;

adrBerita createElmBerita(string judul_Berita,
                          string tanggal,
                          string kategori)
{
    adrBerita B = new elmList_Berita;

    B->info.judul_Berita = judul_Berita;
    B->info.tanggal = tanggal;
    B->info.kategori = kategori;

    B->next = nullptr;

    return B;
}

void insertFirst_Berita(adrP P, adrBerita B){
    if (P->firstB == nullptr){
        P->firstB = B;
    } else {
        B->next = P->firstB;
        P->firstB = B;
    }
}

void insertLast_Berita(adrP P, adrBerita B){
    if (P->firstB == nullptr){
        P->firstB = B;
    } else {
        adrBerita Q = P->firstB;
        while (Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = B;
    }
}

void insert_After(adrP P, adrBerita prec, adrBerita B){
    if (prec == nullptr){
        cout << "Berita sebelumnya tidak ditemukan" << endl;
    } else {
        B->next = prec->next;
        prec->next = B;
    }
}
void deleteFirst_Berita(adrP P, adrBerita &B){
    if (P->firstB == nullptr){
        cout << "Tidak ada berita" << endl;
    } else {
        B = P->firstB;
        P->firstB = B->next;
        B->next = nullptr;
    }
}

void deleteLast_Berita(adrP P, adrBerita &B){
    if (P->firstB == nullptr){
        cout << "Tidak ada berita" << endl;
    } else if (P->firstB->next == nullptr){
        B = P->firstB;
        P->firstB = nullptr;
    } else {
        adrBerita Q = P->firstB;
        while (Q->next->next != nullptr){
            Q = Q->next;
        }
        B = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfter_Berita(adrP P, adrBerita prec, adrBerita &B){
    if (prec == nullptr || prec->next == nullptr){
        cout << "Tidak dapat menghapus" << endl;
    } else {
        B = prec->next;
        prec->next = B->next;
        B->next = nullptr;
    }
}

void deleteBerita(adrP P, adrBerita B){
    if (B == nullptr){
        cout << "Berita tidak ditemukan" << endl;
    } else if (P->firstB == B){
        adrBerita temp;
        deleteFirst_Berita(P, temp);
    } else {
        adrBerita Q = P->firstB;
        while (Q != nullptr && Q->next != B){
            Q = Q->next;
        }
        if (Q != nullptr){
            adrBerita temp;
            deleteAfter_Berita(P, Q, temp);
        }
    }
}
adrBerita searchBerita(List_jurnal L, string judul_berita){
    adrP P = L.first;
    while (P != nullptr){
        adrBerita B = P->firstB;
        while (B != nullptr){
            if (B->info.judul_Berita == judul_berita){
                return B;
            }
            B = B->next;
        }
        P = P->next;
    }
    return nullptr;
}
void showList_Berita(List_jurnal L){
    adrP P = L.first;
    cout << "\n=== DATA BERITA ===\n";

    while (P != nullptr){
        cout << "\nJurnalis: " << P->info.nama << endl;
        cout << "--------------------------------\n";

        adrBerita B = P->firstB;

        if (B == nullptr){
            cout << "Tidak ada berita.\n";
        }

        while (B != nullptr){
            cout << "Judul      : " << B->info.judul_Berita << endl;
            cout << "Tanggal    : " << B->info.tanggal << endl;
            cout << "Kategori   : " << B->info.kategori << endl;
            cout << endl;

            B = B->next;
        }

        P = P->next;
    }
}
