#include "fstream"
#include "Reserva.h"

Reserva::Reserva(int linhas, int colunas):L_inicial(0), C_inicial(0), total(0) {
    if (linhas >= MIN && linhas <= MAX)
        this->nLinhas = linhas;
    else
        this->nLinhas = MIN+ (rand() % MAX);

    if( colunas >= MIN && colunas <= MAX)
        this->nColunas = colunas;
    else
        this->nColunas = MIN+ (rand() % MAX);

    ifstream file;
    string frase;
    file.open("constantes.txt");
    if (!file.is_open())
        cout<<"Erro ao abrir ficheiro de constante, usando constantes default"<<endl;
    else{
        while (getline(file,frase)){
            defineConstante(frase);
        }
        file.close();
    }
    instante = 0;
}

void Reserva::recebeComando(const string &frase) {
    istringstream iss(frase);
    vector<string>arg;

    int i=0, id, linha, coluna;
    string comand,n, nome;
    while (iss>>n){
        ++i;
        arg.push_back(n);
    }
    comand=*arg.begin();

    if(comand=="animal" && i==4) {
        linha = stoi(*(arg.begin()+2));
        coluna = stoi(*(arg.begin()+3));
        criaAnimal(*(*(arg.begin()+1)).c_str(),linha,coluna);
    }else if(comand=="teste"){
        atualizaPosicoes(instante);
    }

    else if(comand=="animal" && i==2) {
        criaAnimal(*(*(arg.begin()+1)).c_str());
    }

    else if(comand=="kill" && i==3) {
        linha = stoi(*(arg.begin()+1));
        coluna = stoi(*(arg.begin()+2));
        if(existeAnimal(linha, coluna) == true){
            removerAnimal(linha, coluna);
        }
    }

    else if(comand=="killid" && i==2) {
        id = stoi(*(arg.begin()+1));
        removerAnimal(id);
    }

    else if(comand=="load" && i==1){
      cout<<"Nome do ficheiro:";
      cin>>nome;
      recebeComandoPorFicheiro(nome);
    }

    else if(comand=="food" && i==4) {
        linha = stoi(*(arg.begin()+2));
        coluna = stoi(*(arg.begin()+3));
        criaAlimento(*(*(arg.begin()+1)).c_str(),linha,coluna);
    }

    else if(comand=="food" && i==2) {
        criaAlimento(*(*(arg.begin()+1)).c_str());
    }

    else if(comand=="feed" && i==5) {
        feed(stoi(arg[1]), stoi(arg[2]), stoi(arg[3]), stoi(arg[4]));
    }
    else if(comand=="feedid" && i==4) {
        feedid(stoi(arg[1]), stoi(arg[2]), stoi(arg[3]));
    }


    else if(comand=="nofood" && i==3) {
        linha = stoi(*(arg.begin()+1));
        coluna = stoi(*(arg.begin()+2));
        if(existeAlimento(linha, coluna) == true){
            removerAlimento(linha, coluna);
        }
    }

    else if(comand=="nofood" && i==2) {
        id = stoi(*(arg.begin()+1));
        removerAlimento(id);
    }

    else if(comand=="empty" && i==3) {
        linha = stoi(*(arg.begin()+1));
        coluna = stoi(*(arg.begin()+2));
        if(existeAlimento(linha, coluna) == true){
            removerAlimento(linha, coluna);
        }
        if(existeAnimal(linha, coluna) == true){
            removerAnimal(linha, coluna);
        }
    }

    else if(comand=="see" && i==3) {
        linha = stoi(*(arg.begin()+1));
        coluna = stoi(*(arg.begin()+2));
        coluna = stoi(*(arg.begin()+2));
        cout << getAsStringPos(linha, coluna) << endl;
    }

    else if(comand=="info" && i==2) {
        id = stoi(*(arg.begin()+1));
        if( getAnimal(id) != NULL){
            cout << getAnimal(id)->getAsString() << endl;
        }else if(getAlimento(id) != NULL)
            cout << getAlimento(id)->getAsString() << endl;
        else
            cout << "Nao existe" << endl;
    }

    else if(comand=="n" && i==1) {
        instante++;
        passaInstante(instante);
    }

    else if(comand=="n" && i==2) {
        for(int j = 0; j < stoi(*(arg.begin()+1)); j++){
            instante++;
            passaInstante(instante);
        }
    }

    else if(comand=="n" && i==3) {
        for(int j = 0; j < stoi(*(arg.begin()+1)); j++){
            instante++;
            passaInstante(instante);
            sleep(stoi(*(arg.begin()+2)));
        }

    }

    else if(comand=="anim" && i==1){
        for(int i = 0; i < animais.size(); i++){
            cout << animais[i]->getAsString();
        }
    }

    else if(comand=="visanim" && i==1){
        for(int i = 0; i < animais.size(); i++){
            if(animais[i]->getX() >= L_inicial && animais[i]->getY() > C_inicial && animais[i]->getX() <= L_inicial+mostra && animais[i]->getY() < C_inicial+mostra)
            cout << animais[i]->getAsString();
        }
    }

    else if(comand=="store" && i==2){
        getToFile(arg.at(1));
    }

    else if(comand=="restore" && i==2){
        restoreProgress(arg[1]);
    }

    else if(comand=="slide" && i==3) {
        if(*(arg.begin()+1) == "up"){
            for(int i = 1; i <= stoi(*(arg.begin()+2)); i++){
                if(L_inicial != 0)
                    L_inicial--;
                else{
                    L_inicial = nLinhas;
                }
            }
        }
        else if(*(arg.begin()+1) == "down"){
            for(int i = 1; i <= stoi(*(arg.begin()+2)); i++){
                if(L_inicial != nLinhas)
                    L_inicial++;
                else{
                    L_inicial = 0;
                }
            }
        }
        else if(*(arg.begin()+1) == "right"){
            for(int i = 1; i <= stoi(*(arg.begin()+2)); i++){
                if(C_inicial != nColunas)
                    C_inicial++;
                else{
                    C_inicial = 0;
                }
            }
        }
        else if(*(arg.begin()+1) == "left"){
            for(int i = 1; i <= stoi(*(arg.begin()+2)); i++){
                if(C_inicial != 0)
                    C_inicial--;
                else{
                    C_inicial = nColunas;
                }
            }
        }
    }

    else if(comand=="exit" && i==1) {cout<<"[saindo...]"<<endl;exit(EXIT_SUCCESS);}


    else if(comand=="ver_reserva" && i==1) verReserva();
            // <- Fazer método para receber comandos por ficheiro

    else cout<<"invalido"<<endl;

    cout << endl << endl;
    cout << getAsString();
}

