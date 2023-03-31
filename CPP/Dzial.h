#pragma once
#include<iostream>
using namespace std;

class Dzial
{
private:
    string IdDzialu;
    string Nazwa;
    string IdDzialuNad;
    double Przychod;

public:

    string GetIdDzialu();

    string GetNazwa();

    string GetIdDzialuNad();

    double GetPrzychod();

    void  SetIdDzialu(string);

    void  SetNazwa(string item);

    void  SetIdDzialuNad(string item);

    void  SetPrzychod(double item);

    void Edytuj();

    void Wypelnij();

    void PokazDane();
};