#ifndef BERITA_H_INCLUDED
#define BERITA_H_INCLUDED

#ifndef BERITA_H_INCLUDED
using namespace std;
struct Berita{
    string judul_Berita, media_Berita, jenis_Berita;
};
typedef Berita infotype_Berita;
typedef struct elmList_Berita *adrB;
struct elmList_Berita{
    infotype info;
    adrB next;
};
struct List_Berita{
    adrB First;
};
adrB createElmBerita(string judul_Berita,
                     string media_Berita,
                     string namaJurnalis,
                     );
void insertFirst_Berita(List_Berita &L, adrB p);
void insertLast_Berita(List_Berita &L, adrB p);
void insert_After(List_Berita &L, adrB p);
void deleteFirst_Berita(List_Berita &L, adrB p);
void deleteAfter_Berita(List_Berita &L, adrB p);
void deleteLast_Berita(List_Berita &L, string judul_berita);
adrB searchBerita(List_Berita &L, adrB p);
void showList_Berita(List_Berita L);
#endif // BERITA_H_INCLUDED

