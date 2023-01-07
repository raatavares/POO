//
// Created by ricar on 26/12/2022.
//

#ifndef POO_CANGURU_H
#define POO_CANGURU_H
#include "Animal.h"

class Canguru : public Animal {
    int morre;



public:
    Canguru(int id,int x,int y,const char &especie,const string &nome,int fome,int saude,int peso,const int &mov_dist,int detet_dist);
    Canguru(int x,int y, int id);
    void verificaAlimentacao(Alimento* alimento) override;
    ~Canguru();

};


#endif //POO_CANGURU_H
