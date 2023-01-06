//
// Created by ricar on 27/12/2022.
//

#include "Cenoura.h"
Cenoura::Cenoura(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,
                                     const string &cheiro): Alimento(especie,x,y,id,val_nutritivo,toxicidade,cheiro){}
Cenoura::Cenoura(int id, int x, int y) : Alimento('t', x,y, id, 4, 0, "verdura"){

}

void Cenoura::verificaComportamento(int instante){
    if(getToxicidade() == 3)
        return;
    if((instante-getInstanteInicial()) % 10 == 0)
        setToxicidade(getToxicidade()+1);
}


Cenoura::~Cenoura(){

}
