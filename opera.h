//
// Created by Bogdan on 5/19/2024.
//

#ifndef TEMA3_OPERA_H
#define TEMA3_OPERA_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "spectacol.h"
using namespace std;


class Opera:public Spectacol{
private:
    int durata_pauza_opera;
    int nr_acte;
    vector <int> durate_acte;
    string nume_solist;
    string rol_solist;


public:
    Opera(){
        setTip("opera");
    }

    Opera(const Circ& circ) {
        setNume(circ.getNume());
        setGen(circ.getGen());
        setTip("opera");
        setDurataFaraPauza(circ.getDurataFaraPauza());
        setDurataCuPauza(circ.getDurataCuPauza());
        setLocuriLibere(circ.getLocuriLibere());
        setLocuriTotal(circ.getlocuriTotal());
        setNumarPrezentari(circ.getNumarPrezentari());
    }

    Opera& operator=(const Opera& other) {
        if (this != &other) {
            Spectacol::operator=(other);
        }
        return *this;
    }

    Opera& operator=(const Circ& circ) {
        setNume(circ.getNume());
        setGen(circ.getGen());
        setTip("opera");
        setDurataFaraPauza(circ.getDurataFaraPauza());
        setDurataCuPauza(circ.getDurataCuPauza());
        setLocuriLibere(circ.getLocuriLibere());
        setLocuriTotal(circ.getlocuriTotal());
        setNumarPrezentari(circ.getNumarPrezentari());

        return *this;
    }

    void setNumeSolist(string nume){
        nume_solist=nume;
    }

    string getNumeSolist() const{
        return nume_solist;
    }

    void setRolSolist(string rol){
        rol_solist=rol;
    }

    string getRolSolist() const{
        return rol_solist;
    }

    string getTip() const override { return "opera"; }

    istream& citireSpectacol(istream& in);
    ostream& afisareSpectacol(ostream& out);
};

istream& Opera::citireSpectacol(std::istream &in) {
    string tip,gen,nume_spectacol,mesaj;
    int durata_act,suma_acte=0,locuri_total,locuri_libere,numar_prezentari;

    in.ignore();
    cout<<"nume spectacol: ";
    getline(in,nume_spectacol);
    setNume(nume_spectacol);

    cout<<"gen: ";
    getline(in,gen);
    setGen(gen);

    mesaj="numar acte: ";
    exceptie(in,nr_acte,mesaj);

    durate_acte.clear();
    for(int i=0;i<nr_acte;i++) {
        mesaj="durata act(minute): ";
        exceptie(in,durata_act,mesaj);
        durate_acte.push_back(durata_act);
        suma_acte+=durata_act;
    }
    setDurataFaraPauza(suma_acte);

    mesaj="durata pauza(minute): ";
    exceptie(in,durata_pauza_opera,mesaj);
    in.ignore();
    setDurataCuPauza(suma_acte+(nr_acte-1)*durata_pauza_opera);

    cout<<"nume solist: ";
    getline(in,nume_solist);
    setNumeSolist(nume_solist);


    while(true){
        try{
            cout<<"rol solist(bass/tenor/bariton): ";
            in>>rol_solist;
            if(rol_solist!="bass"&& rol_solist!="tenor"&& rol_solist!="tenor")
                throw string("Rol solist invalid");
            else break;

        }
        catch(string s){
            cout<<s<<endl;
        }
    }
    setRolSolist(rol_solist);

    mesaj="locuri total: ";
    exceptie(in,locuri_total,mesaj);
    setLocuriTotal(locuri_total);

    mesaj="locuri libere: ";
    exceptie(in,locuri_libere,mesaj);
    setLocuriLibere(locuri_libere);

    mesaj="numar prezentari: ";
    exceptie(in,numar_prezentari,mesaj);
    setNumarPrezentari(numar_prezentari);

    return in;
}

ostream& Opera::afisareSpectacol(std::ostream &out) {
    out<<"Spectacolul se numeste: "<<getNume()<<endl;
    out<<"Tipul spectacolului este: "<<getTip()<<endl;
    out<<"Genul spectacolului este: "<<getGen()<<endl;
    out<<"Spectacolul are "<<nr_acte<<" acte"<<endl;
    out<<"Spectacolul dureaza "<<getDurataFaraPauza()<<" minute fara pauze si "<<getDurataCuPauza()<<" minute cu pauze"<<endl;
    int index=1;
    for(const auto& element:durate_acte) {
        out << "Actul " << index << " dureaza " << element << " minute.";
        index++;
    }
    out<<endl;
    out<<"Solistul se numeste "<<getNumeSolist()<<endl;
    out<<"Solistul are rolul de "<<getRolSolist()<<endl;
    if(getLocuriLibere()>0)
        out<<"Spectacolul are "<<getlocuriTotal()<<" locuri in total, dintre care mai sunt disponibile "<<getLocuriLibere()<<" locuri"<<endl;
    else
        out<<"Nu mai sunt bilete disponibile la acest spectacol"<<endl;
    out<<"Spectacolul are "<<getNumarPrezentari()<<" reprezentari aceasta luna"<<endl;
    return out;
}

#endif //TEMA3_OPERA_H
