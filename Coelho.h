//
// Created by ricar on 26/12/2022.
//

#ifndef POO_COELHO_H
#define POO_COELHO_H
#include "Animal.h"

class Coelho : public Animal {
    int morre, fome;


public:
    Coelho(Coord* coord, int id);
    void verificaComportamento(int instante) override;
    ~Coelho();
};


#endif //POO_COELHO_H
