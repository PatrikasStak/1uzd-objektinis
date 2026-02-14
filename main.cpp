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
    double nd[10], egz;
};

void Skaityti(Studentas X[], int &s, int &n){
    cout<<"Iveskite studentu skaiciu: ";
    cin >> s;
    cout<<"Iveskite nd skaiciu: ";
    cin >> n;
    for(int i=0;i<s;i++){
        cout<<"Iveskite "<<i+1<<" studento varda: ";
        cin >> X[i].vardas;
        cout<<"Iveskite "<<i+1<<" studento pavarde: ";
        cin >> X[i].pavarde;
        for(int j=0;j<n;j++){
            cout<<"Iveskite "<<i+1<<" studento "<<j+1<<" nd: ";
            cin >> X[i].nd[j];
        }
        cout<<"Iveskite "<<i+1<<" studento egzamino rezultata: ";
        cin >> X[i].egz;
    }
}

double Vidurkis(Studentas X[], int n, int x){
    double sum=0.0;
    for(int i=0;i<n;i++){
        sum+=X[x].nd[i];
    }
    return sum/n;
}

double Mediana(Studentas X[], int n, int x){
    std::sort(X[x].nd, X[x].nd + n);
    if(n%2==0){
        return (X[x].nd[n/2-1]+X[x].nd[n/2])/2.0;
    }
    else{
        return X[x].nd[n/2];
    }
}

void Rezultatas(Studentas X[], int s, int n){
    cout<<"Mediana ar vidurkis? (m/v): ";
    string pasirinkimas;
    cin >> pasirinkimas;
    std::transform(pasirinkimas.begin(), pasirinkimas.end(), pasirinkimas.begin(),
               [](unsigned char c){ return std::tolower(c); });

    if(pasirinkimas=="m"||pasirinkimas=="mediana"){
        for(int i=0;i<s;i++){
            cout<<X[i].vardas<<" "<<X[i].pavarde<<": "<<std::fixed<<std::setprecision(2)<<Mediana(X,n,i)*0.4+X[i].egz*0.6<<endl;
        }
    }
    else{
    for(int i=0;i<s;i++){
        cout<<X[i].vardas<<" "<<X[i].pavarde<<": "<<std::fixed<<std::setprecision(2)<<Vidurkis(X,n,i)*0.4+X[i].egz*0.6<<endl;
    }
    }

}





int main() {
    Studentas A[100];
    int s; //studentu skaicius
    int n; //nd skaicius
    Skaityti(A,s,n);
    Rezultatas(A,s,n);
    return 0;
}