void Reserva::passaInstante(int instante){
    int flag=0;
    for (auto it:animais) {
        if(detetaAnimal(it->getID())){
            for (auto ipt:animais) {
                getRedondezaAnim(ipt->getID(),ipt->getDetet_dist());
            }

        }
    }
    atualizaPosicoes(instante);
    adicionaCria();
    for(int i = 0; i < alimentos.size(); i++){
        alimentos[i]->verificaComportamento(instante);
    }
}

void Reserva::defineConstante(const string &frase) {

    string const_name[4]={"SCoelho","SOvelha","SLobo","SCanguru"};
    int* c[4]={&SCoelho,&SOvelha,&SLobo,&SCanguru};
    istringstream iss(frase);
    int i=1;
    string constante,n;
    iss>>constante;
    while (iss >> n){
        ++i;
    }
    for (int j = 0; j < 4; ++j) {
        if(constante==const_name[j]){
            *c[j]= stoi(n);

        }
    }



}

void Reserva::recebeComandoPorFicheiro(const string &ficheiro) {
    ifstream file;
    string linha;
    file.open(ficheiro);
    if (!file.is_open())
        cout<<"Erro ao abrir ficheiro de comandos"<<endl;
    else{
        while (getline(file,linha)){
            recebeComando(linha);
        }
        file.close();
        cin.ignore();
    }

}

