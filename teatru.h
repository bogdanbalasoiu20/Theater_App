//
// Created by Bogdan on 5/19/2024.
//

#ifndef TEMA3_TEATRU_H
#define TEMA3_TEATRU_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "spectacol.h"
using namespace std;

class Teatru:public Spectacol{
    string teatru_interactiv;
    int spectatori_adulti;
    int spectatori_copii;

public:
    Teatru(){
        setTip("teatru");
    }

    void setInteractiv(string raspuns){
        teatru_interactiv=raspuns;
    }

    string getInteractiv(){
        return teatru_interactiv;
    }

    string getTip() const override { return "teatru"; }

    istream& citireSpectacol(istream& in);
    ostream& afisareSpectacol(ostream& out);

};

istream& Teatru::citireSpectacol(std::istream &in) {
    string gen,nume_spectacol,mesaj;
    int durata_fara_pauza,locuri_total,locuri_libere,numar_prezentari;
    in.ignore();
    cout<<"nume spectacol: ";
    getline(in,nume_spectacol);
    setNume(nume_spectacol);

    cout<<"gen: ";
    getline(in,gen);
    setGen(gen);

    mesaj="teatru interactiv(da/nu): ";
    exceptie(in,teatru_interactiv,mesaj);
    setInteractiv(teatru_interactiv);

    mesaj="locuri totale: ";
    exceptie(in,locuri_total,mesaj);
    setLocuriTotal(locuri_total);

    mesaj="locuri libere: ";
    exceptie(in,locuri_libere,mesaj);
    setLocuriLibere(locuri_libere);

    mesaj="spectatori adulti: ";
    exceptie(in,spectatori_adulti,mesaj);
    spectatori_copii=getlocuriTotal()-getLocuriLibere()-spectatori_adulti;

    mesaj="durata fara pauza(minute): ";
    exceptie(in,durata_fara_pauza,mesaj);
    if(teatru_interactiv=="da")
        setDurataFaraPauza(durata_fara_pauza+spectatori_adulti+2*spectatori_copii);
    else
        setDurataFaraPauza(durata_fara_pauza);

    mesaj="numar prezentari: ";
    exceptie(in,numar_prezentari,mesaj);
    setNumarPrezentari(numar_prezentari);

    return in;
}

ostream& Teatru::afisareSpectacol(std::ostream &out) {
    out<<"Spectacolul se numeste: "<<getNume()<<endl;
    out<<"Tipul spectacolului este: "<<getTip()<<endl;
    out<<"Genul spectacolului este: "<<getGen()<<endl;
    if(teatru_interactiv=="da")
        out << "Spectacolul este interactiv" << endl;
    else
        out << "Spectacolul nu este interactiv" << endl;

    out << "Spectacolul dureaza " << getDurataFaraPauza() << " minute" << endl;
    if(getLocuriLibere()>0)
        out<<"Spectacolul are "<<getlocuriTotal()<<" locuri in total, dintre care mai sunt disponibile "<<getLocuriLibere()<<" locuri"<<endl;
    else
        out<<"Nu mai sunt bilete disponibile la acest spectacol"<<endl;
    out<<"Spectacolul are "<<getNumarPrezentari()<<" reprezentari aceasta luna"<<endl;
    return out;
}

#endif //TEMA3_TEATRU_H
