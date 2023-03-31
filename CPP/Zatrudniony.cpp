#include "Zatrudniony.h"

double Zatrudniony::GetWyplata() {
    return Wyplata;
}

void  Zatrudniony::SetWyplata(double item) {
    Wyplata = item;
}

void Zatrudniony::Rewaloryzuj_p(double procent) {
    cout << "Wyplata przed rewaloryzacja " << Wyplata << endl;
    Wyplata = Wyplata * (1 + 0.01 * procent);
    cout << "Wyplata po rewaloryzacji " << Wyplata << endl;
}

void Zatrudniony::Rewaloryzuj_by_przychod(double przychod, double procent) {
    cout << "Wyplata przed rewaloryzacja " << Wyplata << endl;
    cout << "Przychod dzialu " << przychod << endl;
    Wyplata = Wyplata + przychod * 0.01 * procent;
    cout << "Wyplata po rewaloryzacji " << Wyplata << endl;
}

void Zatrudniony::Zatrudnij() {
    string IDdzialuPrac;
    double wyplata;
    cout << "Podaj ID dzialu:" << endl;
    cin >> IDdzialuPrac;
    SetIdDzialu(IDdzialuPrac);
    cout << "Wynadrodzenie:" << endl;;
    cin >> wyplata;
    SetWyplata(wyplata);
    cout << endl;
}

void Zatrudniony::Edytuj()
{
    string item;
    double item_d;
    cout << "Podaj imie: ";
    cin >> item;
    SetImie(item);
    cout << endl;
    cout << "Podaj nazwisko: ";
    cin >> item;
    SetNazwisko(item);
    cout << endl;
    cout << "Podaj ID dzialu:" << endl;;
    cin >> item;
    SetIdDzialu(item);
    cout << endl;
    cout << "Wynadrodzenie:" << endl;;
    cin >> item_d;
    SetWyplata(item_d);
    cout << endl;
}

void Zatrudniony::PokazDane() {
    cout.precision(15);
    string  ID = GetID();
    cout << "Id " << ID << endl;
    string  Imie = GetImie();
    cout << "Imie " << Imie << endl;
    string  Nazwisko = GetNazwisko();
    cout << "Nazwisko " << Nazwisko << endl;
    string item = GetIdDzialu();
    cout << "Dzial w ktorym zatrudniony jest pracownik " << item << endl;
    double wyplata = GetWyplata();
    cout << "Wynagordzenie: " << wyplata << endl;
    cout << " " << endl << endl;
}