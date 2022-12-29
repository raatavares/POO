//
// Created by ricar on 26/12/2022.
//

#ifndef POO_OVELHA_H
#define POO_OVELHA_H

#include "Animal.h"

class Ovelha : public Animal {
    int morre, fome;



public:
    Ovelha(Coord* coord, int id);
    void verificaComportamento(int instante) override;
    ~Ovelha();

};


#endif //POO_OVELHA_H
