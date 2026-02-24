#ifndef FUNCM_H
#define FUNCM_H

#include "lib.h"

struct Studentas {
    std::string vardas, pavarde;
    int* nd = nullptr;
    int nd_kiek = 0;
    int egz;
    ~Studentas() { delete[] nd; }
};

void Skaityti(Studentas*& X, int& s);
double Vidurkis(const Studentas* X, int x);
double Mediana(const Studentas* X, int x);
void Rezultatas(const Studentas* X, int s);

#endif
