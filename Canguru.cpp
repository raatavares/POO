//
// Created by ricar on 26/12/2022.
//

#include <iostream>
#include "Canguru.h"

Canguru::Canguru(int id, int x, int y, int instante) : Animal('G', x, y, id, "canguru", 0, 20, 10, 7, 7, instante), morre(70),idPai(-1){


}
Canguru::Canguru(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
                 const int &mov_dist, int detet_dist, int instante) : Animal(especie, x, y, id, nome, fome, saude, peso, mov_dist,
                                                                             detet_dist, instante),idPai(-1) {

}

void Canguru::verificaComportamento(Alimento* alimento, int instante){
    if(getSaude() == 0)
        setMorte(true);
    if((instante-getInstanteInicial()) == 20)
        setPeso(20);
    return;
}


Canguru::~Canguru(){

}

Animal * Canguru::procria(int instante)  {

    if ((getTempo()+instante)%30==0){
        int x= getX()+rand()%(3-(-3)+1) +(-3);
        if(x<0) x=0;
        int y= getY()+rand()%(3-(-3)+1) +(-3);
        if(y<0) y=0;
        Canguru* cria=new Canguru(-getID(), x, y, instante);//id -1 e como se nao tivesse id
        cria->idPai= this->getID();
        return cria;
    }else return nullptr;
}

void Canguru::interacaoAnimal(Animal *animal) {


    if(animal->getY()> this->getY())this->setY(getY()+1);
    else if(animal->getY()< this->getY())this->setY(getY()-1);

    if(animal->getX()> this->getX())this->setX(getX()+1);
    else if(animal->getX()< this->getX())this->setX(getX()-1);
}

int Canguru::getPai() const {
    return idPai;
}
