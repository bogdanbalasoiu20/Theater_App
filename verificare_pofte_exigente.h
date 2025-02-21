//
// Created by Bogdan on 5/19/2024.
//

#ifndef TEMA3_VERIFICARE_POFTE_EXIGENTE_H
#define TEMA3_VERIFICARE_POFTE_EXIGENTE_H


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "Spectator.h"
using namespace std;


void PofteCirc::filtru(vector<Spectacol*>spectacole,Pofte* pofte,Exigente* exigente,Spectator* spectator){
    int nr_spectacole=0;
    setIndex();
    for(const auto& spectacol:spectacole){

        int nr_pofte=0;
        int nr_exigente=0;

        if(spectacol->getTip()==pofte->getTip())
            nr_pofte++;

        if (spectacol->getGen() == pofte->getGen())
            nr_pofte++;

        if (pofte->getTimpMinFaraPauze() <= spectacol->getDurataFaraPauza())
            nr_pofte++;


        if(exigente->getCombinatie()!="nu") {
            string combinatie_nedorita;
            combinatie_nedorita = spectacol->getTip() +"-"+ spectacol->getGen();
            if (exigente->getCombinatie() == combinatie_nedorita)
                nr_exigente = 1;
        }

        if(exigente->getDurataMaxima()!=0){
            if(exigente->getDurataMaxima()<spectacol->getDurataFaraPauza())
                nr_exigente=1;
        }


        if(exigente->getSpectatoriMaxim()!=0){
            if(exigente->getSpectatoriMaxim() < spectacol->getlocuriTotal()-spectacol->getLocuriLibere())
                nr_exigente=1;
        }


        if(spectacol->getTip()=="circ"){
            Circ* circ = dynamic_cast<Circ*>(spectacol);
            if (!circ) {
                cout << "Conversie invalida la Circ" << endl;
                continue;
            }

            if (circ->getAnimalePrezente() == "da") {
                PofteCirc& poftecirc=dynamic_cast<PofteCirc&>(*pofte);
                for (const auto &animal: circ->getListaAnimale())
                    if (animal == poftecirc.getAnimalDorit())
                        nr_pofte++;
            }

            if(exigente->getDoresteAnimal()!=circ->getAnimalePrezente())
                nr_exigente=1;

            if (circ->getDestinatAdulti() == "da" && spectator->getVarsta() < 18)
                nr_exigente = 1;

        }

        if(spectacol->getTip()=="opera" || spectacol->getTip()=="teatru"){
            if(exigente->getDoresteAnimal()=="da")
                nr_exigente=1;
        }

        if(nr_exigente==0 && nr_pofte>0) {
            if (spectacol->getLocuriLibere() < spectator->getNrBilete())
                nr_exigente = 2;
            else
                spectacol->setLocuriLibere(spectacol->getLocuriLibere() - spectator->getNrBilete());
        }



        if (nr_pofte > 0 && nr_exigente == 0){
            cout<<"Pentru spectatorul "<<pofte->getIndex()<<" se potriveste spectacolul "<<spectacol->getNume()<<endl;
            nr_spectacole++;}


        if(nr_exigente==2)
            cout<<"La spectacolul "<<spectacol->getNume()<<" nu mai sunt suficiente locuri disponibile"<<endl;

    }
    if(nr_spectacole==0)
        cout<<"Pentru spectatorul "<<pofte->getIndex()<<" nu se potriveste niciun spectacol"<<endl;
}


