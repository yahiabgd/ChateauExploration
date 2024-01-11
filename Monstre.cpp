#include "Monstre.h"



Monstre::Monstre(int pointForce, int pointVie, Position position, int habilete):
    Personnage(pointForce, pointVie,position),
    d_habilete{habilete}
{

}

Monstre::~Monstre()
{
    //dtor
}

void Monstre::attaque(Aventurier& ennemi){
    // calculer la force de l'attaque;

    int force = d_pointForce*0.9;
    std::cout<< force;

    if(rand() % 100 < static_cast<int>(d_habilete) ){ // ?? not sure
        ennemi.recoitAttaque(force);
    }

}

void Monstre::recoitAttaque(int degats){
    d_pointVie-= degats;
    if(d_pointVie < 0)
        d_pointVie=0;
}

void Monstre::deplacementAleatoire(Terrain& terrain){
    //const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
}

void Monstre::deplacervers( Aventurier& aventurier,Terrain& terrain){

}
int Monstre::habilete()const{
    return d_habilete;
}
