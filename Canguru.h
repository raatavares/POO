//
// Created by ricar on 26/12/2022.
//

#ifndef POO_CANGURU_H
#define POO_CANGURU_H

#include <memory>
#include "Animal.h"

class Canguru : public Animal {
    int morre;
    int idPai;


public:
    Canguru(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
            const int &mov_dist, int detet_dist, int instante);
    Canguru(int id, int x, int y, int instante);
    Canguru()=default;
    int getPai()const override;
    void interacaoAnimal(Animal *animal) override;
    void verificaComportamento(Alimento* alimento,int instante) override;
    Animal * procria(int instante) override;

    ~Canguru();

};


#endif //POO_CANGURU_H
