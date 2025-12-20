// main.cpp
#include <iostream>
#include <string>
#include "jurnalis.h"
#include "berita.h"

using namespace std;

void main_admin(List_jurnal &L);
void main_user(List_jurnal &L);

int main() {
    List_jurnal L;
    createList(L);
    int pilihan = -1;

    do {
        cout << "\n\t._________________________________________________." << endl;
        cout << "\t|                                                 |" << endl;
        cout << "\t|         SISTEM INFORMASI JURNALISTIK            |" << endl;
        cout << "\t|            MULTI LINKED LIST (1:N)              |" << endl;
        cout << "\t|_________________________________________________|" << endl;
        cout << "\t|                                                 |" << endl;
        cout << "\t|   [1] MENU ADMIN (Manajemen Data Dasar)         |" << endl;
        cout << "\t|   [2] MENU USER  (Implementasi Studi Kasus)     |" << endl;
        cout << "\t|   [0] KELUAR PROGRAM                            |" << endl;
        cout << "\t|_________________________________________________|" << endl;
        cout << "\t Pilih Akses : ";

        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            string ignore;
            getline(cin, ignore);
            cout << "\n\t [!] ERROR: Input tidak Valid! Masukkan angka saja." << endl;
            pilihan = -1;
            continue;
        }

        if (pilihan == 1) {
            main_admin(L);
        } else if (pilihan == 2) {
            main_user(L);
        } else if (pilihan == 0) {
            cout << "\n\t [!] Menutup Program... Sampai Jumpa!" << endl;
        } else {
            cout << "\n\t [!] Pilihan tidak tersedia. Gunakan angka 1, 2, atau 0." << endl;
        }

    } while (pilihan != 0);

    return 0;
}
