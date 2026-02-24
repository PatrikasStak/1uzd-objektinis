#include "funcv.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<Studentas> A;
    std::cout<<"1 - vesti ranka, 2 - skaityti iš failo: ";
    std::string choice;
    getline(std::cin, choice);
    if(choice=="1"){
    Skaityti(A);
    Rezultatas(A);
    }
    else if(choice=="2"){
        std::cout<<"Kokį failą norite skaityti? ";
        getline(std::cin, choice);
        SkaitytiFaila(A,choice);
        Rezultatas(A);
    }
    return 0;
}