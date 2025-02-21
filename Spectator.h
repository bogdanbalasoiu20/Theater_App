//
// Created by Bogdan on 5/19/2024.
//

#ifndef TEMA3_SPECTATOR_H
#define TEMA3_SPECTATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <limits>
#include "Circ.h"
#include "Opera.h"
#include "Teatru.h"
using namespace std;


class Spectator{
    string nume_spectator;
    int varsta;
    int bilete_dorite;
    static int index_spectator;

public:
    void setNume(string nume){
        nume_spectator=nume;
    }

    string getNume(){
        return nume_spectator;
    }

    void setVarsta(int varsta_spectator){
        varsta=varsta_spectator;
    }
    int getVarsta(){
        return varsta;
    }

    void setNrBilete(int nr_bilete){
        bilete_dorite=nr_bilete;
    }
    int getNrBilete(){
        return bilete_dorite;
    }


    friend istream& operator>>(istream& in,Spectator& spectator){
        string mesaj;

        cout<<"Introdu datele despre spectatorul "<<index_spectator<<": "<<endl;
        index_spectator++;
        in.ignore();

        cout<<"nume spectator: ";
        getline(in,spectator.nume_spectator);
        spectator.setNume(spectator.nume_spectator);

        while(true){
            try{
                cout<<"varsta: ";
                in>>spectator.varsta;
                if(spectator.varsta<0){
                    throw string("Numar invalid");
                }
                else{
                    break;
                }
            }
            catch (string s){
                cout<<s<<endl;
            }
        }
        spectator.setVarsta(spectator.varsta);


        while(true){
            try{
                cout<<"bilete dorite: ";
                in>>spectator.bilete_dorite;
                if(spectator.bilete_dorite<0){
                    throw string("Numar invalid");
                }
                else{
                    break;
                }
            }
            catch (string s){
                cout<<s<<endl;
            }
        }
        spectator.setNrBilete(spectator.bilete_dorite);

        return in;
    }

};

int Spectator::index_spectator=1;


class Exigente{
    string combinatie_nedorita;
    int durata_maxima;
    string doreste_animale;
    int spectatori_maxim;
    static int index_spectator;

public:
    void setCombinatie(string combinatie){
        combinatie_nedorita=combinatie;
    }

    string getCombinatie(){
        return combinatie_nedorita;
    }

    void setDurataMaxima(int durata){
        durata_maxima=durata;
    }

    int getDurataMaxima(){
        return durata_maxima;
    }

    void setDoresteAnimal(string raspuns){
        doreste_animale=raspuns;
    }

    string getDoresteAnimal(){
        return doreste_animale;
    }

    void setSpectatoriMaxim(int maxim){
        spectatori_maxim=maxim;
    }

    int getSpectatoriMaxim(){
        return spectatori_maxim;
    }



    friend istream& operator>>(istream& in,Exigente& e){
        return e.citireExigente(in);
    }

    istream& citireExigente(istream& in);

//    friend ostream& operator << (ostream& out, Exigente& e){
//        out<<e.getCombinatie()<<endl;
//        out<<e.getDurataMaxima()<<endl;
//        out<<e.getDoresteAnimal()<<endl;
//        out<<e.getSpectatoriMaxim()<<endl;
//        return out;
//    }

};

istream& Exigente::citireExigente(std::istream &in) {
    cout<<"Introdu exigentele:"<<endl;

    cout<<"combinatie nedorita: ";
    in.ignore();
    getline(in,combinatie_nedorita);
    setCombinatie(combinatie_nedorita);

    cout<<"durata maxima: ";
    in>>durata_maxima;
    setDurataMaxima(durata_maxima);
    //in.ignore(numeric_limits<streamsize>::max(), '\n');
    in.ignore();

    cout << "doreste animale(da/nu): ";
    getline(in,doreste_animale);
    setDoresteAnimal(doreste_animale);

    cout<<"numar maxim de spectatori: ";
    in>>spectatori_maxim;
    setSpectatoriMaxim(spectatori_maxim);
    //in.ignore(numeric_limits<streamsize>::max(), '\n');
    in.ignore();

    return in;
}

int Exigente::index_spectator=1;


class Pofte{
    string gen;
    string tip;
    int timp_minim_fara_pauze;
    static int index_spectator;

public:
    void setTip(string tip_spectacol){
        tip=tip_spectacol;
    }

    string getTip(){
        return tip;
    }

    void setTimpMinFaraPauze(int timp){
        timp_minim_fara_pauze=timp;
    }

    int getTimpMinFaraPauze(){
        return timp_minim_fara_pauze;
    }

    void setGen(string gen_spectacol){
        gen=gen_spectacol;
    }

    string getGen(){
        return gen;
    }

    void setIndex(){
        index_spectator++;
    }

    int getIndex(){
        return index_spectator;
    }

    friend istream& operator >> (istream& in,Pofte& pofte){
        return pofte.citirePofte(in);
    }

//    friend ostream& operator << (ostream& out,Pofte& pofte){
//        return pofte.afisarePofte(out);
//    }

   virtual void filtru(vector<Spectacol*>spectacole,Pofte* pofte,Exigente* exigente,Spectator* spectator){
        cout<<"nimic"<<endl;
    }

    virtual istream& citirePofte(istream& in)=0;
//    virtual ostream& afisarePofte(ostream& out)=0;

