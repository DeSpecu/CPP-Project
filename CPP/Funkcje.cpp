#include <iostream>
#include <conio.h>
#include <list>
#include <memory>
#include <fstream>
#include <string>
#include <iomanip>
#include "Pracownik.h"
#include "Dzial.h"
#include "Zatrudniony.h"
#include "Iterator.h"
#include "Container.h"

using namespace std;

Container<Zatrudniony> ListaZatrudnionychPracownikow;
Container<Dzial> ListaDzialow;

void PokazWszystkieDzialy() {
    cout << "Dzialy:" << endl;
    Iterator<Dzial, Container<Dzial>>* it3 = ListaDzialow.CreateIterator();
    for (it3->First(); !it3->IsDone(); it3->Next()) {
        it3->Current()->PokazDane();
    }
    delete it3;
    cout << " " << endl;
}


//ustaw ID w miejsce usunietego
void ustawIDusunietego(string IDu, string IDnu) {
    Iterator<Dzial, Container<Dzial>>* it3 = ListaDzialow.CreateIterator();
    for (it3->First(); !it3->IsDone(); it3->Next()) {
        string IDn = it3->Current()->GetIdDzialuNad();
        if (IDn == IDu) {
            it3->Current()->SetIdDzialuNad(IDnu);
        }
    }
    delete it3;
}

void UsunDzial() {
    string ID_to_delete;
    string ID_nadrzedny;
    string ID_nadrzedny_p;
    cout << "Podaj ID: ";
    cin >> ID_to_delete;
    cout << endl;

    Iterator<Dzial, Container<Dzial>>* it3 = ListaDzialow.CreateIterator();
    for (it3->First(); !it3->IsDone(); it3->Next()) {
        string  ID = it3->Current()->GetIdDzialu();
        cout << ID << endl;
        if (ID == ID_to_delete) {
            cout << " Usuwam: " << ID << endl;
            it3->Current()->PokazDane();
            string IDn = it3->Current()->GetIdDzialuNad();
            it3->Delete();
            ustawIDusunietego(ID, IDn);
            break;
        }
    }
    delete it3;
}

void EdytujDzial() {
    string ID_to_edit;
    string ID;
    cout << "Podaj ID: ";
    cin >> ID_to_edit;
    cout << endl;
    Iterator<Dzial, Container<Dzial>>* it3 = ListaDzialow.CreateIterator();
    for (it3->First(); !it3->IsDone(); it3->Next()) {
        ID = it3->Current()->GetIdDzialu();
        if (ID == ID_to_edit) {
            cout << "Znaleziono " << ID << endl;
            it3->Current()->Edytuj();
        }
    }
    delete it3;

}

double GetPrzychodDzialu(string IDDp) {
    double przychod = 0;
    int found = 0;

    Iterator<Dzial, Container<Dzial>>* it3 = ListaDzialow.CreateIterator();
    for (it3->First(); !it3->IsDone(); it3->Next()) {
        string ID = it3->Current()->GetIdDzialu();
        if (IDDp == ID) {
            przychod = it3->Current()->GetPrzychod();

        }
        it3++;
    }
    delete it3;

    return przychod;
}

void PokazZatrudnionychPracownikow() {
    cout << "Lista Zatrudnionych Pracowników" << endl;
    Iterator<Zatrudniony, Container<Zatrudniony>>* it2 = ListaZatrudnionychPracownikow.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next()) {
        it2->Current()->PokazDane();
    }
    delete it2;
    cout << " " << endl;
}

void UsunPracownika() {
    string ID_to_delete;
    cout << "Podaj ID: ";
    cin >> ID_to_delete;
    cout << endl;

    Iterator<Zatrudniony, Container<Zatrudniony>>* it2 = ListaZatrudnionychPracownikow.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next()) {
        string  ID = it2->Current()->GetID();
        if (ID == ID_to_delete) {
            it2->Delete();
            break;
        }
    }
    delete it2;

}

