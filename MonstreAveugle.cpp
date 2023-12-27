#include "MonstreAveugle.h"

MonstreAveugle::MonstreAveugle(int pointForce, int pointVie, Position position, int habilete):
    Monstre{pointForce, pointVie, position, habilete}
{
    //ctor
}

MonstreAveugle::~MonstreAveugle()
{
    //dtor
}

void MonstreAveugle::deplacervers(const Aventurier& aventurier,  Terrain& terrain) {
    if(aventurier.position().distance(d_position)<=1.5){
        // il va attaqué l'Aventurier
    }
    //deplacement aléatoire
}

void MonstreAveugle::deplacementAleatoire(Terrain& terrain){
    // il peut se déplacer en diagonale

}
