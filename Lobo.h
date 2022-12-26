//
// Created by ricar on 26/12/2022.
//

#ifndef POO_LOBO_H
#define POO_LOBO_H
#include "Animal.h"

class Lobo : public Animal {
    int fome;

public:
    Lobo(Coord* coord, int id);
    ~Lobo();

};


#endif //POO_LOBO_H
