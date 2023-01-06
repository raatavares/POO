//
// Created by ricar on 27/12/2022.
//

#ifndef POO_RELVA_H
#define POO_RELVA_H
#include "Alimento.h"

class Relva : public Alimento  {
    int fazNascer, duracao;

public:
    Relva(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,
                      const string &cheiro);//apenas para recuperar reserva antiga
    Relva(int id, int x, int y);
    void verificaComportamento(int instante) override;
    ~Relva();
};


#endif //POO_RELVA_H
