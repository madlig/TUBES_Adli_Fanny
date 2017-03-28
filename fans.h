#ifndef FANS_H_INCLUDED
#define FANS_H_INCLUDED

#include <iostream>

using namespace std;

#define nil NULL
#define first(L2) L2.first
#define next(P) P->next
#define info(P) P->info

struct fans{
    int no_id;
    string nama;
    int cp;
    string region;
    string gender;
    string pekerjaan;
};

typedef fans infotype_fans;
typedef struct elmList_fans *address_fans;


struct elmList_fans {
    infotype_fans info;
    address_fans next;
};
struct List_fans {
    address_fans first;
};

void createList_fans (List_fans &L2);
address_fans alokasi_fans(infotype_fans x);
void dealokasi_fans(address_fans &C);

void insertFirst_fans(List_fans &L2, address_fans C);
void insertLast_fans(List_fans &L2, address_fans C);
void insertAfter_fans(List_fans &L2, address_fans Prec, address_fans C);

void deleteFirst_fans(List_fans &L2, address_fans &C);
void deleteLast_fans(List_fans &L2, address_fans &C);
void deleteAfter_fans(List_fans &L2, address_fans Prec, address_fans &C);

address_fans findElm_fans(List_fans L2, infotype_fans x);
void printInfo_fans(List_fans L2);



#endif // FANS_H_INCLUDED
