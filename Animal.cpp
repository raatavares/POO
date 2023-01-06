#include <iostream>
#include "Animal.h"



Animal::Animal(const char &especie,int x,int y,const int &id,const string &nome,int fome,int saude,int peso,const int &mov_dist):especie(especie), x(x),y(y),nome(nome),fome(fome),saude(saude),peso(peso),id(id),mov_dist(mov_dist) {}

const string &Animal::getNome() const {
    return nome;
}

int Animal::getSaude() const {
    return saude;
}

int Animal::getPeso() const {
    return peso;
}

int Animal::getID() const {
    return id;
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
    oss<<"Animal) nome: "<<nome<<" | especie: "<<getEspecie()<<" | id: "<<id<<" | saude: "<<saude<<" | fome: "<<fome<<" | peso: "<<peso<<" | passos: "<<mov_dist<<" | coordenada: ("<<x<<","<<y<<")";
    if(!consumo.empty())
           oss <<" | consumido: "<<getAlimentacao();
    oss << endl;
    return oss.str();
}
string Animal::getToFile() const {
    ostringstream oss;
    oss<<"Animal "<<especie<<" "<<nome<<" "<<id<<" "<<saude<<" "<<fome<<" "<<peso<<" "<<x<<" "<<y<<" "<<mov_dist<<" "<<endl;
    return oss.str();
}


string Animal::getAlimentacao() const {
    ostringstream oss;
    for(const auto it : consumo){
        oss<<it->getTipo()<<" ";
    }
    oss<<endl;
    return oss.str();
}

void Animal::adiciona_Alimento(Alimento* a) {
    //Alimento al(a->getTipoChar(),a->getCoord(),a->getId(),a->getNutricao(),a->getToxicidade(),a->getcheiro());     //Acabar depois de alimento não esquecer composição

    consumo.push_back(a);
    cout << "1";
    //delete(&a);  //nao convem destruir a classe a(Alimento)
}

Animal::~Animal(){
    //cout << "Animal " << getNome() << " morreu" << endl;
}

void Animal::alimentaUser(int pontos_nutritivos, int toxicidade) {
    saude-=toxicidade;
    fome-=pontos_nutritivos;

}

int Animal::getX() const {
    return x ;
}

int Animal::getY() const {
    return y;
}






