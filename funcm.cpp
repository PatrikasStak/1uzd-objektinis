#include "funcm.h"
#include "namesm.h"

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
    srand(time(0));
    while(true){
        while(true){
            cout<<"Pasirinkite kaip norite ivesti duomenis: 1 - ranka, 2 - random pazymiai, 3 - viskas random, 4 - baigti"<<endl;
            getline(cin, line);
            if(line=="1" || line=="2" || line=="3" || line=="4") break;
            cout<<"Neteisinga ivestis. Iveskite 1, 2, 3 arba 4."<<endl;
        }
        if(line=="1"){
        cout<<"Iveskite "<<s+1<<" studento varda: ";
        getline(cin, line);
        
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
        while(true){
            cout<<"Iveskite "<<s+1<<" studento "<<j+1<<" namu darbu pazymi (enter kad baigti): ";
            getline(cin, line);
            if(line.empty()){
                if(j==0){
                    cout<<"Reikia ivesti bent viena pazymi."<<endl;
                    continue;
                }
                break;
            }
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

        X[s].nd_kiek = j;
            while(true){
                cout<<"Iveskite "<<s+1<<" studento egzamino pazymi: ";
                getline(cin, line);
                try{
                    X[s].egz=std::stod(line);
                    break;
                }catch(...){}
            }
    }
    else if(line=="2"){
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
        cout<<"Iveskite "<<s+1<<" studento varda: ";
        getline(cin, X[s].vardas);

        cout<<"Iveskite "<<s+1<<" studento pavarde: ";
        getline(cin, X[s].pavarde);

        X[s].nd_kiek = 0;
        int j = rand() % 10 + 1; // 1-10 namu darbu pazymiu
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
    }
    else if(line=="3"){
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
        int lytis = rand() % 2;//0 - moteris ; 1 - vyras
        if(lytis==0){
            int vardu_kiek = sizeof(vardai_mot) / sizeof(vardai_mot[0]);
            int pavardziu_kiek = sizeof(pavardes_mot) / sizeof(pavardes_mot[0]);
            X[s].vardas=vardai_mot[rand() % vardu_kiek];
            X[s].pavarde=pavardes_mot[rand() % pavardziu_kiek];
        }
        else{
            int vardu_kiek = sizeof(vardai_vyr) / sizeof(vardai_vyr[0]);
            int pavardziu_kiek = sizeof(pavardes_vyr) / sizeof(pavardes_vyr[0]);
            X[s].vardas=vardai_vyr[rand() % vardu_kiek];
            X[s].pavarde=pavardes_vyr[rand() % pavardziu_kiek];
        }

       int j = rand() % 10 + 1; // 1-10 namu darbu pazymiu
        delete[] X[s].nd;
        X[s].nd = new double[j];
        for(int i=0; i<j; i++){
            X[s].nd[i] = rand() % 10 + 1; // pazymiai 1-10
        }
        X[s].nd_kiek=j;
        cout<<"Sugeneruotas "<<s+1<<" studento vardas ir pavardė: "<<X[s].vardas<<" "<<X[s].pavarde<<endl;
        cout<<"Sugeneruoti "<<s+1<<" studento namu darbu pazymiai:";
        for(int i=0;i<j;i++){
            cout<<" "<<X[s].nd[i];
        }
        cout<<endl;
        X[s].egz=rand() % 10 + 1;
        cout<<"Sugeneruotas "<<s+1<<" studento egzamino pazymys: "<<X[s].egz<<endl;
    }
    else if(line=="4")break;
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
    std::fill_n(std::ostream_iterator<char>(cout), w1 + w2 + 16, '-');
    cout << endl;

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
