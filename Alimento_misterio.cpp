//
// Created by ricar on 27/12/2022.
//

#include "Alimento_misterio.h"

Alimento_misterio::Alimento_misterio(int x,int y, int id) : Alimento('a', x,y, id, 4, 1, "peixe"){


}
Alimento_misterio::Alimento_misterio(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,
               const string &cheiro): Alimento(especie,x,y,id,val_nutritivo,toxicidade,cheiro){}
void Alimento_misterio::verificaComportamento(int instante){
    return;
}

Alimento_misterio::~Alimento_misterio(){

}