void EdytujPracownika() {

    string ID_to_edit;
    string ID;
    int edited = 0;
    cout << "Podaj ID: ";
    cin >> ID_to_edit;
    cout << endl;

    Iterator<Zatrudniony, Container<Zatrudniony>>* it2 = ListaZatrudnionychPracownikow.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next()) {
        ID = it2->Current()->GetID();
        if (ID == ID_to_edit) {
            cout << "Znaleziono " << ID << endl;
            it2->Current()->Edytuj();
        }
    }
    delete it2;
}


void wczytajpracownikow()
{
    ifstream file("pracownicy.txt");

    Zatrudniony NeWZat;

    if (file.is_open()) {
        string line;
        string obj_item;
        while (getline(file, line)) {

            int ctrl = 0;
            Zatrudniony NeWZat;

            size_t start = 0, end = 0;
            string delim = ";";

            while ((start = line.find_first_not_of(delim, end)) != string::npos)
            {
                ctrl++;
                end = line.find(delim, start);
                obj_item = line.substr(start, end - start);

                switch (ctrl)
                {
                case 1:

                    NeWZat.SetID(obj_item);
                    break;
                case 2:

                    NeWZat.SetImie(obj_item);
                    break;
                case 3:

                    NeWZat.SetNazwisko(obj_item);
                    break;

                case 4:
                    NeWZat.SetIdDzialu(obj_item);
                    break;

                case 5:
                    NeWZat.SetWyplata(stod(obj_item));
                    break;
                }
            }
            ListaZatrudnionychPracownikow.Add(NeWZat);
        }
    }
    file.close();
}

int klawisz()
{

    unsigned char znak;
    cout << "Proszê wybraæ opcje " << endl;

    znak = _getch();
    while (_kbhit())
    {
        znak = _getch();
    }
    cout << endl;
    return(znak);
}

void czekaj() {
    cout << "Naciœnij klawisz, ¿eby kontynuowaæ " << endl;
    while (!_kbhit())
    {
    }
    system("cls");
}

void rewaloryzuj_place_dzialu_by_przychod(string IDP, double procent) {
    double przychod_d;
    przychod_d = GetPrzychodDzialu(IDP);
    Iterator<Zatrudniony, Container<Zatrudniony>>* it2 = ListaZatrudnionychPracownikow.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next()) {
        string IDD = it2->Current()->GetIdDzialu();
        if (IDD == IDP) {
            it2->Current()->PokazDane();
            it2->Current()->Rewaloryzuj_by_przychod(przychod_d, procent);
            it2->Current()->PokazDane();
        }
    }
    delete it2;
}

void rewaloryzuj_place_dzialu_by_przychod_podrzednego(string IDDp, double procent) {

    rewaloryzuj_place_dzialu_by_przychod(IDDp, procent);

    Iterator<Dzial, Container<Dzial>>* it3 = ListaDzialow.CreateIterator();
    for (it3->First(); !it3->IsDone(); it3->Next()) {
        string IDD = it3->Current()->GetIdDzialu();
        string IDN = it3->Current()->GetIdDzialuNad();
        string IDNazwa = it3->Current()->GetNazwa();

        if (IDDp == IDN) {
            cout << endl;
            cout << "Rewaloryzuje dzia³ " << IDNazwa << " ID " << IDD << " nadrzêdny ID " << IDN << " procent " << procent << endl;
            rewaloryzuj_place_dzialu_by_przychod_podrzednego(IDD, procent);
            cout << endl;
        }
    }
    delete it3;
}

void rewaloryzuj_place_dzialu(string IDP, double procent) {
    Iterator<Zatrudniony, Container<Zatrudniony>>* it2 = ListaZatrudnionychPracownikow.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next()) {
        string IDD = it2->Current()->GetIdDzialu();
        if (IDD == IDP) {
            it2->Current()->PokazDane();
            it2->Current()->Rewaloryzuj_p(procent);
            it2->Current()->PokazDane();
        }
    }
    delete it2;
}

