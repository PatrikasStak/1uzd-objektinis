#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Studentas {
    string vardas, pavarde;
    int nd[10], egz;
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

void Rezultatas(Studentas X[], int s, int n){
    for(int i=0;i<s;i++){
        cout<<X[i].vardas<<" "<<X[i].pavarde<<" "<<Vidurkis(X,n,i)*0.4+(double)X[i].egz*0.6<<endl;
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