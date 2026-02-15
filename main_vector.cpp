#include "funcv.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<Studentas> A;
    Skaityti(A);
    Rezultatas(A);
    return 0;
}