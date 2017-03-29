#include "aplikasi.h"
#include <windows.h>
#include <conio.h>

#include <iostream>

using namespace std;

    artis A;
    fans F;

    address_artis P;
    address_fans C;
    address_relasi R;

    List_artis L;
    List_fans L2;
    List_relasi L3;

void menu(){

    int pilihan;

    A.nama  = "Eman";
    A.gender = "Pria";
    A.no_id = 50;
    A.pekerjaan = "Aktor";
    A.cp = "08122451677";
    A.medsos = "@man";
    insertFirst_artis(L, alokasi_artis(A));

    F.nama  = "Alyssa";
    F.gender = "Wanita";
    F.no_id = 30;
    F.pekerjaan = "Pelajar";
    F.cp = "08523241389";
    F.region = "@lysa";
    insertFirst_fans(L2,alokasi_fans(F));

    do{
        system("CLS");
        cout<<"   =========MENU==========   "<<endl<<
        " 1. Masukan data artis  "<<endl<<
        " 2. Masukan data fans   "<<endl<<
        " 3. Tampilkan data artis   "<<endl<<
        " 4. Tampilkan data fans   "<<endl<<
        " 5. Cari data artis   "<<endl<<
        " 6. Cari data fans   "<<endl<<
        " 7. Hubungkan artis dan fans  "<<endl<<
        " 8. Tampilkan relasi  "<<endl<<
        " 9. Cari relasi  "<<endl<<
        "10. Putuskan relasi "<<endl<<
        "11. Hapus data artis  "<<endl<<
        "12. Hapus data fans  "<<endl<<
        "13. Urutkan data relasi "<<endl<<
        " 0. Keluar "<<endl<<
        "Input Menu : ";
        cin>>pilihan;
        switch(pilihan){
            case 1:insert_parent();break;
            case 2:insert_child();break;
            case 3:view_parent();break;
            case 4:view_child();break;
            case 5:search_parent();break;
            case 6:search_child();break;
            case 7:relasikan();break;
            case 8:view_relasi();break;
            case 9:search_relasi();break;
            case 10:putus_relasi();break;
            case 11:delete_parent();break;
            case 12:delete_child();break;
            /**case 13:sort_relasi();break;**/
            case 0:thank_you();break;
            default:cout<<"Inputan salah"<<endl;break;
        }
        cout<<"\nTekan Enter";getch();
        cout<<endl;
    }while(pilihan!=0);
}

void insert_parent(){
                system("CLS");
                cout<<"==========Masukkan Data Artis=========="<<endl;
                cout<<"Masukkan Nama Artis : ";cin>>A.nama;
                cout<<"Masukkan Nomer Kontak  : ";cin>>A.cp;
                cout<<"Masukkan Alamat Medsos  : ";cin>>A.medsos;
                cout<<"Masukkan Pekerjaan  : ";cin>>A.pekerjaan;
                cout<<"Masukkan Nomer Identitas : ";cin>>A.no_id;
                cout<<"Masukkan Jenis Kelamin : ";cin>>A.gender;

                P = alokasi_artis(A);
                if(P != NULL){
                    if(L.first == NULL || info(P).no_id < info(first(L)).no_id){
                        insertFirst_artis(L,P);
                    }
                    else if(info(P).no_id > info(last(L)).no_id){
                        insertLast_artis(L,P);
                    }
                    else{
                        address_artis T=first(L);
                        address_artis Prec;
                        while(T != NULL){
                            if(info(P).no_id > info(T).no_id){
                                Prec = T;
                                T=next(T);
                            }
                            else{
                                insertAfter_artis(L,Prec,P);
                            }
                        }
                    }
                }
                else{
                    cout<<"Data ada yang salah";
                }

}

void insert_child(){
                system("CLS");
                cout<<"==========Masukan Nama Fans=========="<<endl;
                cout<<"Masukkan Nama Fans : ";cin>>F.nama;
                cout<<"Masukkan Nomer telfon  : ";cin>>F.cp;
                cout<<"Masukkan Region  : ";cin>>F.region;
                cout<<"Masukkan Pekerjaan  : ";cin>>F.pekerjaan;
                cout<<"Masukkan Nomer Identitas  : ";cin>>F.no_id;
                cout<<"Masukkan Gender     : ";cin>>F.gender;

                C = alokasi_fans(F);
                if(C != NULL){
                    insertFirst_fans(L2,C);
                    cout<<"Berhasil diinputkan ";
                }
                else{
                    cout<<"Data ada yang salah";
                }
}

void view_parent(){
                system("CLS");
                if(first(L)==NULL){
                    cout<<"Data Kosong";
                }
                else{
                    cout<<"==========Tampilkan Data Artis=========="<<endl;
                    printInfo_artis(L);
}               }

void view_child(){
                system("CLS");
                if(first(L2)==NULL){
                    cout<<"Data Kosong";
                }
                else{
                    cout<<"==========Tampilkan Data Fans=========="<<endl;
                    printInfo_fans(L2);
                    cout<<endl;
                }
}