void PofteOpera::filtru(vector<Spectacol*>spectacole,Pofte* pofte,Exigente* exigente,Spectator* spectator){
    int nr_spectacole=0;
    setIndex();
    for(const auto& spectacol:spectacole){

        int nr_pofte=0;
        int nr_exigente=0;

        if (spectacol->getGen() == pofte->getGen())
            nr_pofte++;

        if (pofte->getTimpMinFaraPauze() <= spectacol->getDurataFaraPauza())
            nr_pofte++;


        if(exigente->getCombinatie()!="nu") {
            string combinatie_nedorita;
            combinatie_nedorita = spectacol->getTip() +"-"+ spectacol->getGen();
            if (exigente->getCombinatie() == combinatie_nedorita)
                nr_exigente = 1;
        }

        if(exigente->getDurataMaxima()!=0){
            if(exigente->getDurataMaxima()<spectacol->getDurataFaraPauza())
                nr_exigente=1;
        }


        if(exigente->getSpectatoriMaxim()!=0){
            if(exigente->getSpectatoriMaxim() < spectacol->getlocuriTotal()-spectacol->getLocuriLibere())
                nr_exigente=1;
        }

        if(spectacol->getTip()=="opera" || spectacol->getTip()=="teatru"){
            if(exigente->getDoresteAnimal()=="da")
                nr_exigente=1;
        }


        if(spectacol->getTip()=="opera"){
            Opera* opera=dynamic_cast<Opera*>(spectacol);
            if (!opera) {
                cout << "Conversie invalida la Opera" << endl;
                continue;
            }
            PofteOpera& pofteopera=dynamic_cast<PofteOpera&>(*pofte);

            if(pofteopera.getTimpMinFaraPauze()<=opera->getDurataCuPauza())
                nr_pofte++;


            if(pofteopera.getRolSolist()==opera->getRolSolist())
                nr_pofte++;
        }

        if(nr_exigente==0 && nr_pofte>0) {
            if (spectacol->getLocuriLibere() < spectator->getNrBilete())
                nr_exigente = 2;
            else
                spectacol->setLocuriLibere(spectacol->getLocuriLibere() - spectator->getNrBilete());
        }



        if (nr_pofte > 0 && nr_exigente == 0){
            cout<<"Pentru spectatorul "<<pofte->getIndex()<<" se potriveste spectacolul "<<spectacol->getNume()<<endl;
            nr_spectacole++;}


        if(nr_exigente==2)
            cout<<"La spectacolul "<<spectacol->getNume()<<" nu mai sunt suficiente locuri disponibile"<<endl;



    }
    if(nr_spectacole==0)
        cout<<"Pentru spectatorul "<<pofte->getIndex()<<" nu se potriveste niciun spectacol"<<endl;
}


void PofteTeatru::filtru(vector<Spectacol*>spectacole,Pofte* pofte,Exigente* exigente,Spectator* spectator){
    int nr_spectacole=0;
    setIndex();
    for(const auto& spectacol:spectacole){

        int nr_pofte=0;
        int nr_exigente=0;


        if (spectacol->getGen() == pofte->getGen())
            nr_pofte++;

        if (pofte->getTimpMinFaraPauze() <= spectacol->getDurataFaraPauza())
            nr_pofte++;


        if(exigente->getCombinatie()!="nu") {
            string combinatie_nedorita;
            combinatie_nedorita = spectacol->getTip() +"-"+ spectacol->getGen();
            if (exigente->getCombinatie() == combinatie_nedorita)
                nr_exigente = 1;
        }

        if(exigente->getDurataMaxima()!=0){
            if(exigente->getDurataMaxima()<spectacol->getDurataFaraPauza())
                nr_exigente=1;
        }


        if(exigente->getSpectatoriMaxim()!=0){
            if(exigente->getSpectatoriMaxim() < spectacol->getlocuriTotal()-spectacol->getLocuriLibere())
                nr_exigente=1;
        }

        if(spectacol->getTip()=="opera" || spectacol->getTip()=="teatru"){
            if(exigente->getDoresteAnimal()=="da")
                nr_exigente=1;
        }

        if(spectacol->getTip()=="teatru"){
            Teatru* teatru=dynamic_cast<Teatru*>(spectacol);
            if (!teatru) {
                cout << "Conversie invalida la Teatru" << endl;
                continue;
            }
            PofteTeatru& pofteteatru=dynamic_cast<PofteTeatru&>(*pofte);

            if(pofteteatru.getTeatruInteractiv()=="da")
                nr_pofte++;

        }

        if(nr_exigente==0 && nr_pofte>0) {
            if (spectacol->getLocuriLibere() < spectator->getNrBilete())
                nr_exigente = 2;
            else
                spectacol->setLocuriLibere(spectacol->getLocuriLibere() - spectator->getNrBilete());
        }


        if (nr_pofte > 0 && nr_exigente == 0){
            cout<<"Pentru spectatorul "<<pofte->getIndex()<<" se potriveste spectacolul "<<spectacol->getNume()<<endl;
            nr_spectacole++;
        }

        if(nr_exigente==2)
            cout<<"La spectacolul "<<spectacol->getNume()<<" nu mai sunt suficiente locuri disponibile"<<endl;
    }
    if(nr_spectacole==0)
        cout<<"Pentru spectatorul "<<pofte->getIndex()<<" nu se potriveste niciun spectacol"<<endl;
}

#endif //TEMA3_VERIFICARE_POFTE_EXIGENTE_H
