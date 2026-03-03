#include "func.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<Studentas> A;
    std::cout<<"1 - vesti ranka, 2 - skaityti iš failo: ";
    std::string choice;
    while(true){
    getline(std::cin, choice);
    if(choice=="1"||choice=="2")break;
    std::cerr<<"Neteisinga ivestis, bandykite dar karta: ";
    }
    if(choice=="1"){
    Skaityti(A);
    Rezultatas(A);
    }
    else if(choice=="2"){
        std::cout<<"Kokį failą norite skaityti? ";
        system("ls -1 *.txt | grep -v '^rez.txt$'");
        auto t1 = std::chrono::high_resolution_clock::now();
        auto t2 = std::chrono::high_resolution_clock::now();
        while (true){
            getline(std::cin, choice);
            A.clear();
            t1 = std::chrono::high_resolution_clock::now();
            if(SkaitytiFaila(A,choice)){
                t2 = std::chrono::high_resolution_clock::now();
                break;
            }
            system("ls -1 *.txt | grep -v '^rez.txt$'");
            std::cerr<<"Bandykite įvesti failo pavadinima vėl: ";

            
        }
        RezultatasFailo(A);
        std::chrono::duration<double> dt = t2 - t1;
        std::cout << "Laikas: " <<std::fixed<<std::setprecision(5)<< dt.count() << " s\n";
    }
    return 0;
}