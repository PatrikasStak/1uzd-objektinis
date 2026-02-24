#ifndef FUNCV_H
#define FUNCV_H

#include "lib.h"

struct Studentas {
    std::string vardas, pavarde;
    std::vector<int> nd;
    int egz;

};

void Skaityti(std::vector<Studentas>& X);
double Vidurkis(const std::vector<Studentas>& X, int x);
double Mediana(const std::vector<Studentas>& X, int x);
void Rezultatas(const std::vector<Studentas>& X);

#endif