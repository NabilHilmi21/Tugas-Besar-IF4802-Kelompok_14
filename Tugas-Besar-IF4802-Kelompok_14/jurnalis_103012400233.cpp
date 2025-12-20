#include <iostream>
#include "jurnalis.h"
using namespace std;

void deleteFirst_jurnalis(List_jurnal &L, adrP &P) {
    if (L.first == nullptr) {
        cout << "Belum ada data jurnalis" << endl;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLast_jurnalis(List_jurnal &L, adrP &P) {
    if (L.first == nullptr) {
        cout << "Belum ada data jurnalis" << endl;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.last;
        L.last = P->prev;
        L.last->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfter_jurnalis(List_jurnal &L, adrP prec, adrP &P) {
    if (prec == nullptr) {
        cout << "Data jurnalis tidak ditemukan" << endl;
    } else if (prec->next == nullptr) {
        cout << "Tidak ada data jurnalis setelah " << prec->info.nama << endl;
    } else {
        P = prec->next;
        if (P == L.last) {
            L.last = prec;
            prec->next = nullptr;
        } else {
            prec->next = P->next;
            P->next->prev = prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteJurnalis(List_jurnal &L, adrP P) {
    if (P == nullptr) {
        cout << "Jurnalis tidak ditemukan" << endl;
    } else if (L.first == nullptr) {
        cout << "Data jurnalis kosong" << endl;
    } else if (P == L.first) {
        adrP temp; deleteFirst_jurnalis(L, temp);
    } else if (P == L.last) {
        adrP temp; deleteLast_jurnalis(L, temp);
    } else {
        adrP temp; deleteAfter_jurnalis(L, P->prev, temp);
    }
}

adrP searchJurnalis(List_jurnal L, string nama) {
    adrP P = L.first;
    while (P != nullptr) {
        if (P->info.nama == nama) return P;
        P = P->next;
    }
    return nullptr;
}

adrP searchJurnalisID(List_jurnal L, int jurnalis_id) {
    adrP P = L.first;
    while (P != nullptr) {
        if (P->info.jurnalis_id == jurnalis_id) return P;
        P = P->next;
    }
    return nullptr;
}

void showList_jurnalis(List_jurnal L) {
    adrP P = L.first;
    int i = 1;
    cout << "\nDATA JURNALIS (DLL)\n==========================\n";
    while (P != nullptr) {
        cout << i << ". ID Jurnalis: " << P->info.jurnalis_id << endl;
        cout << "--------------------------------------\n";
        cout << "Nama       : " << P->info.nama << " (" << P->info.jenis_kelamin << ") " << endl;
        cout << "Media      : " << P->info.media << endl;
        cout << "Pengalaman : " << P->info.tahun_pengalaman << " tahun\n\n";
        P = P->next;
        i++;
    }
}
