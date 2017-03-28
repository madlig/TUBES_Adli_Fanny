#include "fans.h"

void createList_fans(List_fans &L2) {
    first(L2) = NULL ;
}
address_fans alokasi_fans(infotype_fans x) {
    address_fans C;

    C = new elmList_fans;
    info(C) = x;
    next(C) = NULL;

    return C;
}
void dealokasi_fans(address_fans &C) {
    delete C;
}
void insertFirst_fans(List_fans &L2, address_fans C) {
    next(C) = first(L2);
    first(L2) = C;
}
void insertLast_fans(List_fans &L2, address_fans C) {
    if(first(L2)==NULL) {
        insertFirst_fans(L2,C);
    }else{
        address_fans Q = first(L2);
        while(next(Q) !=NULL) {
            Q = next(Q);
        }
        next(Q) = C;
    }
}
address_fans findElm_fans(List_fans L2, infotype_fans x) {
    address_fans C;

    while(C!=NULL) {
          if(x.no_id==info(C).no_id){
            return C;
          }
        C=next(C);
    }

    return C;
}
void deleteFirst_fans(List_fans &L2, address_fans &C) {
    if(first(L2)!=NULL) {
        C = first(L2);
        first(L2) = next(C);
        next(C) = NULL;
    }
}
void deleteLast_fans(List_fans &L2, address_fans &C) {
    if(first(L2)!=NULL) {
        C = first(L2);
        if(next(C)==NULL) {
            deleteFirst_fans(L2,C);
        }else{
            while(next(next(C))!=NULL) {
                C = next(C);
            }
            address_fans Q = C;
            C = next(Q);
            next(Q) = NULL;
        }
    }
}
void printInfo_fans(List_fans L2) {
    address_fans C = first(L2);
    while(C!=NULL) {
        cout << info(C).no_id << " " << info(C).nama;
        C = next(C);
    }
    cout << endl;
}
void insertAfter_fans(List_fans &L2, address_fans Prec, address_fans C) {
    if(first(L2) == NULL){
        cout<<"Elemen Kosong";
    }
    else if(first(L2) == C) {
        deleteFirst_fans(L2,C);
        }
    else if(next(C) == NULL ){
        deleteLast_fans(L2,C);
    }
    else{
        next(Prec) = next(C);
        next(C) = NULL;
    }
}
address_fans findPrec_fans(List_fans L2,address_fans C){
    address_fans Prec;
    if(C == first(L2)){
        Prec = NULL;
        return Prec;
    }
    else{
        while(next(Prec) != C){
        Prec = next(Prec);
        }
        return Prec;
    }
}
void deleteAfter_fans(List_fans &L2, address_fans Prec, address_fans &C) {
    if(first(L2) == NULL){
        cout<<"Elemen Kosong";
    }
    else if(first(L2) == C) {
        deleteFirst_fans(L2,C);
        }
    else if(next(C) == NULL ){
        deleteLast_fans(L2,C);
    }
    else{
        next(Prec) = next(C);
        next(C) = NULL;
    }
}

