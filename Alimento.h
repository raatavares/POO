#ifndef TP_ALIMENTO_H
#define TP_ALIMENTO_H

//#include "terminal.h"

using namespace std;
#include "complex"
#include <string.h>

class Alimento {
    char tipo;
    int val_nutritivo,toxicidade,id, instanteInicial, comido;
    bool morte;
    int x,y;
    string cheiro;
public:
    Alimento(const char &tipo, int x, int y, const int id, int val_nutritivo, int toxicidade, const string &cheiro);


    int getNutricao() const;
    int getToxicidade() const;
    int getInstanteInicial() const;
    int getValorNutritivo() const;
    bool getMorte() const;
    int getId() const;
    int getX() const;
    int getY() const;
    string getcheiro() const;
    int getComido() const;
    string getTipo() const;
    char getTipoChar() const;

    void setMorte(bool v);
    void setToxicidade(int toxicidade);
    void setValorNutritivo(int valorNutritivo);
    void setComido(int comido);

    string getAsString() const;
    string getToFile() const;

    virtual void verificaComportamento(int instante) = 0;

    virtual ~Alimento();
};


#endif //TP_ALIMENTO_H
