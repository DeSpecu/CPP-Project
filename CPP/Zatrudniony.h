#pragma once
#include "Pracownik.h"
#include "Dzial.h"

class Zatrudniony : public Pracownik, public Dzial
{
private:
    double Wyplata;

public:
    double GetWyplata();

    void  SetWyplata(double item);

    void Rewaloryzuj_p(double procent);

    void Rewaloryzuj_by_przychod(double przychod, double procent);

    void Zatrudnij();

    void Edytuj();

    void PokazDane();
};