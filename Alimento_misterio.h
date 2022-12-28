//
// Created by ricar on 27/12/2022.
//

#ifndef POO_ALIMENTO_MISTERIO_H
#define POO_ALIMENTO_MISTERIO_H
#include "Alimento.h"


class Alimento_misterio : public Alimento  {


public:
    Alimento_misterio(Coord* coord, int id);
    void verificaComportamento(int instante);
    ~Alimento_misterio();
};



#endif //POO_ALIMENTO_MISTERIO_H