void search_parent(){
                system("CLS");
                cout<<"==========Cari data Artis=========="<<endl;
                cout<<"Masukan nomer identitas : ";
                cin>>A.no_id;
                P = findElm_artis(L,A);
                if(P != NULL){
                    cout<<A.nama<<endl;
                    cout<<A.cp<<endl;
                    cout<<A.medsos<<endl;
                    cout<<A.gender<<endl;
                    cout<<A.no_id<<endl;
                    cout<<A.pekerjaan<<endl;
                }
                else{
                    cout<<"Nomer identitas tidak ditemukan";
                }
}
void search_child(){
                system("CLS");
                cout<<"==========Cari data Fans=========="<<endl;
                cout<<"Masukan nomer identitas : ";
                cin>>F.no_id;
                C = findElm_fans(L2,F);
                if(C != NULL){
                    cout<<F.nama<<endl;
                    cout<<F.cp<<endl;
                    cout<<F.no_id<<endl;
                    cout<<F.region<<endl;
                    cout<<F.pekerjaan<<endl;
                    cout<<F.gender<<endl;
                }
                else{
                    cout<<"Nomer identitas tidak ditemukan";
                }
}

void relasikan(){
                cout<<"========== Hubungan Artis & Fans ========="<<endl;
                cout<<"Masukan nama artis : ";
                cin>>A.nama;
                cout<<"Masukan nomer identitas artis : ";
                cin>>A.no_id;
                P = findElm_artis(L,A);
                cout<<"Masukan nama fans : ";
                cin>>F.nama;
                cout<<"Masukan nomer identitas fans : ";
                cin>>F.no_id;
                C = findElm_fans(L2,F);
                if(P != NULL && C != NULL){
                    cout<<"Data berhasil diinputkan";
                    addRelasi(L3,alokasi_relasi(P,C));
                }
                else{
                    cout<<"Data tidak ditemukan";
                }


}

void view_relasi(){
                system("CLS");
                    cout<<"==========Daftar Artis & Fans=========="<<endl;
                    printInfo_relasi(L3);
}

bool search_relasi(){
                cout<<"==========Cari Artis & Fans=========="<<endl;
                cout<<"Masukan nama artis : ";
                cin>>A.nama;
                cout<<"Masukan nomer identitas artis : ";
                cin>>A.no_id;
                P = findElm_artis(L,A);
                cout<<"Masukan nama fans : ";
                cin>>F.nama;
                cout<<"Masukan nomer identitas fans : ";
                cin>>F.no_id;
                C = findElm_fans(L2,F);
                R = findElm_relasi(L3,P,C);
                if(R != NULL){
                    cout<<"Data saling berhubungan"<<endl;
                    return TRUE;
                }
                else{
                    cout<<"Data tidak saling berhubungan"<<endl;
                    return FALSE;
                }
}

void putus_relasi(){
                cout<<"========== Hapus Hubungan ========="<<endl;
                cout<<"Masukan nama artis : ";
                cin>>A.nama;
                cout<<"Masukan nomer identitas artis : ";
                cin>>A.no_id;
                P = findElm_artis(L,A);
                cout<<"Masukan nama fans : ";
                cin>>F.nama;
                cout<<"Masukan nomer identitas fans : ";
                cin>>F.no_id;
                C = findElm_fans(L2,F);
                R = findElm_relasi(L3,P,C);
                if(R != NULL){
                    cout<<"Data berhasil dihapus"<<endl;
                    deleteRelasi(L3,R);
                }
                else{
                    cout<<"Data tidak ditemukan";
                }

}

void delete_parent(){
                cout<<"========== Hapus Data Artis =========="<<endl;
                address_relasi R;
                address_artis Prec;
                cout<<"Masukan nama artis : ";
                cin>>A.nama;
                cout<<"Masukan nomor identitas artis: ";
                cin>>A.no_id;
                P = findElm_artis(L,A);
                if(P != NULL){
                    /**while(R != NULL){
                        if(artis_next(R) == P){
                            deleteRelasi(L3,R);
                        }
                        R=next(R);
                    }**/
                    cout<<"berhasil"<<endl;
                    deleteAfter_artis(L,Prec,P);
                }
                else
                    cout<<"Data tidak ditemukan"<<endl;

}

void delete_child(){
                cout<<"========== Hapus Data Artis =========="<<endl;
                address_relasi R;
                address_fans Prec;
                cout<<"Masukan nama fans : ";
                cin>>F.nama;
                cout<<"Masukan nomor identitas fans: ";
                cin>>F.no_id;
                C = findElm_fans(L2,F);
                if(C != NULL){
                    /**while(R != NULL){
                        cout<<"berhasil"<<endl;
                        if(fans_next(R) == C){
                            cout<<"berhasil"<<endl;
                            deleteRelasi(L3,R);
                        }
                        R=next(R);
                    }**/
                    deleteAfter_fans(L2,Prec,C);
                }
                else{
                    cout<<"Data tidak ditemukan";
                }
}
/**address_relasi findMin(List_relasi &L3){
                address_relasi R;
                if(first(L3) == NULL){
                    cout<<"Data Kosong"<<endl;
                    R = NULL;
                }
                else{
                    R = first(L3);
                    address_relasi min = R ;
                    while(next(R) != NULL){
                        R = next(R);
                        if(info(artis_next(R)).no_id < info(artis_next(min)).no_id){
                            min = R;
                        }
                    }
                }
                return R;
}
void sort_relasi(List_relasi &L3, List_relasi L3_hasil ){
                address_relasi R, R1;
                address_artis P;
                address_fans C;
                while(next(R) != NULL){
                    R1 = findMin(L3);
                    P = artis_next(R);
                    C = fans_next(R);
                    deleteRelasi(L3,R1);
                    A = alokasi_relasi(P,C);
                    insertLast_relasi(L3_hasil,A);
                    R
                }
                R=T;
}**/

void thank_you(){
                cout<<"Udah liat program kita kan ya ?"<<endl;
                cout<<"Kami ucapkan terimakasih telah melihat program ini.."<<endl;

                cout<<"Terimakasih juga buat yang sudah berkontribusi membantu dalam pengerjaan"<<endl;

}
