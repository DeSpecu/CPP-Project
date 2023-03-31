#pragma once
#include<iostream>
using namespace std;

class Pracownik
{
private:
    string ID;
    string imie;
    string nazwisko;

public:
    string GetID();
    string GetImie();
    string GetNazwisko();
    void SetID(string item);
    void SetImie(string item);
    void SetNazwisko(string item);
    void WypelnijDane();
};