
#include "funcm.h"

int main() {
    std::srand(std::time(nullptr));
    Studentas* A = nullptr;
    int s=0; //studentu skaicius
    Skaityti(A,s);
    Rezultatas(A,s);
    return 0;
}