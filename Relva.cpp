//
// Created by ricar on 27/12/2022.
//

#include "Relva.h"

Relva::Relva(Coord* coord, int id) : Alimento('r', coord, id, 3, 0, "erva,verdura"){
    fazNascer = 0.75*20; //entre 4 e 8 posições (linha e coluna) de distância
    duracao = 20;
}

void Relva::verificaComportamento(int instante){

    if((instante-getInstanteInicial()) == duracao){
        setMorte(true);
    }
    return;
}


Relva::~Relva(){

}