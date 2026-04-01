#ifndef FUNC_H
#define FUNC_H

#include "lib.h"

struct Studentas {
    std::string vardas, pavarde;
    std::vector<int> nd;
    int egz;
    double galutinis_vid;
    double galutinis_med;

};


using StudentVec = std::vector<Studentas>;
using StudentList = std::list<Studentas>;
using StudentDeque = std::deque<Studentas>;

void Skaityti(std::vector<Studentas>& X);
void SkaitytiFaila(std::vector<Studentas>& X);
double Vidurkis(const std::vector<Studentas>& X, int x);
double Mediana(const std::vector<Studentas>& X, int x);
void Rezultatas(std::vector<Studentas>& X);
void RezultatasFailo(std::vector<Studentas>& X);
void FailuGeneravimas();
void GeneruotuRusiavimasVec(const std::string& path, int strategija);
void GeneruotuRusiavimasList(const std::string& path, int strategija);
void GeneruotuRusiavimasDeque(const std::string& path, int strategija);
void TrintiFaila(const std::string& path);

#endif
