#include <iostream>
#include <string>
#include "jurnalis.h"
#include "berita.h"

using namespace std;

void main_user(List_jurnal &L) {
    int pilihan = -1;
    string nama, media, jk, judul, tgl, kat, target;
    int id, exp, jumlah;
    adrP P, tempP;
    adrBerita B, tempB;

    while (pilihan != 0) {
        cout << "\n\t._________________________________________________." << endl;
        cout << "\t|                                                 |" << endl;
        cout << "\t|            MENU USER (STUDI KASUS)              |" << endl;
        cout << "\t|_________________________________________________|" << endl;
        cout << "\t  1. Tambahkan Data Jurnalis (Kondisi ID tidak boleh sama)" << endl;
        cout << "\t  2. Tambahkan Data Berita (Kondisi Pengalaman < 2 thn hanya boleh menambahkan 2 berita)" << endl;
        cout << "\t  3. Hapus Jurnalis (Menghapus Jurnalis yang tidak memiliki Berita)" << endl;
        cout << "\t  4. Hapus Berita (Berdasarkan Kategori)" << endl;
        cout << "\t  5. Cari Berita Berdasarkan Kategori" << endl;
        cout << "\t  6. Tampilkan Jurnalis dan Beritanya" << endl;
        cout << "\t -------------------------------------------------" << endl;
        cout << "\t  0. EXIT KE MENU UTAMA" << endl;
        cout << "\t._________________________________________________." << endl;
        cout << "\t Pilih Opsi (Angka): ";

        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            string ignore;
            getline(cin, ignore);
            cout << "\n\t [!] ERROR: Masukkan angka yang valid!" << endl;
            pilihan = -1;
            continue;
        }

        switch (pilihan) {
            case 1:
                cout << "\n Jumlah jurnalis yang ingin ditambah : ";
                cin >> jumlah;
                for (int i = 0; i < jumlah; i++) {
                    cout << "\n --- Data Jurnalis ke-" << i + 1 << " ---" << endl;
                    cout << " Masukkan ID Jurnalis : ";
                    cin >> id;
                    if (searchJurnalisID(L, id) != nullptr) {
                        cout << " [!] ID " << id << " sudah digunakan, input dibatalkan!" << endl;
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
                        cout << " [SUCCESS] Data berhasil disimpan." << endl;
                    }
                }
                showList_jurnalis(L);
                break;

            case 2:
                cout << "\n ID Jurnalis Penerbit : ";
                cin >> id;
                P = searchJurnalisID(L, id);
                if (P != nullptr) {
                    cout << " Jumlah berita yang ingin ditambah : ";
                    cin >> jumlah;
                    for (int i = 0; i < jumlah; i++) {
                        int currentBerita = countBerita(P);
                        if (P->info.tahun_pengalaman < 2 && currentBerita >= 2) {
                            cout << " [!] Gagal: Jurnalis pengalaman < 2 thn maksimal hanya 2 berita." << endl;
                            break;
                        } else {
                            cout << " Judul Berita [" << i + 1 << "]    : ";
                            cin >> judul;
                            cout << " Tanggal            : ";
                            cin >> tgl;
                            cout << " Kategori           : ";
                            cin >> kat;
                            insertLast_Berita(P, createElmBerita(judul, tgl, kat));
                            cout << " [SUCCESS] Berita berhasil ditambahkan." << endl;
                        }
                    }
                } else {
                    cout << " [!] Jurnalis tidak ditemukan." << endl;
                }
                break;

            case 3:
                cout << "\n --- MENGHAPUS JURNALIS TANPA BERITA ---" << endl;
                tempP = L.first;
                while (tempP != nullptr) {
                    adrP nextP = tempP->next;
                    if (tempP->firstB == nullptr) {
                        cout << " [SYSTEM] Menghapus " << tempP->info.nama << " (Belum menulis berita)." << endl;
                        deleteJurnalis(L, tempP);
                    }
                    tempP = nextP;
                }
                showList_jurnalis(L);
                break;

            case 4:
                cout << "\n Masukkan ID Jurnalis : ";
                cin >> id;
                P = searchJurnalisID(L, id);
                if (P != nullptr) {
                    cout << " Kategori yang ingin dihapus : ";
                    cin >> kat;
                    adrBerita currB = P->firstB;
                    while (currB != nullptr) {
                        adrBerita nextB = currB->next;
                        if (currB->info.kategori == kat) {
                            cout << " [SYSTEM] Menghapus berita: " << currB->info.judul_Berita << endl;
                            deleteBerita(P, currB);
                        }
                        currB = nextB;
                    }
                    showList_Berita(P);
                } else {
                    cout << " [!] Jurnalis tidak ditemukan." << endl;
                }
                break;

            case 5:
                cout << "\n Cari Kategori Berita : ";
                cin >> kat;
                {
                    adrP currP = L.first;
                    bool found = false;
                    while (currP != nullptr) {
                        adrBerita currB = currP->firstB;
                        while (currB != nullptr) {
                            if (currB->info.kategori == kat) {
                                cout << " [FOUND] Berita: " << currB->info.judul_Berita
                                     << " | Penulis: " << currP->info.nama << endl;
                                found = true;
                            }
                            currB = currB->next;
                        }
                        currP = currP->next;
                    }
                    if (!found) {
                        cout << " [!] Tidak ada berita dengan kategori tersebut." << endl;
                    }
                }
                break;

            case 6:
                {
                    int totalJurnal = 0;
                    float sumExp = 0;
                    adrP currP = L.first;
                    cout << "\n --- DAFTAR JURNALIS & BERITA ---" << endl;
                    while (currP != nullptr) {
                        totalJurnal++;
                        sumExp += currP->info.tahun_pengalaman;
                        cout << "\n [" << currP->info.jurnalis_id << "] " << currP->info.nama;
                        cout << " (Jumlah Berita: " << countBerita(currP) << ")" << endl;
                        showList_Berita(currP);
                        currP = currP->next;
                    }
                    cout << "\n --- STATISTIK ---" << endl;
                    cout << " Total Jurnalis      : " << totalJurnal << " orang" << endl;
                    if (totalJurnal > 0) {
                        cout << " Rata-rata Pengalaman: " << (sumExp / totalJurnal) << " tahun" << endl;
                    }
                }
                break;
        }
    }
}