void rewaloryzuj_place_dzialu_podrzednego(string IDDp, double procent) {

    //list<Dzial>::iterator it3t;
    rewaloryzuj_place_dzialu(IDDp, procent);

    Iterator<Dzial, Container<Dzial>>* it3 = ListaDzialow.CreateIterator();
    for (it3->First(); !it3->IsDone(); it3->Next()) {
        string IDD = it3->Current()->GetIdDzialu();
        string IDN = it3->Current()->GetIdDzialuNad();
        string IDNazwa = it3->Current()->GetNazwa();

        if (IDDp == IDN) {
            cout << endl;
            cout << "Rewaloryzuje dzia³ " << IDNazwa << " ID " << IDD << " nadrzêdny ID " << IDN << " procent " << procent << endl;
            rewaloryzuj_place_dzialu_podrzednego(IDD, procent);
            cout << endl;
        }
    }
    delete it3;
    return;
}

void get_dzialy_podrzedne(string IDDp) {

    //list<Dzial>::iterator it3t;
    cout << endl;
    cout << "Dzial " << IDDp << endl;

    Iterator<Dzial, Container<Dzial>>* it3 = ListaDzialow.CreateIterator();
    for (it3->First(); !it3->IsDone(); it3->Next()) {
        string IDD = it3->Current()->GetIdDzialu();
        string IDN = it3->Current()->GetIdDzialuNad();
        string IDNazwa = it3->Current()->GetNazwa();
        if (IDDp == IDN) {
            cout << endl;
            cout << "Dzia³ " << IDNazwa << " ID " << IDD << " podrzêdny do ID " << IDN << endl;
            get_dzialy_podrzedne(IDD);
        }
    }
    delete it3;
}

void rewaloryzacja_plac() {

    string IDW;
    int metoda;
    double procent;
    double wyplata;
    int check = 0;
    int check_m = 0;
    cout << "Podaj ID dzia³u, w którym chcesz przeprowadziæ rewaloryzacjê p³ac: ";
    cin >> IDW;
    cout << "Wybrano dzia³" << IDW << endl;
    cout << endl;
    cout << "Podaj procent rewaloryzacji: ";
    cin >> procent;
    cout << "Wybrano rewaloryzacje o " << procent << "%" << endl;
    cout << endl;
    cout << "Czy rewaloryzowaæ p³ace w dzia³ach podrzêdnych (T/N)?" << endl;

    do
    {
        check = klawisz();
    } while (check != 116 and check != 110);

    cout << "Wybierz metodê:" << endl;
    cout << "1: procentowo od wynagrodzenia" << endl;
    cout << "2: procentowo od przychodu dzia³u" << endl;

    do
    {
        check_m = klawisz();
        cout << check_m << endl;
    } while (check_m != 49 and check_m != 50);

    if (check_m == 49) {
        if (check == 110) {
            cout << "1:  " << endl;
            rewaloryzuj_place_dzialu(IDW, procent);
        }
        else {
            rewaloryzuj_place_dzialu_podrzednego(IDW, procent);
        }
    }
    else {

        if (check == 110) {
            cout << "2:  " << endl;
            rewaloryzuj_place_dzialu_by_przychod(IDW, procent);
        }
        else {
            rewaloryzuj_place_dzialu_by_przychod_podrzednego(IDW, procent);
        }
    }
}

