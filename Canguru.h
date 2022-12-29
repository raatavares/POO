//
// Created by ricar on 26/12/2022.
//

#ifndef POO_CANGURU_H
#define POO_CANGURU_H
#include "Animal.h"

class Canguru : public Animal {
    int morre;



public:
    Canguru(Coord* coord, int id);
    void verificaComportamento(int instante) override;
    ~Canguru();

};


#endif //POO_CANGURU_H
