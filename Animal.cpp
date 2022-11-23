//
// Created by Danie on 21/11/2022.
//

#include <iostream>
#include "Animal.h"



Animal::Animal(const char &especie,const Coord& coord,const string &nome, int saude, int peso, int fome, const int &id, const int &mov_dist):especie(especie), coordenada(coord),nome(nome),saude(saude),peso(peso),id(id),mov_dist(mov_dist),fome(fome) {}

const string &Animal::getNome() const {
    return nome;
}

int Animal::getSaude() const {
    return saude;
}

int Animal::getPeso() const {
    return peso;
}

int Animal::getFome() const {
    return fome;
}

int Animal::getID() const {
    return id;
}

Coord Animal::getCoord() const {
    return this->coordenada;
}

int Animal::getMov_dist() const {
    return mov_dist;
}


string Animal::getEspecie() const {
    if (especie=='C') return "Coelho";
    else if (especie=='O') return "Ovelha";
    else if (especie=='L') return "Lobo";
    else if (especie=='G') return "Canguru";
    else return "???";
}

string Animal::getAsString() const {
    ostringstream oss;
    oss<<"Animal) nome:"<<nome<<" | especie:"<<getEspecie()<<" | id:"<<id<<" | saude:"<<saude<<" | peso:"<<peso<<" | fome:"<<fome<<" | passos:"<<mov_dist<<" | coordenada:"<<coordenada.getAsString()<<" | consumido: "<<getAlimentacao()<<endl;
    return oss.str();
}

string Animal::getAlimentacao() const {
    ostringstream oss;
    for(const auto & it : consumo){
        oss<<it.getTipo()<<" ";
    }
    oss<<endl;
    return oss.str();
}

void Animal::adicionaAlimento(const Alimento &a) {
    Alimento al(a.getTipoChar(),a.getCoord(),a.getNutricao(),a.getToxicidade(),a.getTempo(),a.getcheiro());                                          //Acabar depois de alimento não esquecer composição
    this->consumo.push_back(al);
    //delete(&a);  //nao convem destruir a classe a(Alimento)
}


