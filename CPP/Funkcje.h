#pragma once
#include<string>

using namespace std;

void PokazWszystkieDzialy();

void UsunDzial();

void ustawIDusunietego(string IDu, string IDnu);

void EdytujDzial();

double GetPrzychodDzialu(string IDDp);

void rewaloryzuj_place_dzialu_by_przychod(string IDP, double procent);

void rewaloryzuj_place_dzialu_by_przychod_podrzednego(string IDDp, double procent);

void rewaloryzuj_place_dzialu(string IDP, double procent);

void rewaloryzuj_place_dzialu_podrzednego(string IDDp, double procent);

void get_dzialy_podrzedne(string IDDp);

int klawisz();

void czekaj();

void rewaloryzacja_plac();

int menu_glowne();

void wczytajdzialy();

void zapisz();

void PokazZatrudnionychPracownikow();

void UsunPracownika();

void EdytujPracownika();

void wczytajpracownikow();