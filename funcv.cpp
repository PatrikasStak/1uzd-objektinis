#include "funcv.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::left;
using std::setw;
using std::vector;

void Skaityti(vector<Studentas>& X){
    string line;
    int i=0;
    while(true){
        cout<<"Iveskite "<<i+1<<" studento varda (enter kad baigti): ";
        getline(cin,line);
        if(line.empty())break;
        Studentas naujas;
        naujas.vardas=line;
        cout<<"Iveskite "<<i+1<<" studento pavarde: ";
        getline(cin, naujas.pavarde);
        int j=0;
        bool random_hw = false;
        while(true){
            cout<<"Iveskite "<<i+1<<" studento "<<j+1<<" namu darbu pazymi (enter kad baigti/r kad random): ";
            getline(cin, line);
            if(line.empty())break;
            if(line=="r"){
                j = rand() % 10 + 1; // 1-10 namu darbu pazymiu
                naujas.nd.clear();
                for(int k=0; k<j; k++){
                    naujas.nd.push_back(rand() % 10 + 1); // pazymiai 1-10
                }
                cout<<"Sugeneruoti "<<i+1<<" studento namu darbu pazymiai:";
                for(int k=0;k<j;k++){
                    cout<<" "<<naujas.nd[k];
                }
                cout<<endl;
                naujas.egz=rand() % 10 + 1;
                cout<<"Sugeneruotas "<<i+1<<" studento egzamino pazymys: "<<naujas.egz<<endl;
                random_hw = true;
                break;
            }
            else{
            try{
            naujas.nd.push_back(std::stod(line));
            j++;
            }catch(...){}
        }
        }
        if(!random_hw){
        while(true){
        cout<<"Iveskite "<<i+1<<" studento egzamino pazymi: ";
        getline(cin, line);
        try{
        naujas.egz = std::stod(line);
        break;
        }catch(...){}
        }
    }
        X.push_back(naujas);
        i++;
    }

}

double Vidurkis(const vector<Studentas>& X, int x){
    double sum=0.0;
    for(size_t i=0;i<X[x].nd.size();i++){
        sum+=X[x].nd[i];
    }
    return sum/X[x].nd.size();
}

double Mediana(const vector<Studentas>& X, int x){
    std::vector<double> temp = X[x].nd;
    std::sort(temp.begin(), temp.end());
    if (temp.size() % 2 == 0) {
        return (temp[temp.size()/2 - 1] + temp[temp.size()/2]) / 2.0;
    } else {
        return temp[temp.size()/2];
    }
}

void Rezultatas(const vector<Studentas>& X){
    cout<<"Mediana ar vidurkis? (m/v): ";
    string pasirinkimas;
    cin >> pasirinkimas;
    std::transform(pasirinkimas.begin(), pasirinkimas.end(), pasirinkimas.begin(),
               [](unsigned char c){ return std::tolower(c); });
    
    size_t w1 = string("Vardas").size();
    size_t w2 = string("Pavarde").size();

    for(int i=0;i<X.size();++i){
        w1=std::max(w1, X[i].vardas.size());
        w2=std::max(w2, X[i].pavarde.size());
    }

    w1+=2;
    w2+=2;
    
    if(pasirinkimas=="m"||pasirinkimas=="mediana"){
        cout<<left<<setw(w1)<<"Vardas"<<setw(w2)<<"Pavarde"<<setw(12)<<"Galutinis (Med.)"<<endl;
    }
    else{
        cout<<left<<setw(w1)<<"Vardas"<<setw(w2)<<"Pavarde"<<setw(12)<<"Galutinis (Vid.)"<<endl;
    }
    for(int i=0;i<w1+w2+16;i++){
        cout<<"-";
    }
    cout<<endl;

    if(pasirinkimas=="m"||pasirinkimas=="mediana"){
        for(int i=0;i<X.size();i++){
            cout<<left<<setw(w1)<<X[i].vardas<<setw(w2)<<X[i].pavarde<<setw(12)<<std::fixed<<std::setprecision(2)<<Mediana(X,i)*0.4+X[i].egz*0.6<<endl;
        }
    }
    else{
    for(int i=0;i<X.size();i++){
        cout<<left<<setw(w1)<<X[i].vardas<<setw(w2)<<X[i].pavarde<<setw(12)<<std::fixed<<std::setprecision(2)<<Vidurkis(X,i)*0.4+X[i].egz*0.6<<endl;
    }
    }

}