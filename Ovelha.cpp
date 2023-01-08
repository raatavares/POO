//
// Created by ricar on 26/12/2022.
//

#include <iostream>
#include "Ovelha.h"

Ovelha::Ovelha(int id, int x, int y, int instante=0) : Animal('O', x, y, id, "ovelhaXoné", 0, 30, (4 + rand() % 8), 3, 3, instante) {

    morre = 35;
}
Ovelha::Ovelha(int id, int x, int y, const char &especie, const string &nome, int fome, int saude, int peso,
               const int &mov_dist, int detet_dist, int instante) : Animal(especie, x, y, id, nome, fome, saude, peso, mov_dist,
                                                                           detet_dist, instante), morre(35){
    cout<<"nasceu:-"<<getID()<<endl;
}

void Ovelha::verificaComportamento(Alimento* alimento, int instante){
    if(alimento->getcheiro() == "erva"){
        setSaude(getSaude()+alimento->getValorNutritivo());
        setSaude(getSaude()-alimento->getToxicidade());
        adiciona_Alimento(alimento);
        alimento->setComido(1);
    }
    if(getSaude() == 0)
        setMorte(true);
    if((instante-getInstanteInicial()) == 35)
        setMorte(true);
    setFome(getFome()+1);
    if(getFome() > 20){
        setSaude(getSaude()-2);
    }else if(getFome() > 15){
        setSaude(getSaude()-1);
        setMov_dist((1 + rand() % 2));
    }
    return;
}

Ovelha::~Ovelha(){

}

Animal *Ovelha::procria(int instante) {

    if ((instante+getTempo())%15==0 ){
        int x= getX()+rand()%(12-(-12)+1) +(-12);
        if(x<0) x=0;
        int y= getY()+rand()%(12-(-12)+1) +(-12);
        if(y<0) y=0;
        //return new Ovelha(-getID(),x,y);//id -1 e como se nao tivesse id
        return new Ovelha(-getID(), x, y, 'O', "efnm", 0, 30, (4 + rand() % 8), 3, 3, 0);
    }else return nullptr;
}

void Ovelha::interacaoAnimal(Animal *animal) {

    if(animal->getPeso()>15){
        cout<<"existe";
        if(animal->getY()> this->getY())this->setY(getY()-1);
        else if(animal->getY()< this->getY())this->setY(getY()+1);

        if(animal->getX()> this->getX())this->setX(getX()-1);
        else if(animal->getX()< this->getX())this->setX(getX()+1);
    }else return;
}
