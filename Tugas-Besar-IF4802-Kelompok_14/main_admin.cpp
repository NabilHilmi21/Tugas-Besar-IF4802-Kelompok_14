#include <iostream>
#include <string>
#include "jurnalis.h"
#include "berita.h"

using namespace std;

void main_admin(List_jurnal &L) {
    int pilihan = -1;
    string nama, media, jk, judul, tgl, kat, target;
    int id, exp, idBaru;

    adrP P, precP, tempP;
    adrBerita B, precB, tempB;

    while (pilihan != 0) {
        cout << "\n\t._________________________________________________." << endl;
        cout << "\t|                                                 |" << endl;
        cout << "\t|              PANEL ADMIN                        |" << endl;
        cout << "\t|_________________________________________________|" << endl;

        cout << "\t [ PARENT: JURNALIS ]" << endl;
        cout << "\t  1. Insert First        5. Delete Last" << endl;
        cout << "\t  2. Insert Last         6. Delete After" << endl;
        cout << "\t  3. Insert After        7. Search by ID" << endl;
        cout << "\t  4. Delete First        8. Show All Jurnalis" << endl;

        cout << "\t -------------------------------------------------" << endl;

        cout << "\t [ CHILD: BERITA ]" << endl;
        cout << "\t  9.  Insert First       13. Delete Last" << endl;
        cout << "\t  10. Insert Last        14. Delete After" << endl;
        cout << "\t  11. Insert After       15. Search by Judul" << endl;
        cout << "\t  12. Delete First       16. Show Berita Jurnalis" << endl;

        cout << "\t -------------------------------------------------" << endl;
        cout << "\t  0. EXIT KE MENU UTAMA" << endl;
        cout << "\t._________________________________________________." << endl;
        cout << "\t Pilih Opsi (Angka): ";

        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            string dummy;
            getline(cin, dummy);
            cout << "\n\t [!] ERROR: Masukkan ID dalam bentuk angka!" << endl;
            pilihan = -1;
            continue;
        }

        switch (pilihan) {
            case 1:
                cout << "\n--- [ INSERT FIRST JURNALIS ] ---" << endl;
                cout << " Masukkan ID Jurnalis : ";
                cin >> id;
                if (cin.fail()) {
                    cin.clear();
                    string d;
                    getline(cin, d);
                    cout << " [!] Harus angka!\n";
                } else if (searchJurnalisID(L, id)) {
                    cout << " [!] ID tidak valid, sudah digunakan\n";
                } else {
                    cout << " Nama                : ";
                    cin >> nama;
                    cout << " Media               : ";
                    cin >> media;
                    cout << " Jenis Kelamin       : ";
                    cin >> jk;
                    cout << " Tahun Pengalaman    : ";
                    cin >> exp;
                    insertFirst_jurnalis(L, createElmP(nama, media, jk, id, exp));
                    showList_jurnalis(L);
                }
                break;

            case 2:
                cout << "\n--- [ INSERT LAST JURNALIS ] ---" << endl;
                cout << " Masukkan ID Jurnalis : ";
                cin >> id;
                if (cin.fail()) {
                    cin.clear();
                    string d;
                    getline(cin, d);
                    cout << " [!] Harus angka!\n";
                } else if (searchJurnalisID(L, id)) {
                    cout << " [!] ID sudah digunakan\n";
                } else {
                    cout << " Nama                : ";
                    cin >> nama;
                    cout << " Media               : ";
                    cin >> media;
                    cout << " Jenis Kelamin       : ";
                    cin >> jk;
                    cout << " Tahun Pengalaman    : ";
                    cin >> exp;
                    insertLast_jurnalis(L, createElmP(nama, media, jk, id, exp));
                    showList_jurnalis(L);
                }
                break;

            case 3:
                cout << "\n--- [ INSERT AFTER JURNALIS ] ---" << endl;
                cout << " Masukkan ID Acuan   : ";
                cin >> id;
                precP = searchJurnalisID(L, id);
                if (precP) {
                    cout << " Masukkan ID Baru    : ";
                    cin >> idBaru;
                    if (searchJurnalisID(L, idBaru)) {
                        cout << " [!] ID sudah digunakan\n";
                    } else {
                        cout << " Nama                : ";
                        cin >> nama;
                        cout << " Media               : ";
                        cin >> media;
                        cout << " Jenis Kelamin       : ";
                        cin >> jk;
                        cout << " Tahun Pengalaman    : ";
                        cin >> exp;
                        insertAfter_jurnalis(L, precP, createElmP(nama, media, jk, idBaru, exp));
                        showList_jurnalis(L);
                    }
                } else {
                    cout << " [!] ID Acuan tidak ditemukan\n";
                }
                break;

            case 4:
                cout << "\n--- [ DELETE FIRST JURNALIS ] ---" << endl;
                deleteFirst_jurnalis(L, tempP);
                if (tempP) {
                    cout << " [DEL] " << tempP->info.nama << " dihapus.\n";
                    delete tempP;
                    showList_jurnalis(L);
                }
                break;

            case 5:
                cout << "\n--- [ DELETE LAST JURNALIS ] ---" << endl;
                deleteLast_jurnalis(L, tempP);
                if (tempP) {
                    cout << " [DEL] " << tempP->info.nama << " dihapus.\n";
                    delete tempP;
                    showList_jurnalis(L);
                }
                break;

            case 6:
                cout << "\n--- [ DELETE AFTER JURNALIS ] ---" << endl;
                cout << " Masukkan ID Acuan   : ";
                cin >> id;
                precP = searchJurnalisID(L, id);
                if (precP) {
                    deleteAfter_jurnalis(L, precP, tempP);
                    if (tempP) {
                        cout << " [DEL] " << tempP->info.nama << " dihapus.\n";
                        delete tempP;
                        showList_jurnalis(L);
                    }
                } else {
                    cout << " [!] ID Acuan tidak ditemukan\n";
                }
                break;

            case 7:
                cout << "\n--- [ SEARCH JURNALIS BY ID ] ---" << endl;
                cout << " Cari ID             : ";
                cin >> id;
                P = searchJurnalisID(L, id);
                if (P) {
                    cout << " [FOUND] " << P->info.nama << " (" << P->info.media << ")\n";
                } else {
                    cout << " [!] Tidak ditemukan\n";
                }
                break;

            case 8:
                cout << "\n--- [ SHOW ALL JURNALIS ] ---" << endl;
                showList_jurnalis(L);
                break;

            case 9:
                cout << "\n--- [ INSERT FIRST BERITA ] ---" << endl;
                cout << " ID Jurnalis Tujuan  : ";
                cin >> id;
                P = searchJurnalisID(L, id);
                if (P) {
                    cout << " Judul Berita        : ";
                    cin >> judul;
                    cout << " Tanggal             : ";
                    cin >> tgl;
                    cout << " Kategori            : ";
                    cin >> kat;
                    insertFirst_Berita(P, createElmBerita(judul, tgl, kat));
                    showList_Berita(P);
                } else {
                    cout << " [!] Jurnalis tidak ditemukan\n";
                }
                break;

            case 10:
                cout << "\n--- [ INSERT LAST BERITA ] ---" << endl;
                cout << " ID Jurnalis Tujuan  : ";
                cin >> id;
                P = searchJurnalisID(L, id);
                if (P) {
                    cout << " Judul Berita        : ";
                    cin >> judul;
                    cout << " Tanggal             : ";
                    cin >> tgl;
                    cout << " Kategori            : ";
                    cin >> kat;
                    insertLast_Berita(P, createElmBerita(judul, tgl, kat));
                    showList_Berita(P);
                } else {
                    cout << " [!] Jurnalis tidak ditemukan\n";
                }
                break;

            case 11:
                cout << "\n--- [ INSERT AFTER BERITA ] ---" << endl;
                cout << " ID Jurnalis         : ";
                cin >> id;
                P = searchJurnalisID(L, id);
                if (P) {
                    cout << " Judul Berita Acuan  : ";
                    cin >> target;
                    precB = searchBerita(P, target);
                    if (precB) {
                        cout << " Judul Baru          : ";
                        cin >> judul;
                        cout << " Tanggal             : ";
                        cin >> tgl;
                        cout << " Kategori            : ";
                        cin >> kat;
                        insert_After(P, precB, createElmBerita(judul, tgl, kat));
                        showList_Berita(P);
                    } else {
                        cout << " [!] Berita acuan tidak ditemukan\n";
                    }
                } else {
                    cout << " [!] Jurnalis tidak ditemukan\n";
                }
                break;

            case 12:
                cout << "\n--- [ DELETE FIRST BERITA ] ---" << endl;
                cout << " ID Jurnalis         : ";
                cin >> id;
                P = searchJurnalisID(L, id);
                if (P) {
                    deleteFirst_Berita(P, tempB);
                    if (tempB) {
                        cout << " [DEL] Berita '" << tempB->info.judul_Berita << "' dihapus.\n";
                        delete tempB;
                        showList_Berita(P);
                    }
                } else {
                    cout << " [!] Jurnalis tidak ditemukan\n";
                }
                break;

            case 13:
                cout << "\n--- [ DELETE LAST BERITA ] ---" << endl;
                cout << " ID Jurnalis         : ";
                cin >> id;
                P = searchJurnalisID(L, id);
                if (P) {
                    deleteLast_Berita(P, tempB);
                    if (tempB) {
                        cout << " [DEL] Berita '" << tempB->info.judul_Berita << "' dihapus.\n";
                        delete tempB;
                        showList_Berita(P);
                    }
                } else {
                    cout << " [!] Jurnalis tidak ditemukan\n";
                }
                break;

            case 14:
                cout << "\n--- [ DELETE AFTER BERITA ] ---" << endl;
                cout << " ID Jurnalis         : ";
                cin >> id;
                P = searchJurnalisID(L, id);
                if (P) {
                    cout << " Judul Berita Acuan  : ";
                    cin >> target;
                    precB = searchBerita(P, target);
                    if (precB) {
                        deleteAfter_Berita(P, precB, tempB);
                        if (tempB) {
                            cout << " [DEL] Berita '" << tempB->info.judul_Berita << "' dihapus.\n";
                            delete tempB;
                            showList_Berita(P);
                        }
                    } else {
                        cout << " [!] Berita acuan tidak ditemukan\n";
                    }
                } else {
                    cout << " [!] Jurnalis tidak ditemukan\n";
                }
                break;

            case 15:
                cout << "\n--- [ SEARCH GLOBAL BERITA ] ---" << endl;
                cout << " Judul dicari        : ";
                cin >> judul;
                tempP = L.first;
                idBaru = 0; // Penanda ditemukan
                while (tempP) {
                    B = searchBerita(tempP, judul);
                    if (B) {
                        cout << " [FOUND] Ada di Jurnalis: " << tempP->info.nama << endl;
                        idBaru = 1;
                    }
                    tempP = tempP->next;
                }
                if (idBaru == 0) cout << " [!] Judul tidak ditemukan di seluruh database.\n";
                break;

            case 16:
                cout << "\n--- [ SHOW BERITA JURNALIS ] ---" << endl;
                cout << " ID Jurnalis         : ";
                cin >> id;
                P = searchJurnalisID(L, id);
                if (P) {
                    cout << " Daftar Berita dari: " << P->info.nama << endl;
                    showList_Berita(P);
                } else {
                    cout << " [!] Jurnalis tidak ditemukan\n";
                }
                break;
        }
    }
}
