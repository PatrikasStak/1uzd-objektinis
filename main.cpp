#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>


using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Studentas {
    string vardas, pavarde;
    double* nd= nullptr;
    int nd_kiek=0;
    double egz;

    ~Studentas() { delete[] nd; }

};

void Skaityti(Studentas*& X, int &s){
    X = nullptr;
    s=0;
    string line;
    while(true){
        cout<<"Iveskite studento "<<s+1<<" varda: ";
        getline(cin, line);
        if (line.empty()) break;
        
        Studentas* temp = new Studentas[s+1];
        for(int i=0; i<s; i++){
            temp[i] = X[i];
        }
        delete[] X;
        X = temp;

        X[s].vardas = line;

        cout<<"Iveskite "<<s+1<<" studento pavarde: ";
        getline(cin, X[s].pavarde);

        X[s].nd = nullptr;
        X[s].nd_kiek = 0;

        int j=0;
        while(true){
            cout<<"Iveskite "<<s+1<<" studento "<<j+1<<" namu darbu pazymi (enter kad baigti): ";
            getline(cin, line);
            if(line.empty())break;

            double* nd_temp = new double[j+1];
            for(int i=0;i<j;i++){
                nd_temp[i]=X[s].nd[i];
            }
                delete[] X[s].nd;
                X[s].nd=nd_temp;

                X[s].nd[j]=std::stod(line);
                j++;
        }
            X[s].nd_kiek=j;

            cout<<"Iveskite "<<s+1<<" studento egzaminu pazymi: ";
            getline(cin, line);
            X[s].egz=std::stod(line);
            s++;
        
    }

}

double Vidurkis(Studentas* X, int x){
    double sum=0.0;
    for(int i=0;i<X[x].nd_kiek;i++){
        sum+=X[x].nd[i];
    }
    return sum/X[x].nd_kiek;
}

double Mediana(Studentas* X, int x){
    if(X[x].nd_kiek%2==0){
        return (X[x].nd[X[x].nd_kiek/2-1]+X[x].nd[X[x].nd_kiek/2])/2.0;
    }
    else{
        return X[x].nd[X[x].nd_kiek/2];
    }
}

void Rezultatas(Studentas* X, int s){
    cout<<"Mediana ar vidurkis? (m/v): ";
    string pasirinkimas;
    cin >> pasirinkimas;
    std::transform(pasirinkimas.begin(), pasirinkimas.end(), pasirinkimas.begin(),
               [](unsigned char c){ return std::tolower(c); });

    if(pasirinkimas=="m"||pasirinkimas=="mediana"){
        for(int i=0;i<s;i++){
            cout<<X[i].vardas<<" "<<X[i].pavarde<<": "<<std::fixed<<std::setprecision(2)<<Mediana(X,i)*0.4+X[i].egz*0.6<<endl;
        }
    }
    else{
    for(int i=0;i<s;i++){
        cout<<X[i].vardas<<" "<<X[i].pavarde<<": "<<std::fixed<<std::setprecision(2)<<Vidurkis(X,i)*0.4+X[i].egz*0.6<<endl;
    }
    }

}





int main() {
    Studentas* A = nullptr;
    int s=0; //studentu skaicius
    Skaityti(A,s);
    Rezultatas(A,s);
    return 0;
}