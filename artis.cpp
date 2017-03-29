#include "artis.h"

void createList_artis(List_artis &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_artis alokasi_artis(infotype_artis x) {
    address_artis P;

    P = new elmlist_artis;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void dealokasi_artis(address_artis &P) {
    delete P;
}

void insertFirst_artis(List_artis &L, address_artis P){
    if(first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else{
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}
void insertLast_artis(List_artis &L, address_artis P){
    if(first(L)==NULL){
        insertFirst_artis(L,P);
    }
    else{
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}
void insertAfter_artis(List_artis &L, address_artis Prec, address_artis P){
    if(Prec!=NULL){
        if(next(Prec)==NULL) {
            insertLast_artis(L,P);
        }
        else {
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(Prec))=P;
            next(Prec) = P;
        }
     }else{
        cout<<"Tidak terdapat insertAfter,Prec NULL"<<endl;
     }
}

void deleteFirst_artis(List_artis &L, address_artis P){
    if(first(L)==NULL){
        cout<<"Tidak ada data"<<endl;
    }
    else if(first(L)==last(L)){
        P=first(L);
        first(L)=next(P);
        prev(first(L))=NULL;
        next(P)=NULL;
    }
    else{
        P=first(L);
        first(L)=next(P);
        prev(first(L))=NULL;
        next(P)=NULL;
    }
}

void deleteLast_artis(List_artis &L, address_artis P){
    if(first(L)==NULL){
        cout<<"Tidak ada data"<<endl;
    }
    else if(first(L)==last(L)){
        P=first(L);
        first(L)=next(P);
        prev(first(L))=NULL;
        next(P)=NULL;
    }
    else{
        P=first(L);
        last(L)=prev(P);
        next(last(L))=NULL;
        next(P)=NULL;
    }
}
void deleteAfter_artis(List_artis &L, address_artis Prec, address_artis P){
   if(first(L) == NULL){
        cout<<"Elemen Kosong";
    }
    else if(first(L) == P) {
        deleteFirst_artis(L,P);
        }
    else if(next(P) == NULL ){
        deleteLast_artis(L,P);
    }
    else{
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

address_artis findElm_artis(List_artis L,infotype_artis x){
    address_artis A = first(L);
    while(A != NULL) {
          if(x.no_id == info(A).no_id){
            return A;
          }
        A = next(A);
    }

    return A;
}

void printInfo_artis(List_artis L){
    address_artis P = first(L);
    while(P != NULL){
        cout<<info(P).no_id<<" "<<info(P).nama;cout<<" "<<endl;
        P = next(P);
    }
}


