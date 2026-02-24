#include "funcv.h"
#include "namesv.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::left;
using std::setw;
using std::vector;

void Skaityti(vector<Studentas>& X){
    string line;
    int s=0;
    srand(time(0));
    while(true){
        while(true){
            cout<<"Pasirinkite kaip norite ivesti duomenis: 1 - ranka, 2 - random pazymiai, 3 - viskas random, 4 - baigti"<<endl;
            getline(cin, line);
            if(line=="1" || line=="2" || line=="3" || line=="4") break;
            cout<<"Neteisinga ivestis. Iveskite 1, 2, 3 arba 4."<<endl;
        }
        if(line=="4") break;

        Studentas naujas;
        if(line=="1"){
            cout<<"Iveskite "<<s+1<<" studento varda: ";
            getline(cin, naujas.vardas);
            cout<<"Iveskite "<<s+1<<" studento pavarde: ";
            getline(cin, naujas.pavarde);
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
                    naujas.nd.push_back(std::stod(line));
                    j++;
                }catch(...){}
            }
            while(true){
                cout<<"Iveskite "<<s+1<<" studento egzamino pazymi: ";
                getline(cin, line);
                try{
                    naujas.egz = std::stod(line);
                    break;
                }catch(...){}
            }
        }
        else if(line=="2"){
            cout<<"Iveskite "<<s+1<<" studento varda: ";
            getline(cin, naujas.vardas);
            cout<<"Iveskite "<<s+1<<" studento pavarde: ";
            getline(cin, naujas.pavarde);
            int j = rand() % 10 + 1; // 1-10 namu darbu pazymiu
            for(int k=0; k<j; k++){
                naujas.nd.push_back(rand() % 10 + 1); // pazymiai 1-10
            }
            cout<<"Sugeneruoti "<<s+1<<" studento namu darbu pazymiai:";
            for(int k=0;k<j;k++){
                cout<<" "<<naujas.nd[k];
            }
            cout<<endl;
            naujas.egz=rand() % 10 + 1;
            cout<<"Sugeneruotas "<<s+1<<" studento egzamino pazymys: "<<naujas.egz<<endl;
        }
        else if(line=="3"){
            int kiek;
            cout<<"Kiek studentų norite sugeneruoti? ";
            while(!(cin>>kiek)){
                cout<<"Iveskite sveika skaiciu. Bandykite dar karta: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<endl;
            for(int i=0;i<kiek;i++){
            int lytis = rand() % 2; // 0 - moteris ; 1 - vyras
            if(lytis == 0){
                int vardu_kiek = static_cast<int>(vardai_mot.size());
                int pavardziu_kiek = static_cast<int>(pavardes_mot.size());
                naujas.vardas = vardai_mot[rand() % vardu_kiek];
                naujas.pavarde = pavardes_mot[rand() % pavardziu_kiek];
            }
            else{
                int vardu_kiek = static_cast<int>(vardai_vyr.size());
                int pavardziu_kiek = static_cast<int>(pavardes_vyr.size());
                naujas.vardas = vardai_vyr[rand() % vardu_kiek];
                naujas.pavarde = pavardes_vyr[rand() % pavardziu_kiek];
            }
            int j = rand() % 10 + 1; // 1-10 namu darbu pazymiu
            for(int k=0; k<j; k++){
                naujas.nd.push_back(rand() % 10 + 1); // pazymiai 1-10
            }
            cout<<"Sugeneruotas "<<s+1<<" studento vardas ir pavardė: "<<naujas.vardas<<" "<<naujas.pavarde<<endl;
            cout<<"Sugeneruoti "<<s+1<<" studento namu darbu pazymiai:";
            for(int k=0;k<j;k++){
                cout<<" "<<naujas.nd[k];
            }
            cout<<endl;
            naujas.egz=rand() % 10 + 1;
            cout<<"Sugeneruotas "<<s+1<<" studento egzamino pazymys: "<<naujas.egz<<endl;
            X.push_back(naujas);
            s++;
        }
    }
    if(line!="3"){
        X.push_back(naujas);
        s++;
    }
    }

}

void SkaitytiFaila(vector<Studentas>& X, const std::string& path){
    string header;
    std::ifstream in(path);
    std::stringstream ss;
    ss<<in.rdbuf();
    getline(ss, header);
    while(true){
        Studentas naujas;
        if(!(ss>>naujas.vardas>>naujas.pavarde))break;
        naujas.nd.clear();
        for(int i=0;i<15;i++){
            int nd;
            if(!(ss >> nd)){
                cout << "Klaida skaitant ND (truksta duomenu)." << endl;
                return;
            }
            naujas.nd.push_back(nd);
        }
        if(!(ss >> naujas.egz)){
            cout << "Klaida skaitant egzamina (truksta duomenu)." << endl;
            return;
        }
        X.push_back(naujas);
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
    std::vector<int> temp = X[x].nd;
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
    getline(cin, pasirinkimas);
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
    std::fill_n(std::ostream_iterator<char>(cout), w1 + w2 + 16, '-');
    cout << endl;

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
