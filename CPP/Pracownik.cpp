#include "Pracownik.h"

string Pracownik::GetNazwisko() {
    return nazwisko;
}

string Pracownik::GetImie() {
    return imie;
}

string Pracownik::GetID() {
    return ID;
}

void Pracownik::SetID(string item) {
    ID = item;
}

void Pracownik::SetImie(string item) {
    imie = item;
}

void Pracownik::SetNazwisko(string item) {
    nazwisko = item;
}

void Pracownik::WypelnijDane() {
    cout << "Podaj ID: ";
    cin >> ID;
    cout << endl;

    cout << "Podaj imie: ";
    cin >> imie;
    cout << endl;

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << endl;
}