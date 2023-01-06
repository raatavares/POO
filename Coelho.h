//
// Created by ricar on 26/12/2022.
//

#ifndef POO_COELHO_H
#define POO_COELHO_H
#include "Animal.h"

class Coelho : public Animal {
    int morre;


public:
    Coelho(int id,int x,int y,const char &especie,const string &nome,int fome,int saude,int peso,const int &mov_dist);//apenas para recuperar reserva antiga
    Coelho(int id, int x, int y);
    void verificaComportamento(int instante) override;
    ~Coelho();
};


#endif //POO_COELHO_H
