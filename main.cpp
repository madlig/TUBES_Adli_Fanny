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


}
