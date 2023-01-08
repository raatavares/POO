#include <iostream>
#include "Animal.h"



Animal::Animal(const char &especie, int x, int y, const int &id, const string &nome, int fome, int saude, int peso,
               const int &mov_dist, int detet_dist, int criado_t)
        : especie(especie), x(x), y(y), nome(nome), fome(fome), saude(saude), peso(peso), id(id), mov_dist(mov_dist), detet_dist(detet_dist) {
    this->criado_t = criado_t;
    morte = false;
}

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
    oss<<"Animal "<<especie<<" "<<nome<<" "<<id<<" "<<saude<<" "<<fome<<" "<<peso<<" "<<x<<" "<<y<<" "<<mov_dist<<" "<<detet_dist<<" "<<endl;
    return oss.str();
}


string Animal::getAlimentacao() const {
    ostringstream oss;
    for(const auto it : consumo){
        oss << it << endl;
    }
    return oss.str();
}

void Animal::adiciona_Alimento(Alimento* a) {
    string mensagem = (a->getTipo() + " com " + to_string(a->getValorNutritivo()) + " valor nutritivo e " + to_string(a->getToxicidade()) + " toxicidade");
    consumo.push_back(&mensagem);
}

Animal::~Animal(){
    consumo.clear();
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

void Animal::movimenta() {

    int pos = rand() % 16;
    if(pos==0||pos==15){
        y++;
    }else if(pos==1||pos==14){
        y++;x++;
    }else if(pos==2||pos==13){
        x++;
    }else if(pos==3||pos==12){
        y--;x++;

    }else if(pos==4||pos==11){
        y--;
    }else if(pos==5||pos==10){
        y--;x--;

    }else if(pos==6||pos==9){
        x--;

    }else if(pos==7||pos==8){
        y++;x--;

    }
}



void Animal::setX(int x) {
    this->x=x;
}
void Animal::setY(int y) {
    this->y=y;
}

void Animal::setSaude(int saude) {
    this->saude=saude;
}

void Animal::setMorte(bool morte){
    this->morte = morte;
}

void Animal::setFome(int fome){
    this->fome = fome;
}

void Animal::setMov_dist(int mov){
    mov_dist = mov;
}

void Animal::setPeso(int peso) {
    this->peso = peso;
}

int Animal::getInstanteInicial() const{
    return criado_t;
}

bool Animal::getMorte() const{
    return morte;
}
int Animal::getFome() const{
    return fome;
}


int Animal::getDetet_dist() const {
    return detet_dist;
}

char Animal::getEspecieChar() const {
    return especie;
}

Animal *Animal::procria(int instante)  {

    return nullptr;
}

void Animal::setID(int newID) {
    id=newID;
}

int Animal::getTempo() const{
    return criado_t;
}





void Animal::interacaoAnimal(Animal *animal) {

}

void Animal::setMov(int n) {
    mov_dist=n;
}