void Reserva::criaAnimal(const char &especie, int x, int y) {
    if (x == -1 && y == -1){
        x = rand() % nLinhas;
        y = rand() % nColunas;
    }
    if (toupper(especie) == 'C')
        adicionaAnimal(new Coelho(total, x, y, instante));
    else if (toupper(especie) == 'O')
        adicionaAnimal(new Ovelha(total, x, y, instante));
    else if (toupper(especie) == 'L')
        adicionaAnimal(new Lobo(total,x,y, instante));
    else if (toupper(especie) == 'G')
        adicionaAnimal(new Canguru(total, y, x, instante));
    else if (toupper(especie) == 'M')
        adicionaAnimal(new Misterio(total, x, y, instante));
    total++;
}

void Reserva::criaAlimento(const char &tipo, int x, int y) {
    if (x == -1 && y == -1){
        x = rand() % nLinhas;
        y = rand() % nColunas;
    }
    if (toupper(tipo) == 'R')
        adicionaAlimento(new Relva(total, x, y));
    else if (toupper(tipo) == 'T')
        adicionaAlimento(new Cenoura(total, x, y));
    else if (toupper(tipo) == 'B')
        adicionaAlimento(new Bife(total, x, y));
    else if (toupper(tipo) == 'A')
        adicionaAlimento(new Alimento_misterio(x, y, total));
    total++;
}

void Reserva::verReserva() const {
    cout<<"----------- Animais -----------"<<endl<<endl;
    for(auto it:animais){
        cout<<it->getAsString()<<endl;
    }
    cout<<endl<<"---------- Alimentos ----------"<<endl<<endl;
    for(auto it:alimentos){
        cout<<it->getAsString()<<endl;
    }
}


vector<Animal*> Reserva::getAnimais() const
{
    return animais;
};

vector<Alimento*> Reserva::getAlimentos() const
{
    return alimentos;
};

Alimento* Reserva::getAlimento(int id) const
{
    for(int i=0 ; i < alimentos.size(); i++){
        if(alimentos[i]->getId() == id)
            return alimentos[i];
    }
    return NULL;
};

Animal* Reserva::getAnimal(int id) const
{
    for(int i=0 ; i < animais.size(); i++){
        if(animais[i]->getID() == id)
            return animais[i];
    }
    return nullptr;
};
Animal *Reserva::getAnimal(int x, int y) const {
    for(int i=0 ; i < animais.size(); i++){
        if(animais[i]->getY()==y && animais[i]->getX()==x)
            return animais[i];
    }
    return nullptr;
}
Alimento* Reserva::getAlimento(int x, int y) const {
    for(int i=0 ; i < alimentos.size(); i++){
        if(alimentos[i]->getY()==y && alimentos[i]->getX()==x)
            return alimentos[i];
    }
    return nullptr;
}

int Reserva::getnLinhas() const
{
    return nLinhas;
};

int Reserva::getnColunas() const
{
    return nColunas;
};

int Reserva::getL_inicial() const
{
    return L_inicial;
};

int Reserva::getC_inicial() const
{
    return C_inicial;
};

void Reserva::setL_inicial(int l)
{
    L_inicial = l;
};

void Reserva::setC_inicial(int c)
{
    C_inicial = c;
};

void Reserva::adicionaAlimento(Alimento *alimento)
{

    alimentos.push_back(alimento);

};

void Reserva::adicionaAnimal(Animal *animal)
{
    animais.push_back(animal);
};

void Reserva::removerAlimento(int id)
{
    for (auto ptr = alimentos.begin(); ptr != alimentos.end(); ) {
        if ((*(ptr))->getId() == id) {
            delete *(ptr);
            ptr = alimentos.erase(ptr);
        }
        else
            ptr++;
    }
};

void Reserva::removerAlimento(int linha, int coluna)
{
    for (auto ptr = alimentos.begin(); ptr != alimentos.end(); ) {
        if ((*(ptr))->getX() == linha && (*(ptr))->getY() == coluna) {
            delete *(ptr);
            ptr = alimentos.erase(ptr);
        }
        else
            ptr++;
    }
};

