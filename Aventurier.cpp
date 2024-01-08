#include "Aventurier.h"
#include "Monstre.h"

Aventurier::Aventurier(int pointForce, int pointVie, Position position,
                       const Armure& armure, const Epee& epee,
                       const Bourse& bourse, bool amulette=false) :
    Personnage{pointForce, pointVie, position},
    d_armure{armure}, d_epee{epee}, d_bourse{bourse}, d_amulette{amulette}
{}

void Aventurier::recoitAttaque(int degats) {
    int nb = static_cast<int>((3/4) * degats);
    if (nb <= d_armure.pointSolide())
        d_armure.reduireSolidite(nb);
    else {
        int reste = ((1/4) * degats) + (nb - d_armure.pointSolide());
        d_pointVie -= reste;
    }
}


void Aventurier::attaque(Monstre &monstre) {
    int damage = d_pointForce + d_epee.pointSolide();
    if ( rand() % 100  <  80)
        damage *=  0.9 ;
    d_epee.reduireSolidite(1);
    monstre.recoitAttaque(damage);
    if(! monstre.estVivant()){
        d_pointForce += monstre.pointForce() * 1/4;
        d_pointVie += monstre.pointForce() * 3/4;
    }
}
