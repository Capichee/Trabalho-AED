#include <cstring>
#include "Pkm.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>

mochila * mochila_introducao(const string& Nome){
    mochila * m;
    m = (mochila *)malloc(sizeof(mochila));
    m->nome = Nome;
    m->pokebolas = 10;
    m->dinheiro = 1000.0;
    return m;
}

void limpa_dialogo(){
    system("pause");
    system("cls");
}