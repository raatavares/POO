//
// Created by Danie on 23/11/2022.
//

#ifndef TP_RESERVA_H
#define TP_RESERVA_H
#include "animal.h"

class Reserva {
    vector<Animal>animais;
    vector<Alimento>alimentos;
    int SCoelho=20,SOvelha=30,SLobo=25,SCanguru=20;
    const int VCoelho=30,VOvelha=35,VLobo=40,VCanguru=70;
public:
    Reserva();
    void recebeComando(const string &frase);
    void defineConstante(const string &frase);
};


#endif //TP_RESERVA_H