void Reserva::removerAnimal(int id)
{
    for (auto ptr = animais.begin(); ptr != animais.end(); ) {
        if ((*(ptr))->getID() == id){

            delete *(ptr);
            ptr = animais.erase(ptr);
        }
        else
            ptr++;
    }
};

void Reserva::removerAnimal(int linha, int coluna)
{
    for (auto ptr = animais.begin(); ptr != animais.end(); ) {
        if ((*(ptr))->getX() == linha && (*(ptr))->getY()== coluna) {

            delete *(ptr);
            ptr = animais.erase(ptr);
        }
        else
            ptr++;
    }
};

string Reserva::getAsString() const
{
    ostringstream oss;
    int auxL=L_inicial, auxC=C_inicial;
    for(int i = 1; i <= mostra; i++){
        auxC = C_inicial;
        for(int j = 1; j <= mostra; j++){
            if(existeAlimento(auxL, auxC) == false && existeAnimal(auxL, auxC) == false){
                oss << '_';
            }else{
                for(int a = 0; a<alimentos.size(); a++){
                    if(alimentos[a]->getX() == auxL && alimentos[a]->getY() == auxC)
                        oss << alimentos[a]->getId();
                }
                for(int a = 0; a<animais.size(); a++){
                    if(animais[a]->getX() == auxL && animais[a]->getY() == auxC)
                        oss << animais[a]->getID();
                }
            }
            if (auxC == nColunas)
                auxC = 0;
            else
                auxC++;
        }
        if (auxL == nLinhas)
            auxL = 0;
        else
            auxL++;
        oss << endl;
    }
    return oss.str();
};

void Reserva::getToFile(const string& name) const {
    ostringstream oss;
    oss<<name<<".txt";
    ofstream MyFile(oss.str());

    for (Animal *it:animais) {
        MyFile<<it->getToFile();
    }
    for (Alimento *it:alimentos) {
        MyFile<<it->getToFile();
    }
    MyFile.close();
}

string Reserva::getAsStringPos(int linha,int coluna) const{
    ostringstream oss;
    oss << "Linha: " << linha << "Coluna: " << coluna << endl;
    if(existeAlimento(linha, coluna) == false)
        oss << "Nao existe alimentos nesta posicao" << endl;
    else{
        for(int i = 0; i < alimentos.size(); i++) {
            if(alimentos[i]->getX()== linha && alimentos[i]->getY() == coluna)
                oss << alimentos[i]->getAsString() << endl;
        }
    }
    if(existeAnimal(linha, coluna) == false)
        oss << "Nao existe animais nesta posicao" << endl;
    else{
        for(int i = 0; i < animais.size(); i++) {
            if(animais[i]->getX() == linha && animais[i]->getY() == coluna)
                oss << animais[i]->getAsString() << endl;
        }
    }
    return oss.str();
};


bool Reserva::existeAlimento(int x, int y) const
{
    for(int i = 0; i < alimentos.size(); i++){
        if(alimentos[i]->getX()== x && alimentos[i]->getY()== y)
            return true;
    }
    return false;
};

bool Reserva::existeAnimal(int x, int y) const
{
    for(int i = 0; i < animais.size(); i++){
        if(animais[i]->getX() == x && animais[i]->getY() == y)
            return true;
    }
    return false;
};



Reserva::~Reserva()
{
    animais.clear();
    alimentos.clear();
}

void Reserva::feed(int x,int y,int pontos_nutritivos,int toxicidade) {
    for(int i = 0; i < animais.size(); i++){
        if(animais[i]->getX() == x && animais[i]->getY() == y)
            animais[i]->alimentaUser(pontos_nutritivos,toxicidade);
    }
}

void Reserva::feedid(int id, int pontos_nutritivos, int toxicidade) {
    for (int i = 0; i < animais.size(); i++) {
        if (animais[i]->getID() == id) {
            animais[i]->alimentaUser(pontos_nutritivos, toxicidade);
        }
    }
}

