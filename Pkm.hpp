#ifndef PKM_HPP
#define PKM_HPP

#include <string>

using namespace std;

typedef struct Moves {
    string move1, move2, move3, move4;
    int power1, power2, power3, power4;
    int acc1, acc2, acc3, acc4;
} moves;

typedef struct Pokemon {
    int lvl, exp, atk, def, vel;
    bool isdualtype;
    string nome, tipo1, tipo2;
    int hp, hpmax;
    moves ATKs;
    Pokemon * next;
} pokemon;

typedef struct Treinador {
    pokemon * caughtPkm;
    int count;
} treinador;

typedef struct Mochila {
    string nome;
    int pokebolas;
    float dinheiro;
} mochila;

mochila * mochila_introducao(const string& Nome);

void limpa_dialogo();

void escolha_pokemon(int escolha, treinador * t);

#endif