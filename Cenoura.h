//
// Created by ricar on 27/12/2022.
//

#ifndef POO_CENOURA_H
#define POO_CENOURA_H
#include "Alimento.h"

class Cenoura : public Alimento  {


public:
    Cenoura(Coord* coord, int id);

    void verificaComportamento(int instante);

    ~Cenoura();
};


#endif //POO_CENOURA_H