void Reserva::restoreProgress(const string &filename) {
    ifstream file;
    string linha;
    file.open(filename);
    if (!file.is_open())
        cout<<"Erro ao abrir ficheiro de comandos"<<endl;
    else{
        for (auto it:animais) {
            removerAnimal(it->getID());
        }
        for (auto it:alimentos) {
            removerAlimento(it->getId());
        }
        while (getline(file,linha)){
            reconstruct(linha);
        }
        file.close();
        cin.ignore();
    }
}

void Reserva::reconstruct(const string &line) {
    istringstream iss(line);
    vector<string>arg;

    int i=0, id, linha, coluna;
    string tipo,n, nome;
    while (iss>>n){
        ++i;
        arg.push_back(n);
    }
    tipo=*arg.begin();

    if(tipo=="Animal"){
        /*Coelho(int id,int x,int y,const char &especie,const string &nome,int fome,int saude,int peso,const int &mov_dist);//apenas para recuperar reserva antiga
        //           3      7     8               1                    2        5         4         6             9
         oss<<"Animal "<<especie<<" "<<nome<<" "<<id<<" "<<saude<<" "<<fome<<" "<<peso<<" "<<x<<" "<<y<<" "<< mov <<endl;*/
        //         0      1           2           3         4         5           6          7       8          9
        if (toupper(arg[1].c_str()[0]) == 'C')
            adicionaAnimal(new Coelho(stoi(arg[3]), stoi(arg[7]), stoi(arg[8]), arg[1].c_str()[0], arg[2], stoi(arg[5]),
                                      stoi(arg[4]), stoi(arg[6]), stoi(arg[9]), stoi(arg[10]), instante));
        else if (toupper(arg[1].c_str()[0]) == 'O')
            adicionaAnimal(new Ovelha(stoi(arg[3]), stoi(arg[7]), stoi(arg[8]), arg[1].c_str()[0], arg[2], stoi(arg[5]),
                                      stoi(arg[4]), stoi(arg[6]), stoi(arg[9]), stoi(arg[10]), instante));
        else if (toupper(arg[1].c_str()[0]) == 'L')
            adicionaAnimal(new Lobo(stoi(arg[3]),stoi(arg[7]),stoi(arg[8]),arg[1].c_str()[0],arg[2],stoi(arg[5]),stoi(arg[4]),stoi(arg[6]),stoi(arg[9]),stoi(arg[10]), instante));
        else if (toupper(arg[1].c_str()[0]) == 'G')
            adicionaAnimal(new Canguru(stoi(arg[3]), stoi(arg[7]), stoi(arg[8]), arg[1].c_str()[0], arg[2],
                                       stoi(arg[5]), stoi(arg[4]), stoi(arg[6]), stoi(arg[9]), stoi(arg[10]), instante));
        else if (toupper(arg[1].c_str()[0]) == 'M')
            adicionaAnimal(new Misterio(stoi(arg[3]), stoi(arg[7]), stoi(arg[8]), arg[1].c_str()[0], arg[2],
                                        stoi(arg[5]), stoi(arg[4]), stoi(arg[6]), stoi(arg[9]), stoi(arg[10]), instante));
        total++;
    }else if(tipo=="Alimento"){
        /*Alimento_misterio(int id, int x, int y, const char &especie, int val_nutritivo, int toxicidade,const string &cheiro);
                                 3      6      7               1                2                   5                     8
         oss<<"Alimento "<<tipo<<" "<<val_nutritivo<<" "<<id<<" "<<instanteInicial<<" "<<toxicidade<<" "<<x<<" "<<y<<" "<<cheiro<<endl;
                   0         1              2              3            4                   5             6       7         8
                      */
        if (toupper(arg[1].c_str()[0]) == 'R')
            adicionaAlimento(new Relva(stoi(arg[3]),stoi(arg[6]),stoi(arg[7]),arg[1].c_str()[0],stoi(arg[2]),stoi(arg[5]),arg[8]));
        else if (toupper(arg[1].c_str()[0]) == 'T')
            adicionaAlimento(new Cenoura(stoi(arg[3]),stoi(arg[6]),stoi(arg[7]),arg[1].c_str()[0],stoi(arg[2]),stoi(arg[5]),arg[8]));
        else if (toupper(arg[1].c_str()[0]) == 'B')
            adicionaAlimento(new Bife(stoi(arg[3]),stoi(arg[6]),stoi(arg[7]),arg[1].c_str()[0],stoi(arg[2]),stoi(arg[5]),arg[8]));
        else if (toupper(arg[1].c_str()[0]) == 'A')
            adicionaAlimento(new Alimento_misterio(stoi(arg[3]),stoi(arg[6]),stoi(arg[7]),arg[1].c_str()[0],stoi(arg[2]),stoi(arg[5]),arg[8]));
        total++;
    };
}

