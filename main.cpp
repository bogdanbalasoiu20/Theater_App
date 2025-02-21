#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include "Circ.h"
#include "Opera.h"
#include "Teatru.h"
#include "Spectator.h"
#include "verificare_pofte_exigente.h"
using namespace std;


int main(int argc,char *argv[]) {
    istream *in;
    char *nume_fisier;

    int citire_tastatura;
    if (argc == 1) {
        citire_tastatura = 1;
    } else {
        citire_tastatura = 0;
        nume_fisier=argv[1];
    }

    if (citire_tastatura == 1)
        in = &cin;
    else {
        fstream *fin = new fstream(nume_fisier);
        in = fin;
    }

    int meniu_ghiseu=1,tasta,index_spectacol=1,index_spectator=1;
    string tip_spectacol;


    vector <Circ*> circuri;
    vector <Opera*>opere;
    vector <Teatru*> teatre;
    vector <Spectacol*> spectacole;

    cout<<"Apasati: 1 pentru a introduce un spectacol nou\n"
          "         2 pentru introducerea unui client nou\n"
          "         3 pentru afisarea spectacolelor introduse\n"
          "         0 pentru inchiderea meniului:";

    while(*in>>tasta){
        if(tasta==1){
            string tip_spectacol;

            cout<<"Introdu datele despre spectacolul "<<index_spectacol<<endl;
            index_spectacol++;

            while(true){
                try{
                    cout<<"Introdu tipul spectacolului(circ/opera/teatru):";
                    *in>>tip_spectacol;
                    if(tip_spectacol!="circ"&& tip_spectacol!="opera"&& tip_spectacol!="teatru")
                        throw string("Tip spectacol invalid");
                        else break;

                }
                catch(string s){
                    cout<<s<<endl;
                }
            }


            if(tip_spectacol=="circ"){

                try{
                    Spectacol* sp=new Circ;
                    Circ* circ=dynamic_cast<Circ*>(sp);
                    *in>>*circ;

//                    Opera opera = Opera(*circ);
//                    cout<<opera;
                    circuri.push_back(circ);
                    spectacole.push_back(circ);
                }
                catch(const std::bad_cast&){
                    cout<<"conversie invalida"<<endl;
                }catch (const bad_alloc&) {
                    cout << "Alocare de memorie esuata. Nu s-a putut crea obiectul Circ." << endl;
                    break;
                }
            }

            else if(tip_spectacol=="opera"){

                try {
                    Spectacol *sp = new Opera;
                    Opera *opera = dynamic_cast<Opera*>(sp);
                    *in >> *opera;
                    opere.push_back(opera);
                    spectacole.push_back(opera);
                }
                catch(const std::bad_cast&){
                    cout<<"conversie invalida"<<endl;
                }catch (const bad_alloc&) {
                    cout << "Alocare de memorie esuata. Nu s-a putut crea obiectul Circ." << endl;
                    break;
                }
            }
            else if(tip_spectacol=="teatru") {
                try {
                    Spectacol *sp = new Teatru;
                    Teatru *teatru = dynamic_cast<Teatru*>(sp);
                    *in >> *teatru;
                    teatre.push_back(teatru);
                    spectacole.push_back(teatru);
                }catch(const std::bad_cast&){
                    cout<<"conversie invalida"<<endl;
                }catch (const bad_alloc&) {
                    cout << "Alocare de memorie esuata. Nu s-a putut crea obiectul Circ." << endl;
                    break;
                }
            }
       }
        else
           if(tasta==2){
            string tip_dorit;

            Spectator* spectator=new Spectator;
            *in>>*spectator;
            Exigente* exigente=new Exigente();


           while(true){
               try{
                   cout<<"Introdu tipul de spectacol dorit(circ/opera/teatru): ";
                   *in>>tip_dorit;
                   if(tip_dorit!="circ"&& tip_dorit!="opera"&& tip_dorit!="teatru")
                       throw string("Tip spectacol invalid");
                   else break;

               }
               catch(string s){
                   cout<<s<<endl;
               }
           }
            if(tip_dorit=="circ") {

                try{
                    PofteCirc pofteCirc;
                    Pofte* pofte=&pofteCirc;

                    *in>>*pofte;
                    *in>>*exigente;
                    pofte->filtru(spectacole,pofte,exigente,spectator);
                }catch (const std::bad_cast&){
                    cout<<"conversie invalida"<<endl;
                }


            }
            else if(tip_dorit=="opera") {
                try{
                    PofteOpera pofteOpera;
                    Pofte* pofte=&pofteOpera;

                    *in>>*pofte;
                    *in>>*exigente;
                    pofte->filtru(spectacole,pofte,exigente,spectator);
                }catch (const std::bad_cast&){
                    cout<<"conversie invalida"<<endl;
                }
            }
            else {
                try{
                    PofteTeatru pofteTeatru;
                    Pofte* pofte=&pofteTeatru;

                    *in>>*pofte;
                    *in>>*exigente;
                    pofte->filtru(spectacole,pofte,exigente,spectator);
                }catch (const std::bad_cast&){
                    cout<<"conversie invalida"<<endl;
                }
            }
            delete spectator;
            delete exigente;
        }
        else if(tasta==3){
            try{
                for(const auto& spectacol:spectacole)
                    cout<<*spectacol<<endl;
                if(spectacole.size()==0)
                    throw string("Nu au fost introduse spectacole inca");
            }
            catch(string s) {
                cout << s << endl;
            }

        }

        else if(tasta==0){
            break;
        }

        cout<<"Apasati: 1 pentru a introduce un spectacol nou\n"
              "         2 pentru introducerea unui client nou\n"
              "         3 pentru afisarea spectacolelor introduse\n"
              "         0 pentru inchiderea meniului:";
    }


    return 0;
}
