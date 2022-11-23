//
// Created by Danie on 27/10/2022.
//

#ifndef UNTITLED3_COORD_H
#define UNTITLED3_COORD_H

#include "complex"


using namespace std;

class Coord {
    int x;
    int y;

public:
    Coord(int x,int y);
    ~Coord();

    void setCoord(int x,int y);
    int getCoordX() const;
    int getCoordY() const;

    double obterDist(const Coord &p) const;

    string getAsString() const;


};


#endif //UNTITLED3_COORD_H