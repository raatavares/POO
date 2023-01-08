//
// Created by ricar on 26/12/2022.
//

#ifndef POO_MISTERIO_H
#define POO_MISTERIO_H
#include "Animal.h"

class Misterio : public Animal {


public:
    Misterio(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
             const int &mov_dist, int detet_dist, int instante);
    Misterio(int id, int x, int y, int instante);
    void verificaComportamento(int instante) override;
    ~Misterio();

};


#endif //POO_MISTERIO_H
