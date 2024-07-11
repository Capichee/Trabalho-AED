#ifndef pkm_h
#define pkm_h

    //Pokémon//

    typedef struct{
        int vida;
        int exp;
        int status;
        int atk;
        int def;
        int vel;
    }pokemon;

    typedef struct{
        pokemon * nextpkm;
    }treinador;

#endif
