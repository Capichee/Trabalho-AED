#ifndef trabalho_h
#define trabalho_h

    //Pokémon//

    typedef struct{
        int vida, exp, status, atk, def, vel;
    }pokemon;

    typedef struct{
        pokemon * nextpkm;
    }treinador;

#endif
