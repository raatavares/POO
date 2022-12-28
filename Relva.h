//
// Created by ricar on 27/12/2022.
//

#ifndef POO_RELVA_H
#define POO_RELVA_H
#include "Alimento.h"

class Relva : public Alimento  {
    int fazNascer, duracao;

public:

    Relva(Coord* coord, int id);
    void verificaComportamento(int instante);
    ~Relva();
};


#endif //POO_RELVA_H