void Reserva::atualizaPosicoes(int instante) {
    for (auto it:animais) {
        for (int i = 0; i <it->getMov_dist() ; ++i) {
            if(detetaProximidade(it->getID())) {
                int idAlim = getID_AlimProx(it->getID());
                if (idAlim<0)return;
                if (!alimentoCerto(it->getID(),idAlim)){
                    it->movimenta();
                    break;
                }
                if (getAlimento(idAlim)->getX() < it->getX() && getAlimento(idAlim)->getY() < it->getY()) { // 0 0   |   0 é menor
                    it->setX(it->getX() - 1);                                                                      //           1 é maior
                    it->setY(it->getY() - 1);
                } else if (getAlimento(idAlim)->getX() < it->getX() && getAlimento(idAlim)->getY() > it->getY()) {//   0 1
                    it->setX(it->getX() - 1);
                    it->setY(it->getY() + 1);
                }
                else if (getAlimento(idAlim)->getX() > it->getX() && getAlimento(idAlim)->getY() < it->getY()) {//   1 0
                    it->setX(it->getX() + 1);
                    it->setY(it->getY() - 1);
                }
                else if (getAlimento(idAlim)->getX() > it->getX() && getAlimento(idAlim)->getY() > it->getY()) {//   1 1
                    it->setX(it->getX() + 1);
                    it->setY(it->getY() + 1);
                }
                else if (getAlimento(idAlim)->getX() > it->getX() && getAlimento(idAlim)->getY() == it->getY())
                    it->setX(it->getX() + 1);
                else if (getAlimento(idAlim)->getX() < it->getX() && getAlimento(idAlim)->getY() == it->getY())
                    it->setX(it->getX() - 1);
                else if (getAlimento(idAlim)->getX() == it->getX() && getAlimento(idAlim)->getY() < it->getY())
                    it->setY(it->getY() - 1);
                else if (getAlimento(idAlim)->getX() == it->getX() && getAlimento(idAlim)->getY() > it->getY())
                    it->setY(it->getY() + 1);
            }
            else it->movimenta();

            if (it->getX()<0) it->setX(0);
            else if(it->getY()<0) it->setY(0);
            else if(it->getY()>nColunas) it->setY(nColunas);
            else if(it->getY()>nLinhas) it->setY(nLinhas);
        }

        if(existeAlimento(it->getX(), it->getY())){
            it->verificaComportamento(getAlimento(it->getX(), it->getY()), instante);
            if(getAlimento(it->getX(), it->getY())->getComido() == 1)
                removerAlimento(getAlimento(it->getX(), it->getY())->getId());
        }
    }
    for (auto it:animais) {
        if(it->getMorte() == true) {
            if (toupper(it->getEspecieChar()) == 'C')
                removerAnimal(it->getID());
            if (toupper(it->getEspecieChar()) == 'O') {
                adicionaAlimento(new Corpo(total, it->getX() + 1, it->getY(), 'p', it->getPeso(), 0, "carne"));
                removerAnimal(it->getID());
                total++;
            }
            if (toupper(it->getEspecieChar()) == 'L') {
                adicionaAlimento(new Corpo(total, it->getX() + 1, it->getY(), 'p', 10, 0, "carne"));
                removerAnimal(it->getID());
                total++;
            }
            if (toupper(it->getEspecieChar()) == 'G') {
                adicionaAlimento(new Corpo(total, it->getX() + 1, it->getY(), 'p', 15, 5, "carne"));
                removerAnimal(it->getID());
                total++;
            }
            if (toupper(it->getEspecieChar()) == 'M') {
                adicionaAlimento(new Bife(total, it->getX(), it->getY(), 'b', instante, 0, "carne"));
                removerAnimal(it->getID());
                total++;
            }
        }
    }
}


