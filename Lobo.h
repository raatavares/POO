//
// Created by ricar on 26/12/2022.
//

#ifndef POO_LOBO_H
#define POO_LOBO_H
#include "Animal.h"

class Lobo : public Animal {


public:
    Lobo(int id,int x,int y,const char &especie,const string &nome,int fome,int saude,int peso,const int &mov_dist);
    Lobo(int id, int x, int y);
    void verificaComportamento(int instante) override;
    ~Lobo();

};


#endif //POO_LOBO_H
