//
// Created by ricar on 27/12/2022.
//

#ifndef POO_ALIMENTO_MISTERIO_H
#define POO_ALIMENTO_MISTERIO_H
#include "Alimento.h"


class Alimento_misterio : public Alimento  {


public:
    Alimento_misterio(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,
                      const string &cheiro);//apenas para recuperar reserva antiga
    Alimento_misterio(int id,int x,int y);
    void verificaComportamento(int instante) override;
    ~Alimento_misterio();
};



#endif //POO_ALIMENTO_MISTERIO_H
