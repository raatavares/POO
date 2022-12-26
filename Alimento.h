#ifndef TP_ALIMENTO_H
#define TP_ALIMENTO_H

//#include "terminal.h"
#include "coord.h"

using namespace std;

class Alimento {
    char tipo;
    int val_nutritivo,toxicidade,tempo,id ;
    Coord *coordnada;
    string cheiro;
public:
    Alimento(const char &tipo,Coord *coord, const int id, int val_nutritivo = 1,int toxicidade = 1,const int &tempo = 1,const string &cheiro = "comida");


    int getNutricao() const;
    int getToxicidade() const;
    int getTempo() const;
    int getId() const;
    Coord* getCoord() const;
    string getcheiro() const;
    string getTipo() const;
    char getTipoChar() const;

    string getAsString() const;

    ~Alimento();
};


#endif //TP_ALIMENTO_H
