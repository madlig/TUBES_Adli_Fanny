#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#define artis_next(R)  R->artis_next
#define fans_next(R)  R->fans_next
#include <iostream>
#include "artis.h"
#include "fans.h"

using namespace std;

typedef struct elmList_relasi *address_relasi;

struct elmList_relasi {
    address_relasi next;
    address_artis artis_next;
    address_fans fans_next;
};
struct List_relasi {
    address_relasi first;
};

void createList_relasi (List_relasi &L3);
address_relasi alokasi_relasi(address_artis P,address_fans C);
void dealokasi_relasi(address_relasi &P);

void insertFirst_relasi(List_relasi &L3, address_relasi P);
void insertLast_relasi(List_relasi &L3, address_relasi P);
void insertAfter_relasi(List_relasi &L3, address_relasi Prec, address_relasi P);

void deleteFirst_relasi(List_relasi &L3, address_relasi &p);
void deleteLast_relasi(List_relasi &L3, address_relasi &p);
address_relasi findPrec_relasi(List_relasi L3,address_relasi R);
void deleteAfter_relasi(List_relasi &L3, address_relasi Prec, address_relasi &p);

address_relasi findElm_relasi(List_relasi L3, address_artis P,address_fans C);
void printInfo_relasi(List_relasi L3);
void addRelasi(List_relasi &L3, address_relasi R);
void deleteRelasi(List_relasi L3, address_relasi R);

address_relasi findMin(List_relasi &R);






#endif // RELASI_H_INCLUDED