int menu_glowne()
{
    int check1 = 0;

    cout << "1 Wprowad¿ dzia³" << endl;
    cout << "D Edytuj dzia³" << endl;
    cout << "2 Zatrudnij pracownika" << endl;
    cout << "P Edytuj pracownika" << endl;
    cout << "3 Dokonaj rewaloryzacji" << endl;
    cout << "4 Poka¿ dzia³y" << endl;
    cout << "5 Poka¿ pracowników" << endl;
    cout << "7 Usuñ dzia³" << endl;
    cout << "8 Usuñ dane pracownika" << endl;
    cout << "0 Wyjœcie i Zapis" << endl;

    char wybor;
    wybor = klawisz();

    Dzial NowyDzial;
    Zatrudniony NowyPracownik;

    switch (wybor)
    {
    case '1':
        cout << "Wybrano Wprowadzanie Dzia³u" << endl;
        NowyDzial.Wypelnij();
        ListaDzialow.Add(NowyDzial);
        break;

    case 'd':
        cout << "Wybrano Edycjê Dzia³u" << endl;
        PokazWszystkieDzialy();
        EdytujDzial();
        PokazWszystkieDzialy();
        break;

    case '2':
        cout << "Wybrano Zatrudnianie Pracownika" << endl;
        NowyPracownik.WypelnijDane();
        NowyPracownik.Zatrudnij();
        ListaZatrudnionychPracownikow.Add(NowyPracownik);   
        break;

    case 'p':
        cout << "Wybrano Edycjê Pracownika" << endl;
        PokazZatrudnionychPracownikow();
        EdytujPracownika();
        break;


    case '3':
        cout << "Wybrano Rewaloryzacjê" << endl;
        PokazWszystkieDzialy();
        rewaloryzacja_plac();
        break;


    case '4':
        PokazWszystkieDzialy();
        czekaj();
        break;

    case '5':
        PokazZatrudnionychPracownikow();
        czekaj();
        break;


    case '7':
        cout << "Wybrano Usuwanie Dzia³u" << endl;
        PokazWszystkieDzialy();
        UsunDzial();
        PokazWszystkieDzialy();
        czekaj();
        break;

    case '8':
        cout << "Wybrano Usuwanie Pracownika" << endl;
        PokazZatrudnionychPracownikow();
        UsunPracownika();
        PokazZatrudnionychPracownikow();
        czekaj();
        break;

    case '0':
        cout << "Wybrano Wyjœcie i Zapis" << endl;
        check1 = 1;

        break;

    default:
        cout << "Wybrano inny" << endl;
        czekaj();
        break;
    }

    return check1;
}

void wczytajdzialy()
{
    ifstream file("dzialy.txt");

    if (file.is_open()) {
        string line;
        string obj_item;
        double obj_item_double;
        while (getline(file, line)) {

            int ctrl = 0;

            Dzial NeWDzial;

            size_t start = 0, end = 0;
            string delim = ";";

            while ((start = line.find_first_not_of(delim, end)) != string::npos)
            {
                ctrl++;
                end = line.find(delim, start);
                obj_item = line.substr(start, end - start);

                switch (ctrl)
                {
                case 1:
                    NeWDzial.SetIdDzialu(obj_item);

                    break;

                case 2:
                    NeWDzial.SetNazwa(obj_item);
                    break;

                case 3:
                    NeWDzial.SetIdDzialuNad(obj_item);
                    break;

                case 4:
                    obj_item_double = stod(obj_item);
                    NeWDzial.SetPrzychod(obj_item_double);
                    break;

                }
            }
            ListaDzialow.Add(NeWDzial);
        }
    }
    file.close();
}

void zapisz()
{
    ofstream output("pracownicy.txt");
    double wyplata;
    Iterator<Zatrudniony, Container<Zatrudniony>>* it2 = ListaZatrudnionychPracownikow.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next()) {
        output << it2->Current()->GetID();
        output << ";";
        output << it2->Current()->GetImie();
        output << ";";
        output << it2->Current()->GetNazwisko();
        output << ";";
        output << it2->Current()->GetIdDzialu();
        output << ";";
        wyplata = it2->Current()->GetWyplata();
        output << to_string(wyplata);
        output << endl;
    }
    delete it2;

    ofstream output_d("dzialy.txt");

    Iterator<Dzial, Container<Dzial>>* it3 = ListaDzialow.CreateIterator();
    for (it3->First(); !it3->IsDone(); it3->Next()) {
        output_d << it3->Current()->GetIdDzialu();
        output_d << ";";
        output_d << it3->Current()->GetNazwa();
        output_d << ";";
        output_d << it3->Current()->GetIdDzialuNad();
        output_d << ";";
        wyplata = it3->Current()->GetPrzychod();
        output_d << to_string(wyplata);
        output_d << endl;
    }
}