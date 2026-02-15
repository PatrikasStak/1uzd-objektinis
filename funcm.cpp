#include "funcm.h"

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::string;
using std::sort;

void Skaityti(Studentas*& X, int &s){
    X = nullptr;
    s=0;
    string line;
    while(true){
        cout<<"Iveskite "<<s+1<<" studento varda (enter kad baigti): ";
        getline(cin, line);
        if (line.empty()) break;
        
        Studentas* temp = new Studentas[s+1];
        for(int i=0; i<s; i++){
            temp[i].vardas = X[i].vardas;
            temp[i].pavarde = X[i].pavarde;
            temp[i].nd_kiek = X[i].nd_kiek;
            temp[i].egz = X[i].egz;
            if(X[i].nd_kiek > 0){
                temp[i].nd = new double[X[i].nd_kiek];
                for(int k=0; k<X[i].nd_kiek; k++){
                    temp[i].nd[k] = X[i].nd[k];
                }
            }
        }
        delete[] X;
        X = temp;

        X[s].vardas = line;

        cout<<"Iveskite "<<s+1<<" studento pavarde: ";
        getline(cin, X[s].pavarde);

        X[s].nd = nullptr;
        X[s].nd_kiek = 0;

        int j=0;
        bool random_hw = false;
        while(true){
            if(j==0){
            cout<<"Iveskite "<<s+1<<" studento "<<j+1<<" namu darbu pazymi (enter kad baigti, r kad random): ";
            }
            else{
                cout<<"Iveskite "<<s+1<<" studento "<<j+1<<" namu darbu pazymi (enter kad baigti): ";
            }
            getline(cin, line);
            if(line.empty())break;
            if(line=="r"&&j==0){
                j = rand() % 10 + 1; // 1-10 namu darbu pazymiu
                delete[] X[s].nd;
                X[s].nd = new double[j];
                for(int i=0; i<j; i++){
                    X[s].nd[i] = rand() % 10 + 1; // pazymiai 1-10
                }
                X[s].nd_kiek=j;
                cout<<"Sugeneruoti "<<s+1<<" studento namu darbu pazymiai:";
                for(int i=0;i<j;i++){
                    cout<<" "<<X[s].nd[i];
                }
                cout<<endl;
                X[s].egz=rand() % 10 + 1;
                cout<<"Sugeneruotas "<<s+1<<" studento egzamino pazymys: "<<X[s].egz<<endl;
                random_hw = true;
                break;
            }
            else {
                try{
                    double* nd_temp = new double[j+1];
                    for(int i=0;i<j;i++){
                        nd_temp[i]=X[s].nd[i];
                    }
                    delete[] X[s].nd;
                    X[s].nd=nd_temp;

                    X[s].nd[j]=std::stod(line);
                    j++;
                }catch(...){}
            }
        }

        X[s].nd_kiek = j;
        if(!random_hw){
            while(true){
                cout<<"Iveskite "<<s+1<<" studento egzamino pazymi: ";
                getline(cin, line);
                try{
                    X[s].egz=std::stod(line);
                    break;
                }catch(...){}
            }
        }

        s++;
    }
}

double Vidurkis(const Studentas* X, int x){
    double sum=0.0;
    for(int i=0;i<X[x].nd_kiek;i++){
        sum+=X[x].nd[i];
    }
    return sum/X[x].nd_kiek;
}

double Mediana(const Studentas* X, int x){
    sort(X[x].nd, X[x].nd + X[x].nd_kiek);
    if(X[x].nd_kiek%2==0){
        return (X[x].nd[X[x].nd_kiek/2-1]+X[x].nd[X[x].nd_kiek/2])/2.0;
    }
    else{
        return X[x].nd[X[x].nd_kiek/2];
    }
}

void Rezultatas(const Studentas* X, int s){
    cout<<"Mediana ar vidurkis? (m/v): ";
    string pasirinkimas;
    getline(cin, pasirinkimas);
    std::transform(pasirinkimas.begin(), pasirinkimas.end(), pasirinkimas.begin(),
               [](unsigned char c){ return std::tolower(c); });
    
    size_t w1 = string("Vardas").size();
    size_t w2 = string("Pavarde").size();

    for(int i=0;i<s;++i){
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
        for(int i=0;i<s;i++){
            cout<<left<<setw(w1)<<X[i].vardas<<setw(w2)<<X[i].pavarde<<setw(12)<<std::fixed<<std::setprecision(2)<<Mediana(X,i)*0.4+X[i].egz*0.6<<endl;
        }
    }
    else{
    for(int i=0;i<s;i++){
        cout<<left<<setw(w1)<<X[i].vardas<<setw(w2)<<X[i].pavarde<<setw(12)<<std::fixed<<std::setprecision(2)<<Vidurkis(X,i)*0.4+X[i].egz*0.6<<endl;
    }
    }

}
