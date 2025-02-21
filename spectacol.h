//
// Created by Bogdan on 5/19/2024.
//

#ifndef TEMA3_SPECTACOL_H
#define TEMA3_SPECTACOL_H


#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Spectacol{
private:
    string nume;
    string tip;
    string gen;
    int* durata_fara_pauza;
    int durata_cu_pauza;
    int locuri_libere;
    int locuri_total;
    int numar_prezentari;

public:
    Spectacol() : nume(""), durata_fara_pauza(0), durata_cu_pauza(0), locuri_libere(0), locuri_total(0), numar_prezentari(0) {
        durata_fara_pauza = new int(0);
    }

    Spectacol(string str) : nume(""), durata_cu_pauza(0), locuri_libere(0), locuri_total(0), numar_prezentari(0) {
        durata_fara_pauza = new int(0);
    }

    Spectacol(const Spectacol& other){
        nume=other.nume;
        tip=other.tip;
        gen=other.gen;
        durata_fara_pauza = new int(*other.durata_fara_pauza);
        durata_cu_pauza=other.durata_cu_pauza;
        locuri_libere=other.locuri_libere;
        locuri_total=other.locuri_total;
        numar_prezentari=other.numar_prezentari;
    }

    ~Spectacol(){
        delete durata_fara_pauza;
    }

    Spectacol& operator=(const Spectacol& other) {
        if (this != &other) {
            nume = other.nume;
            tip = other.tip;
            gen = other.gen;
            durata_fara_pauza = new int(*other.durata_fara_pauza);
            durata_cu_pauza = other.durata_cu_pauza;
            locuri_libere = other.locuri_libere;
            locuri_total = other.locuri_total;
            numar_prezentari = other.numar_prezentari;
        }
        return *this;
    }


    void setGen(string gen_spectacol){
        gen=gen_spectacol;
    }
    string getGen() const{
        return gen;
    }

    void setTip(string tip_spectacol){
        tip=tip_spectacol;
    }


    void setNume(string nume_spectacol){
        nume=nume_spectacol;
    }
    string getNume() const{
        return nume;
    }

    void setDurataFaraPauza(int durata_spectacol_fara_pauza) {
        *durata_fara_pauza = durata_spectacol_fara_pauza;
    }

    int getDurataFaraPauza() const {
        return *durata_fara_pauza;
    }

    void setDurataCuPauza(int durata_spectacol_cu_pauza){
        durata_cu_pauza=durata_spectacol_cu_pauza;
    }

    int getDurataCuPauza() const{
        return durata_cu_pauza;
    }

    void setLocuriLibere(int locuri_libere2){
        locuri_libere=locuri_libere2;
    }

    int getLocuriLibere() const{
        return locuri_libere;
    }

    void setLocuriTotal(int locuri_spectacol){
        locuri_total=locuri_spectacol;
    }

    int getlocuriTotal() const{
        return locuri_total;
    }

    void setNumarPrezentari(int prezentari_pe_luna){
        numar_prezentari=prezentari_pe_luna;
    }

    int getNumarPrezentari() const{
        return numar_prezentari;
    }

    friend istream& operator >> (istream& in,Spectacol& s){
        return s.citireSpectacol(in);
    }

    friend ostream& operator <<(ostream& out, Spectacol& s){
        return s.afisareSpectacol(out);
    }

    virtual string getTip() const = 0;
    virtual istream& citireSpectacol(istream& in)=0;
    virtual ostream& afisareSpectacol(ostream& out)=0;

    void exceptie(istream& in,string &x,string mesaj){
        while(true) {
            try {
                cout << mesaj;
                getline(in, x);
                if(x!="da" && x!="nu"){
                    throw string("Raspuns invalid");
                }
                else{break;
                }
            }
            catch(string s){
                cout<<s<<endl;
            }
        }
    }

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
#endif //TEMA3_SPECTACOL_H
