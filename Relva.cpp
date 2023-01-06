//
// Created by ricar on 27/12/2022.
//

#include "Relva.h"
Relva::Relva(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,
                                     const string &cheiro): Alimento(especie,x,y,id,val_nutritivo,toxicidade,cheiro){}
Relva::Relva(int id, int x, int y) : Alimento('r', x,y, id, 3, 0, "erva,verdura"){
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