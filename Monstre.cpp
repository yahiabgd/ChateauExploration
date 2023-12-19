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

}

void Monstre::recoitAttaque(int degats){
    d_pointVie-= degats;
    if(d_pointVie < 0)
        d_pointVie=0;
}

void Monstre::deplacervers(const Aventurier& aventurier){
}
