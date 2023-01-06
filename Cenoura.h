//
// Created by ricar on 27/12/2022.
//

#ifndef POO_CENOURA_H
#define POO_CENOURA_H
#include "Alimento.h"

class Cenoura : public Alimento  {


public:
    Cenoura(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,
                      const string &cheiro);//apenas para recuperar reserva antiga
    Cenoura(int id, int x, int y);

    void verificaComportamento(int instante) override;

    ~Cenoura();
};


#endif //POO_CENOURA_H
