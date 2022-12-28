//
// Created by ricar on 27/12/2022.
//

#include "Cenoura.h"

Cenoura::Cenoura(Coord* coord, int id) : Alimento('t', coord, id, 4, 0, "verdura"){

}

void Cenoura::verificaComportamento(int instante){
    if(getToxicidade() == 3)
        return;
    if((instante-getInstanteInicial()) % 10 == 0)
        setToxicidade(getToxicidade()+1);
}


Cenoura::~Cenoura(){

}
