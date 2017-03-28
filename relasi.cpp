#include "relasi.h"

void createList_relasi(List_relasi &L3) {
    first(L3) = NULL ;
}
address_relasi alokasi_relasi(address_artis P, address_fans C) {
    address_relasi R;

    R = new elmList_relasi;
    artis_next(R) = P;
    fans_next(R) = C;

    return R;
}
void dealokasi_relasi(address_relasi &R) {
    delete R;
}
void insertFirst_relasi(List_relasi &L3, address_relasi R) {
    next(R) = first(L3);
    first(L3) = R;
}
void insertLast_relasi(List_relasi &L3, address_relasi R) {
    if(first(L3)==NULL) {
        insertFirst_relasi(L3,R);
    }else{
        address_relasi Q = first(L3);
        while(next(Q) !=NULL) {
            Q = next(Q);
        }
        next(Q) = R;
    }
}
address_relasi findElm_relasi(List_relasi L3, address_artis P,address_fans C) {
    address_relasi R;

    while(P!=NULL) {
        if(artis_next(R)==P && fans_next(R)==C){
            return R;
        }
        R = next(R);
    }

    return R;
}
void deleteFirst_relasi(List_relasi &L3, address_relasi &R) {
    if(first(L3)!=NULL) {
        R = first(L3);
        first(L3) = next(R);
        next(R) = NULL;
    }
}
void deleteLast_relasi(List_relasi &L3, address_relasi &R) {
    if(first(L3)!=NULL) {
        R = first(L3);
        if(next(R)==NULL) {
            deleteFirst_relasi(L3,R);
        }else{
            while(next(next(R))!=NULL) {
                R = next(R);
            }
            address_relasi Q = R;
            R = next(Q);
            next(Q) = NULL;
        }
    }
}
void printInfo_relasi(List_relasi L3) {
    address_relasi R = first(L3);
    while(R!=NULL) {
        cout << info(artis_next(R)).nama << " " << info(fans_next(R)).nama;
        R = next(R);
    }
    cout << endl;
}
void insertAfter_relasi(List_relasi &L3, address_relasi Prec, address_relasi R) {
    if(first(L3)!=NULL) {
        next(R) = next(Prec);
        next(Prec) = R;
    }else{
        insertFirst_relasi(L3,R);
    }
}
address_relasi findPrec_relasi(List_relasi L3,address_relasi R){
    address_relasi Prec;
    if(R == first(L3)){
        Prec = NULL;
        return Prec;
    }
    else{
        while(next(Prec) != R){
        Prec = next(Prec);
        }
        return Prec;
    }
}
void deleteAfter_relasi(List_relasi &L3, address_relasi Prec, address_relasi &R) {
    if(first(L3) == NULL){
        cout<<"Elemen Kosong";
    }
    else if(first(L3) == R) {
        deleteFirst_relasi(L3,R);
        }
    else if(next(R) == NULL ){
        deleteLast_relasi(L3,R);
    }
    else{
        next(Prec) = next(R);
        next(R) = NULL;
    }
}
void addRelasi(List_relasi &L3, address_relasi R){
    if(first(L3) == NULL ){
        insertFirst_relasi(L3,R);
    }
    else{
        insertLast_relasi(L3,R);
    }
}
void deleteRelasi(List_relasi L3, address_relasi R){
    address_relasi Prec;
    if(first(L3) == NULL){
        cout<<"Elemen Kosong";
    }
    else{
        deleteAfter_relasi(L3,Prec,R);
    }
}

