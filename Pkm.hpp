#ifndef PKM_HPP
#define PKM_HPP
#include <string>

using namespace std;

struct moves {
    string move;
    int power;
    int acc;
    int pp;
    string type;
    int moveIndex;
    moves* nextMove;
};

struct Pokemon {
    string nomePKM;
    string tipo1;
    string tipo2;
    int lvl;
    int exp;
    int atk;
    int def;
    int vel;
    int hp;
    int hpmax;
    bool isdualtype;
    moves ATKs;
};

struct treinador {
    Pokemon caughtPkm;
    int count;
    treinador* nextPkm;
};

struct mochila {
    string nome;
    int pokebolas;
    double dinheiro;
};

mochila* mochila_introducao(const string& Nome);
void limpa_dialogo();
void registra_pokemon(treinador* t);
void registra_move(moves* m, const string& move, int power, int acc, int pp, const string& type);
void banco_pokemon(treinador* t);
bool verifica_super(treinador* t, treinador* oponente);
bool pokemon_move(int ataque, treinador* t);
bool captura_pokemon(treinador* t, const Pokemon& wildPkm);
bool pokemon_acc(int ataque, treinador* t);
void inicializa_pokemon(treinador* t, const string& nome, const string& tipo1, const string& tipo2, int lvl, int exp, int atk, int def, int vel, int hp, int hpmax);
void inicia_batalha(treinador* t, treinador* oponente, mochila* m);
void delete_pokemon(Pokemon& pkm);
void copy_pokemon(Pokemon& dest, const Pokemon& src);
int calculate_damage(treinador * t, treinador * oponente, int move_power, bool is_super_effective);

#endif // PKM_HPP
