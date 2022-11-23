#include "Reserva.h"
#include <sstream>
#include <iostream>

Reserva::Reserva(int NL,int NC):x_inicial(0), y_inicial(0), linhas(NL), colunas(NC)
{
    for (int i = 0;i < NL; i++) {
        vector<char> aux;
        for (int j = 0;j < NC; j++)
            aux.push_back('_');
        tabela.push_back(aux);
    }
}


void Reserva::SetPosicaoTabela(int x, int y, char valor)
{
    tabela[x][y] = valor;
};

char Reserva::GetPosicaoTabela(int x, int y)
{
    return tabela[x][y];
};

int Reserva::GetX_inicial() const
{
    return x_inicial;
};

void Reserva::SetX_inicial(int NL)
{
    x_inicial = NL;
};

int Reserva::GetY_inicial() const
{
    return y_inicial;
};

void Reserva::SetY_inicial(int NC)
{
    y_inicial = NC;
};

int Reserva::GetLinhas() const
{
    return linhas;
};

int Reserva::GetColunas() const
{
    return colunas;
};

vector< vector< char> > Reserva::getTabelaTotal()const
{
    return tabela;
};

string Reserva::getAsString()const
{
    ostringstream oss;
    for(int i = x_inicial; (i < linhas) && ((i - x_inicial) < MAXLMOSTRAR); i++){
        for(int j = y_inicial; (j < colunas) && ((j - y_inicial) < MAXCMOSTRAR); j++)
            oss << tabela[i][j];
        oss << endl;
    }
    return oss.str();
};

void Reserva::limpaTabela()
{
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            tabela[i][j]='_';
    }
};

Reserva::~Reserva()
{

}
