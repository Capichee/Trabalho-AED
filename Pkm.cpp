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
    do {
        cout << '\n' << "Aperte ENTER para continuar.";
    } while (cin.get() != '\n');
    system("clear");
}

void registra_pokemon(treinador * t){
    while(t->nextPkm != NULL){
        t = t->nextPkm;
    }
    if(t->count == 5){
        cout << "Você não pode ter mais de 6 pokemons!" << endl;
        return;
    }
    t->nextPkm = (treinador *)malloc(sizeof(treinador));
    t->nextPkm->nextPkm = NULL;
    t->nextPkm->count = t->count + 1;
}

void escolha_pokemon(int escolha, treinador * t){
    switch(escolha){
        case 1: {
            void registra_pokemon(treinador * t);
            t->caughtPkm.lvl = 5;
            t->caughtPkm.exp = 0;
            t->caughtPkm.atk = 65;
            t->caughtPkm.def = 49;
            t->caughtPkm.vel = 45;
            t->caughtPkm.isdualtype = true;
            t->caughtPkm.nomePKM = "Bulbasaur";
            t->caughtPkm.tipo1 = "grama";
            t->caughtPkm.tipo2 = "venenoso";
            t->caughtPkm.hp = 45;
            t->caughtPkm.hpmax = 45;
            t->caughtPkm.ATKs.move1 = "Investida";
            t->caughtPkm.ATKs.power1 = 40;
            t->caughtPkm.ATKs.acc1 = 100;
            t->caughtPkm.ATKs.move2 = "Rosnado";
            t->caughtPkm.ATKs.power2 = 0;
            t->caughtPkm.ATKs.acc2 = 100;
            t->caughtPkm.ATKs.move3 = "Folha navalha";
            t->caughtPkm.ATKs.power3 = 55;
            t->caughtPkm.ATKs.acc3 = 90;
            t->caughtPkm.ATKs.move4 = "Chicote de cipó";
            t->caughtPkm.ATKs.power4 = 45;
            t->caughtPkm.ATKs.acc4 = 100;
            break;
        }
        case 2:{
            void registra_pokemon(treinador * t);
            t->caughtPkm.lvl = 5;
            t->caughtPkm.exp = 0;
            t->caughtPkm.atk = 52;
            t->caughtPkm.def = 43;
            t->caughtPkm.vel = 65;
            t->caughtPkm.isdualtype = false;
            t->caughtPkm.nomePKM = "Chamander";
            t->caughtPkm.tipo1 = "fogo";
            t->caughtPkm.tipo2 = "fogo";
            t->caughtPkm.hp = 39;
            t->caughtPkm.hpmax = 39;
            t->caughtPkm.ATKs.move1 = "Arranhar"; // Normal
            t->caughtPkm.ATKs.power1 = 40;
            t->caughtPkm.ATKs.acc1 = 100;
            t->caughtPkm.ATKs.move2 = "Rosnado"; // Normal
            t->caughtPkm.ATKs.power2 = 0;
            t->caughtPkm.ATKs.acc2 = 100;
            t->caughtPkm.ATKs.move3 = "Brasa"; // Fogo
            t->caughtPkm.ATKs.power3 = 40;
            t->caughtPkm.ATKs.acc3 = 100;
            t->caughtPkm.ATKs.move4 = "Sopro do Dragão"; // Fogo
            t->caughtPkm.ATKs.power4 = 60;
            t->caughtPkm.ATKs.acc4 = 100;
            break;
        }
        case 3:{
            void registra_pokemon(treinador * t);
            t->caughtPkm.lvl = 5;
            t->caughtPkm.exp = 0;
            t->caughtPkm.atk = 48;
            t->caughtPkm.def = 65;
            t->caughtPkm.vel = 43;
            t->caughtPkm.isdualtype = false;
            t->caughtPkm.nomePKM = "Squirtle";
            t->caughtPkm.tipo1 = "agua";
            t->caughtPkm.tipo2 = "agua";
            t->caughtPkm.hp = 44;
            t->caughtPkm.hpmax = 44;
            t->caughtPkm.ATKs.move1 = "Cabeçada"; // Normal
            t->caughtPkm.ATKs.power1 = 40;
            t->caughtPkm.ATKs.acc1 = 100;
            t->caughtPkm.ATKs.move2 = "Chicote de Cauda"; // Normal
            t->caughtPkm.ATKs.power2 = 0;
            t->caughtPkm.ATKs.acc2 = 100;
            t->caughtPkm.ATKs.move3 = "Bala de Agua";// Agua
            t->caughtPkm.ATKs.power3 = 40;
            t->caughtPkm.ATKs.acc3 = 100;
            t->caughtPkm.ATKs.move4 = "Pulso de Agua";// Agua
            t->caughtPkm.ATKs.power4 = 60;
            t->caughtPkm.ATKs.acc4 = 100;
            break;
        }
        default: {
            cout << "Escolha inválida!" << endl;
            break;
        }
    }
}