    void exceptie(istream& in,int &x,string mesaj){
        while(true){
            try{
                cout<<mesaj;
                in>>x;
                if(x<0){
                    throw string("Numar invalid");
                }
                else{
                    break;
                }
            }
            catch (string s){
                cout<<s<<endl;
            }
        }
    }

};

int Pofte::index_spectator=0;


class PofteCirc:public Pofte{
    string animal_dorit;
public:

    void setAnimalDorit(string animal){
        animal_dorit=animal;
    }

    string getAnimalDorit(){
        return animal_dorit;
    }

    PofteCirc(){
        setTip("circ");
        setGen("comedie");
    }

    void filtru(vector<Spectacol*>spectacole,Pofte* pofte,Exigente* exigente,Spectator* spectator);
    istream& citirePofte(istream& in);

//     ostream& afisarePofte(ostream& out){
//        out<<getTimpMinFaraPauze()<<endl;
//        out<<animal_dorit<<endl;
//        return out;
//    }


    friend class Exigente;
};

istream& PofteCirc::citirePofte(std::istream &in) {
    int timp_minim_fara_pauze;
    string mesaj;

    cout<<"Introdu poftele: "<<endl;

    mesaj="timp minim dorit: ";
    exceptie(in,timp_minim_fara_pauze,mesaj);
    setTimpMinFaraPauze(timp_minim_fara_pauze);

    //in.ignore(numeric_limits<streamsize>::max(), '\n');
    in.ignore();

    cout<<"animal dorit: ";
    getline(in,animal_dorit);
    setAnimalDorit(animal_dorit);

    return in;
}

class PofteOpera:public Pofte{
    int timp_minim_cu_pauze;
    string rol_solist_dorit;

public:
    void setTimpMinCuPauze(int timp_min){
        timp_minim_cu_pauze=timp_min;
    }

    int getTimpMinCuPauze(){
        return timp_minim_cu_pauze;
    }

    void setRolSolist(string rol_solist){
        rol_solist_dorit=rol_solist;
    }

    string getRolSolist(){
        return rol_solist_dorit;
    }

    PofteOpera(){ setTip("opera");}

    void filtru(vector<Spectacol*>spectacole,Pofte* pofte,Exigente* exigente,Spectator* spectator);

    istream& citirePofte(istream& in);

//     ostream& afisarePofte (ostream& out){
//        out<<getGen()<<endl;
//        out<<getTimpMinFaraPauze()<<endl;
//        out<<getTimpMinCuPauze()<<endl;
//        out<<getRolSolist();
//        return out;
//    }

    friend class Exigente;
};

istream& PofteOpera::citirePofte(istream &in) {
    int timp_minim_fara_pauze;
    string gen,mesaj;

    cout<<"Introdu poftele: "<<endl;

    in.ignore();
    cout<<"gen dorit: ";
    getline(in,gen);
    setGen(gen);

    mesaj="timp minim fara pauza dorit: ";
    exceptie(in,timp_minim_fara_pauze,mesaj);
    setTimpMinFaraPauze(timp_minim_fara_pauze);

    mesaj="timp minim cu pauza inclusa dorit: ";
    exceptie(in,timp_minim_cu_pauze,mesaj);
    setTimpMinCuPauze(timp_minim_cu_pauze);
    in.ignore();

    while(true){
        try{
            cout<<"rol solist(bass/tenor/bariton): ";
            in>>rol_solist_dorit;
            if(rol_solist_dorit!="bass"&& rol_solist_dorit!="tenor"&& rol_solist_dorit!="tenor")
                throw string("Rol solist invalid");
            else break;

        }
        catch(string s){
            cout<<s<<endl;
        }
    }
    setRolSolist(rol_solist_dorit);

    return in;
}

class PofteTeatru:public Pofte{
    string doreste_teatru_interactiv;

public:
    PofteTeatru(){setTip("teatru");}

    void setTeatruInteractiv(string raspuns){
        doreste_teatru_interactiv=raspuns;
    }

    string getTeatruInteractiv(){
        return doreste_teatru_interactiv;
    }

    void filtru(vector<Spectacol*>spectacole,Pofte* pofte,Exigente* exigente,Spectator* spectator);

    istream& citirePofte(istream& in);

//    ostream& afisarePofte(ostream& out){
//        out<<getGen()<<endl;
//        out<<getTimpMinFaraPauze()<<endl;
//        out<<doreste_teatru_interactiv<<endl;
//        return out;
//    }


    friend class Exigente;
};

istream& PofteTeatru::citirePofte(std::istream &in) {
    int timp_minim_fara_pauze;
    string mesaj,gen;

    cout<<"Introdu poftele: "<<endl;

    in.ignore();
    cout<<"gen dorit: ";
    getline(in,gen);
    setGen(gen);

    mesaj="timp minim dorit: ";
    exceptie(in,timp_minim_fara_pauze,mesaj);
    setTimpMinFaraPauze(timp_minim_fara_pauze);
    in.ignore();

    while(true) {
        try {
            cout << "teatru interactiv dorit(da/nu): ";
            getline(in, doreste_teatru_interactiv);
            if(doreste_teatru_interactiv!="da" && doreste_teatru_interactiv!="nu"){
                throw string("Raspuns invalid");
            }
            else{break;
            }
        }
        catch(string s){
            cout<<s<<endl;
        }
    }
    setTeatruInteractiv(doreste_teatru_interactiv);

    return in;
}

#endif //TEMA3_SPECTATOR_H
