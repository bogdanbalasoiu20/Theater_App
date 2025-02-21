//
// Created by Bogdan on 5/19/2024.
//

#ifndef TEMA3_CIRC_H
#define TEMA3_CIRC_H


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "spectacol.h"
using namespace std;


class Circ:public Spectacol{
private:
    string destinat_adulti;
    string animale_prezente;
    vector <string> lista_animale;
public:
    Circ(){
        setGen("comedie");
        setTip("circ");
    }
    void setAnimalPrezent(string raspuns){
        animale_prezente=raspuns;
    }

    string getAnimalePrezente() const{
        return animale_prezente;
    }

    void setDestinatAdulti(string raspuns){
        destinat_adulti=raspuns;
    }

    string getDestinatAdulti() const{
        return destinat_adulti;
    }

    void setListaAnimale(string animal){
        lista_animale.push_back(animal);
    }

    vector<string> getListaAnimale() const{
        return lista_animale;
    }

    Circ& operator=(const Circ& other) {
        if (this != &other) {
            Spectacol::operator=(other);
            destinat_adulti = other.destinat_adulti;
            animale_prezente = other.animale_prezente;
            lista_animale = other.lista_animale;
        }
        return *this;
    }

    string getTip() const override { return "circ"; }

    istream& citireSpectacol(istream& in);
    ostream& afisareSpectacol(ostream& out);

};

istream& Circ::citireSpectacol(std::istream &in) {
    string tip,animal="",nume_spectacol,mesaj;
    int  durata_fara_pauza,locuri_total,locuri_libere,numar_prezentari;

    cout<<"nume spectacol: ";
    in.ignore();
    getline(in,nume_spectacol);
    setNume(nume_spectacol);

    mesaj="destinat adulti(da/nu): ";
    exceptie(in,destinat_adulti,mesaj);
    setDestinatAdulti(destinat_adulti);

    mesaj="animale prezente(da/nu): ";
    exceptie(in,animale_prezente,mesaj);
    setAnimalPrezent(animale_prezente);

    if(animale_prezente=="da"){
        lista_animale.clear();
        cout<<"introdu animal: ";
        getline(in,animal);
        while(animal != "stop"){
            setListaAnimale(animal);
            cout<<"introdu animal: ";
            getline(in,animal);
        }
    }
    mesaj="durata(minute): ";
    exceptie(in,durata_fara_pauza,mesaj);
    setDurataFaraPauza(durata_fara_pauza);

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

ostream& Circ::afisareSpectacol(std::ostream &out) {
    out<<"Numele spectacolului este:"<<getNume()<<endl;
    out<<"Tipul spectacolului este:"<<getTip()<<endl;
    out<<"Genul spectacolului este:"<<getGen()<<endl;
    if(destinat_adulti=="da")
        out<<"Spectacolul este destinat doar adultilor."<<endl;
    else
        out<<"Spectacolul este destinat atat adultilor, cat si copiilor."<<endl;

    if(animale_prezente=="da") {
        out << "Spectacolul contine animalele: ";
        for (const auto& element : lista_animale)
            out << element << " ";
        out<<endl;
    }
    else
        out<<"Spectacolul nu contine animale"<<endl;

    out<<"Spectacolul dureaza "<<getDurataFaraPauza()<<" minute"<<endl;
    if(getLocuriLibere()>0)
        out<<"Spectacolul are "<<getlocuriTotal()<<" locuri in total, dintre care mai sunt disponibile "<<getLocuriLibere()<<" locuri"<<endl;
    else
        out<<"Nu mai sunt locuri disponibile la acest spectacol"<<endl;
    out<<"Spectacolul are "<<getNumarPrezentari()<<" reprezentari aceasta luna"<<endl;
    return out;
}
#endif //TEMA3_CIRC_H
