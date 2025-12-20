#ifndef BERITA_H_INCLUDED
#define BERITA_H_INCLUDED
#include "jurnalis.h"

#include <string>
#include "jurnalis.h"
using namespace std;

struct Berita {
    string judul_Berita, tanggal, kategori;
};

typedef Berita infotype_Berita;
typedef struct elmList_Berita *adrBerita;

struct elmList_Berita {
    infotype_Berita info;
    adrBerita next;
};
adrBerita createElmBerita(string judul_Berita,
                          string tanggal,
                          string kategori);

void insertFirst_Berita(adrP P, adrBerita B);
void insertLast_Berita(adrP P, adrBerita B);
void insert_After(adrP P, adrBerita prec, adrBerita B);
void deleteFirst_Berita(adrP P, adrBerita &B);
void deleteAfter_Berita(adrP P, adrBerita prec, adrBerita &B);
void deleteLast_Berita(adrP P, adrBerita &B);
void deleteBerita(adrP P, adrBerita B);
adrBerita searchBerita(adrP P, string judul);
void showList_Berita(adrP P);
int countBerita(adrP P);


#endif // BERITA_H_INCLUDED
