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
        TrintiFaila("generuoti1000.txt");
        TrintiFaila("generuoti10000.txt");
        TrintiFaila("generuoti100000.txt");
        TrintiFaila("generuoti1000000.txt");
        TrintiFaila("generuoti10000000.txt");
        FailuGeneravimas();
        while(true){
            std::cout<<"Kuri faila rusioti? 1 - generuoti1000.txt 2 - generuoti10000.txt 3 - generuoti100000.txt 4 - generuoti1000000.txt 5 - generuoti10000000.txt 6 - baigti \n";
            if(choice=="1"||choice=="2"||choice=="3"||choice=="4"||choice=="5"||choice=="6"){
            getline(std::cin, choice);
            if(choice=="1")GeneruotuRusiavimas("generuoti1000.txt");
            else if(choice=="2")GeneruotuRusiavimas("generuoti10000.txt");
            else if(choice=="3")GeneruotuRusiavimas("generuoti100000.txt");
            else if(choice=="4")GeneruotuRusiavimas("generuoti1000000.txt");
            else if(choice=="5")GeneruotuRusiavimas("generuoti10000000.txt");
            else if(choice=="6")break;
            }
            else std::cerr<<"Neteisinga ivestis! \n";
        }
    }
    return 0;
}