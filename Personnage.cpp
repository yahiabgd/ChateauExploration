#include "Personnage.h"

Personnage::Personnage(int pointForce, int pointVie, Position position):
    d_pointForce{pointForce},
    d_pointVie{pointVie},
    d_position{position},
    d_estSur{Cellule::TypeCellule::VIDE}
{}

Personnage::~Personnage()
{}

int Personnage::pointForce() const
{ return d_pointForce; }

int Personnage::pointVie() const
{ return d_pointVie; }

Cellule::TypeCellule Personnage::estSur() const
{
    return d_estSur;
}
Cellule::TypeCellule Personnage::modifieEstSur(Cellule::TypeCellule type)
{
    d_estSur = type;
}

void Personnage::reduirePointVie(int points)
{ d_pointVie -= points ;}

Position Personnage::position()const{
    return d_position;
}

bool Personnage::estVivant() const{
    return d_pointVie>0;
}

