//
// Created by ricar on 27/12/2022.
//

#ifndef POO_CORPO_H
#define POO_CORPO_H
#include "Alimento.h"


class Corpo : public Alimento  {
    int valorNutritivoInicial;


public:
    Corpo(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,
                      const string &cheiro);//apenas para recuperar reserva antiga
    Corpo(int id, int valorNutritivo, int x, int y);
    void verificaComportamento(int instante) override;
    ~Corpo();
};


#endif //POO_CORPO_H
