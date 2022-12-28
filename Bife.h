//
// Created by ricar on 27/12/2022.
//

#ifndef POO_BIFE_H
#define POO_BIFE_H
#include "Alimento.h"


class Bife : public Alimento  {
    int duracao;

public:
    Bife(Coord* coord, int id);
    void verificaComportamento(int instante);
    ~Bife();
};


#endif //POO_BIFE_H
