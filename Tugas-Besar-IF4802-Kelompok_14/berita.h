#ifndef BERITA_H_INCLUDED
#define BERITA_H_INCLUDED
using namespace std;
//struct elmList_jurnal;
//typedef elmList_jurnal *adrP;
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
adrBerita searchBerita(List_jurnal L, string judul_berita);
void showList_Berita(List_jurnal L);

#endif // BERITA_H_INCLUDED

