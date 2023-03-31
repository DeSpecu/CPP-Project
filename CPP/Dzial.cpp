#include "Dzial.h"

string Dzial::GetIdDzialu() {
    return IdDzialu;
}

string Dzial::GetNazwa() {
    return Nazwa;
}

string Dzial::GetIdDzialuNad() {
    return IdDzialuNad;
}

double Dzial::GetPrzychod() {
    return Przychod;
}

void  Dzial::SetIdDzialu(string item) {
    IdDzialu = item;
}

void  Dzial::SetNazwa(string item) {
    Nazwa = item;
}

void  Dzial::SetIdDzialuNad(string item) {
    IdDzialuNad = item;
}

void  Dzial::SetPrzychod(double item) {
    Przychod = item;
}

void Dzial::Wypelnij()
{
    cout << "Podaj nazwe : ";
    cin >> Nazwa;
    cout << endl;

    cout << "Podaj id: ";
    cin >> IdDzialu;
    cout << endl;

    cout << "Podaj id dzialu nadrzednego: ";
    cin >> IdDzialuNad;
    cout << "Podaj przychod: ";
    cin >> Przychod;
    cout << endl;

    cout << endl;
}

void Dzial::Edytuj()
{
    string item;
    double przychod;

    cout << "Podaj nazwe : ";
    cin >> item;
    SetNazwa(item);
    cout << endl;

    cout << "Podaj id dzialu nadrzednego: ";
    cin >> item;
    SetIdDzialuNad(item);

    cout << "Podaj kwote przychodu: ";
    cin >> przychod;
    SetPrzychod(przychod);
    cout << endl;
    cout << endl;
}

void Dzial::PokazDane()
{
    string item;
    cout.precision(15);
    item = GetIdDzialu();
    cout << "ID " << item << endl;
    item = GetNazwa();
    cout << "Nazwa " << item << endl;
    item = GetIdDzialuNad();
    cout << "ID dzialu nadrzednego: " << item << endl;
    double przychod = GetPrzychod();
    cout << "Przychod dzialu: " << przychod << endl;
    cout << " " << endl;
}