bool Reserva::detetaProximidade(int id) const{

    for (auto it :animais) {
        if(it->getID()==id){

            for (int i = it->getX()-it->getDetet_dist(); i < it->getX()+it->getDetet_dist() ; ++i) {


                for (int j = it->getY()-it->getDetet_dist(); j <it->getY()+it->getDetet_dist() ; ++j) {

                    if (existeAlimento(i,j)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool Reserva::detetaAnimal(int id) const {
    for (auto it :animais) {
        if(it->getID()==id){

            for (int i = it->getX()-it->getDetet_dist(); i < it->getX()+it->getDetet_dist() ; ++i) {


                for (int j = it->getY()-it->getDetet_dist(); j <it->getY()+it->getDetet_dist() ; ++j) {
                    if(i==it->getX()&&j==it->getY()) continue;

                    if (existeAnimal(i,j)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/*void Reserva::buscaAlimento() {
    int idAlim ;
    for (auto it:animais) {
        if(detetaProximidade(it->getID())){
            idAlim=getID_AlimProx(it->getID());
            return;
        }
    }
}*/

int Reserva::getID_AlimProx(int id) const {
    for (auto it :animais) {
        if(it->getID()==id){
            for (int i = it->getX()-it->getDetet_dist(); i < it->getX()+it->getDetet_dist() ; ++i) {
                for (int j = it->getY()-it->getDetet_dist(); j <it->getY()+it->getDetet_dist() ; ++j) {

                    if (existeAlimento(i,j)){
                        return getAlimento(i,j)->getId();
                    }
                }
            }
        }
    }
    return -1;
}

bool Reserva::alimentoCerto(int idAnimal, int idAlim) {
    if (toupper(getAnimal(idAnimal)->getEspecieChar()) == 'C'){
        if (getAlimento(idAlim)->getcheiro()=="verdura") {
            return true;}
    }
    else if (toupper(getAnimal(idAnimal)->getEspecieChar()) == 'O')
        if (getAlimento(idAlim)->getcheiro()=="erva") return true;
    else if (toupper(getAnimal(idAnimal)->getEspecieChar()) == 'L')
        if (getAlimento(idAlim)->getcheiro()=="carne") return true;

    return false;

}

void Reserva::adicionaCria() {
    Animal* cria;
    for (Animal* it:animais) {
        cria=it->procria(instante);
        if(cria!= nullptr){
            cria->setID(total);

            animais.push_back(cria);
            total++;
        }

    }
}

bool Reserva::getRedondezaAnim(int id, int dist) const {
    int Mpeso=0,x,y;
    for (auto it:animais) {
        if(it->getID()==id){
            for (int i = it->getX()-dist; i <it->getY()+dist ; ++i) {
                for (int j =it->getY()-dist ; j <it->getY()+dist ; ++j) {
                    if (existeAnimal(i,j) && id!= getAnimal(i,j)->getID()){
                        cout<<"fe";
                        if(Mpeso<getAnimal(i,j)->getPeso()){
                            Mpeso=getAnimal(i,j)->getPeso();
                                    x=i;
                                    y=j;
                        } ;

                    }
                }
            }

        }
    }
    if (existeAnimal(x,y)) {
        getAnimal(id)->interacaoAnimal(getAnimal(x,y));
        return true;
    }
    return false;
}













