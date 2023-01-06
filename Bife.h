//
// Created by ricar on 27/12/2022.
//

#ifndef POO_BIFE_H
#define POO_BIFE_H
#include "Alimento.h"


class Bife : public Alimento  {
    int duracao;

public:
    Bife(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,
                      const string &cheiro);//apenas para recuperar reserva antiga
    Bife(int id, int x, int y);
    void verificaComportamento(int instante) override;
    ~Bife();
};


#endif //POO_BIFE_H
