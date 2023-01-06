//
// Created by ricar on 27/12/2022.
//

#include "Bife.h"

Bife::Bife(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,
                                     const string &cheiro): Alimento(especie,x,y,id,val_nutritivo,toxicidade,cheiro){}

Bife::Bife(int id, int x, int y) : Alimento('b', x,y, id, 10, 2, "carne,ketchup"){
    duracao = 30;
}

void Bife::verificaComportamento(int instante){
    if(getValorNutritivo() > 0)
        setValorNutritivo(getValorNutritivo()-1);
}

Bife::~Bife(){

}