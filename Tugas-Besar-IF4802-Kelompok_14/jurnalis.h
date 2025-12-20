#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct elmList_Berita; // forward declaration

struct jurnalis {
    string nama, media, jenis_kelamin;
    int jurnalis_id, tahun_pengalaman;
};

typedef jurnalis infotype;
typedef struct elmList_jurnal *adrP;
typedef struct elmList_Berita *adrBerita;

struct elmList_jurnal {
    infotype info;
    adrP prev;
    adrP next;
    adrBerita firstB;   // relasi ke child
};

struct List_jurnal {
    adrP first;
    adrP last;
};
void createList(List_jurnal &L);
adrP createElmP(string nama,
                string media,
                string jenis_kelamin,
                int jurnalis_id,
                int tahun_pengalaman);
void insertFirst_jurnalis(List_jurnal &L, adrP P);
void insertLast_jurnalis(List_jurnal &L, adrP P);
void insertAfter_jurnalis (List_jurnal &L, adrP prec, adrP P);
void deleteFirst_jurnalis(List_jurnal &L, adrP &P);
void deleteLast_jurnalis(List_jurnal &L, adrP &P);
void deleteAfter_jurnalis(List_jurnal &L, adrP prec, adrP &P);
void deleteJurnalis(List_jurnal &L, adrP P);
adrP searchJurnalis(List_jurnal L, string nama);
adrP searchJurnalisID(List_jurnal L, int jurnalis_id);
void showList_jurnalis(List_jurnal L);

#endif // JURNALIS_H_INCLUDED
