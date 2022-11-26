#include <iostream>
#include "Coord.h"

Coord::Coord(int x, int y) {
    if (x <= MAX)
        this->x = x;
    else
        this->x = (rand() % MAX);

    if(y <= MAX)
        this->y = y;
    else
        this->y = (rand() % MAX);
    //cout << "Criado ponto/prego"<<getAsString();
}

void Coord::setCoord(int x, int y) {
    this->x=x;
    this->y=y;
}

int Coord::getCoordX() const {
    return x;
}

int Coord::getCoordY() const {
    return y;
}

double Coord::obterDist(const Coord &p) const {
    return sqrt(pow(this->x-p.getCoordX(),2)+pow(this->y-p.getCoordY(),2));
}

string Coord::getAsString() const {
    std::ostringstream oss;
    oss<<"(x: "<<x<<"/ y: "<<y<<")"<<endl;
    return oss.str();
}

Coord::~Coord() {
    //cout<<"Destruido ponto=> "<<getAsString();
}






