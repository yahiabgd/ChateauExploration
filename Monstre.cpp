#include "Monstre.h"



Monstre::Monstre()
{
    //ctor
}

Monstre::~Monstre()
{
    //dtor
}

void Monstre::attaque(Aventurier& ennemi){
    // calculer la force de l'attaque;
    int force=0;
    ennemi.recoitAttaque(force);
}

void Monstre::recoitAttaque(int degats){
    d_pointVie-= degats;
    if(d_pointVie < 0)
        d_pointVie=0;
}

void Monstre::deplacervers(const Aventurier& aventurier){
}
