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


void Personnage::recoitAttaque(int degats){

}

void Personnage::deplacement(char direction){
    // à déclarer
}
Position Personnage::position()const{
    return d_position;
}
