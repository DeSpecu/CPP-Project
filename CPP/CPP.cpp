#include "Funkcje.h"
#include<iostream>

using namespace std;

int main()
{   

    //Polskie Znaki
    setlocale(LC_ALL, "");

    wczytajpracownikow();
    wczytajdzialy();

    int check = 0;
    do
    {
        check = menu_glowne();

    } while (check == 0);

    zapisz();

    return 0;
}