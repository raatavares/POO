#ifndef POO_RESERVA_H
#define POO_RESERVA_H

#define MAX 500
#define MIN 16
#define MAXCMOSTRAR 100
#define MAXLMOSTRAR 100



class Reserva{
    int x_inicial, y_inicial;
    vector< vector< char> > tabela;
    int linhas, colunas;

public:
    Reserva(int NL,int NC);


    void SetPosicaoTabela(int x, int y, char valor);
    char GetPosicaoTabela(int x, int y);
    int GetX_inicial() const;
    void SetX_inicial(int NL);
    int GetY_inicial() const;
    void SetY_inicial(int NC);

    int GetLinhas() const;
    int GetColunas() const;

    //void setTabelaXY(int x, int y);             repetido
    //char getTabelaXY(int x, int y) const;       repetido

    //void carregaTabela();
    vector< vector< char> > getTabelaTotal()const;
    vector< vector< char> > getTabela()const;

    void limpaTabela();

    ~Reserva();

};


#endif //POO_RESERVA_H
