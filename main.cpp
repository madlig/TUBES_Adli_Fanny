#include <iostream>
#include <conio.h>
#include <windows.h>
#include "artis.h"
#include "relasi.h"
#include "fans.h"
#include "aplikasi.h"

using namespace std;

int main()
{
    artis A;
    fans F;

    List_artis L;
    List_fans L2;
    List_relasi L3;

    createList_artis(L);
    createList_fans(L2);
    createList_relasi(L3);

    menu();

    int input,x;

    A.nama  = "Eman";
    A.gender = "Pria";
    insertFirst_artis(L, alokasi_artis(A));



    /**
    address_artis P;
    address_fans C;
    address_relasi R;

    int input;

    do{
        cin>>input;
        switch(input){
        case 1 :
                system("CLS");
                cout<<"FUNGSI 1"<<endl;
                cout<<"Masukkan Nama Artis : ";cin>>A.nama;
                cout<<"Masukkan Kontaknya  : ";cin>>A.cp;
                cout<<"Masukkan Medsosnya  : ";cin>>A.medsos;
                cout<<"Masukkan Pekerjaan  : ";cin>>A.pekerjaan;
                cout<<"Masukkan Nomer Identitas      : ";cin>>A.no_id;
                cout<<"Masukkan Gender     : ";cin>>A.gender;

                P = alokasi_artis(A);
                if(P != NULL){
                    insertFirst_artis(L,P);
                    cout<<"Berhasil diinputkan ";
                }
                else{
                    cout<<"Data ada yang salah";
                }

                break;
        case 2 :
                system("CLS");
                cout<<"FUNGSI 2";
                printInfo_artis(L);
                break;
        case 3 :
                system("CLS");
                cout<<"FUNGSI 3";

                break;
        case 4 :
                system("CLS");
                cout<<"FUNGSI 4";

                break;
        case 5 :
                system("CLS");
                cout<<"FUNGSI 5";

                break;
        case 0 :
                return input;
                break;
        }
    }while(input != 0);**/
}
