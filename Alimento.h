#ifndef TP_ALIMENTO_H
#define TP_ALIMENTO_H

//#include "terminal.h"
#include "coord.h"

using namespace std;

class Alimento {
    char tipo;
    int val_nutritivo,toxicidade,id, instanteInicial;
    bool morte;
    Coord *coordnada;
    string cheiro;
public:
    Alimento(const char &tipo,Coord *coord, const int id, int val_nutritivo,int toxicidade,const string &cheiro);


    int getNutricao() const;
    int getToxicidade() const;
    int getInstanteInicial() const;
    int getValorNutritivo() const;
    bool getMorte() const;
    int getId() const;
    Coord* getCoord() const;
    string getcheiro() const;
    string getTipo() const;
    char getTipoChar() const;

    void setMorte(bool v);
    void setToxicidade(int toxicidade);
    void setValorNutritivo(int valorNutritivo);

    string getAsString() const;

    virtual void verificaComportamento(int instante) = 0;

    ~Alimento();
};


#endif //TP_ALIMENTO_H
