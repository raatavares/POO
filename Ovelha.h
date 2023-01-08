//
// Created by ricar on 26/12/2022.
//

#ifndef POO_OVELHA_H
#define POO_OVELHA_H

#include "Animal.h"

class Ovelha : public Animal {
    int morre;



public:
    Ovelha(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
           const int &mov_dist, int detet_dist, int instante);
    Ovelha(int id, int x, int y, int instante);

    void verificaComportamento(int instante) override;
    Animal * procria(int instante) override;

    ~Ovelha();

};


#endif //POO_OVELHA_H
