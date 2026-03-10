#include "func.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<Studentas> A;
    std::cout<<"1 - vesti ranka, 2 - skaityti iš failo, 3 - generuoti failus: ";
    std::string choice;
    while(true){
    getline(std::cin, choice);
    if(choice=="1"||choice=="2"||choice=="3")break;
    std::cerr<<"Neteisinga ivestis, bandykite dar karta: ";
    }
    if(choice=="1"){
    Skaityti(A);
    Rezultatas(A);
    }
    else if(choice=="2"){
        SkaitytiFaila(A);
        RezultatasFailo(A);
    }
    else if(choice=="3"){
        FailuGeneravimas();
    }
    return 0;
}