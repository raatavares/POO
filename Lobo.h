//
// Created by ricar on 26/12/2022.
//

#ifndef POO_LOBO_H
#define POO_LOBO_H
#include "Animal.h"

class Lobo : public Animal {
    int temCria;
    int momentonascer;

public:
    Lobo(int id,int x,int y,const char &especie,const string &nome,int fome,int saude,int peso,const int &mov_dist,int detet_dist, int instante);
    Lobo(int id, int x, int y, int instante);

    void interacaoAnimal(Animal *animal) override;
    void verificaComportamento(Alimento* alimento,int instante) override;
    Animal * procria(int instante) override;

    ~Lobo();

};


#endif //POO_LOBO_H
