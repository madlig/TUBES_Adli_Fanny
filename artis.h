#ifndef ARTIS_H_INCLUDED
#define ARTIS_H_INCLUDED

#include <iostream>

using namespace std;

#define nil NULL
#define first(L) L.first
#define next(P) P->next
#define last(L) L.last
#define prev(P) P->prev
#define info(P) P->info

struct artis{
    int no_id;
    string nama;
    int cp;
    string gender;
    string pekerjaan;
    string medsos;
};

typedef artis infotype_artis;
typedef struct elmlist_artis *address_artis;

struct elmlist_artis{
    infotype_artis info;
    address_artis next;
    address_artis prev;
};

struct List_artis{
    address_artis first;
    address_artis last;
};

void createList_artis(List_artis &L);
address_artis alokasi_artis(infotype_artis x);
void dealokasi_artis(address_artis &P);

void insertFirst_artis(List_artis &L, address_artis P);
void insertLast_artis(List_artis &L, address_artis P);
void insertAfter_artis(List_artis &L, address_artis Prec, address_artis P);

void deleteFirst_artis(List_artis &L, address_artis P);
void deleteLast_artis(List_artis &L, address_artis P);
void deleteAfter_artis(List_artis &L, address_artis Prec, address_artis P);

address_artis findElm_artis(List_artis L,infotype_artis x);
void printInfo_artis(List_artis L);

#endif // ARTIS_H_INCLUDED
