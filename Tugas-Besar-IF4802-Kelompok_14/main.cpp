#include <iostream>
#include "jurnalis.h"

using namespace std;

int main(){
    string nama, media, jenis_kelamin;
    int jurnalis_id = 0;
    int tahun_pengalaman = 0;

    adrP P;
    List_jurnal L;

    createList(L);

    for (int i = 0; i < 3;){
        cout << "Input data jurnalis: " << endl;
        cout << "==========================" << endl;

        cout << "Nama: ";
        cin >> nama;

        cout << "Media: ";
        cin >> media;

        cout << "Jenis Kelamin: ";
        cin >> jenis_kelamin;

        cout << "ID Jurnalis: ";
        cin >> jurnalis_id;

        if (searchJurnalisID(L, jurnalis_id) == nullptr){
            cout << "Tahun pengalaman: ";
            cin >> tahun_pengalaman;

            P = createElmP(nama, media, jenis_kelamin, jurnalis_id, tahun_pengalaman);
            insertLast_jurnalis(L, P);

            cout << endl;
            i++;
        } else {
            cout << "Jurnalis dengan ID itu sudah ada, input lagi" << endl;
            cout << endl;
        }

    }

    showList_jurnalis(L);

    cout << "Hapus jurnalis berdasarkan nama: ";
    cin >> nama;

    deleteJurnalis(L, searchJurnalis(L, nama));

    showList_jurnalis(L);

    return 0;
}
