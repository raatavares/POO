#ifndef TP_ALIMENTO_H
#define TP_ALIMENTO_H

//#include "terminal.h"
#include "coord.h"

using namespace std;

class Alimento {
    char tipo;
    int val_nutritivo,toxicidade,tempo,id ;
    Coord coordnada;
    string cheiro;
public:
    Alimento(const char &tipo,const Coord &coord,int val_nutritivo,int toxicidade,const int &tempo,const string &cheiro);


    int getNutricao() const;
    int getToxicidade() const;
    int getTempo() const;
    int getId() const;
    Coord getCoord() const;
    string getcheiro() const;
    string getTipo() const;
    char getTipoChar() const;

    string getAsString() const;

    ~Alimento();
};


#endif //TP_ALIMENTO_H
