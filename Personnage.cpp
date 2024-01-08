#include "Personnage.h"

Personnage::Personnage(int pointForce, int pointVie, Position position):
    d_pointForce{pointForce},
    d_pointVie{pointVie},
    d_position{position}
{
    //ctor
}

Personnage::~Personnage()
{
    //dtor
}

int Personnage::pointForce() const
{ return d_pointForce; }

int Personnage::pointVie() const
{ return d_pointVie; }

void Personnage::deplacement(char direction){
    // à déclarer
}
Position Personnage::position()const{
    return d_position;
}

bool Personnage::estVivant() const{
    return d_pointVie>0 ? true : false;
}
