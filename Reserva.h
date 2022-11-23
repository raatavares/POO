//
// Created by Danie on 23/11/2022.
//

#ifndef TP_RESERVA_H
#define TP_RESERVA_H
#include "animal.h"

class Reserva {
    vector<Animal>animais;
    vector<Alimento>alimentos;

public:

    void recebeComando(const string &frase);
};


#endif //TP_RESERVA_H
