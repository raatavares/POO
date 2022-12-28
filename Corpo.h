//
// Created by ricar on 27/12/2022.
//

#ifndef POO_CORPO_H
#define POO_CORPO_H
#include "Alimento.h"


class Corpo : public Alimento  {
    int valorNutritivoInicial;


public:
    Corpo(Coord* coord, int id, int valorNutritivo);
    void verificaComportamento(int instante);
    ~Corpo();
};


#endif //POO_CORPO_H
