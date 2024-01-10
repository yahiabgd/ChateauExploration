#include "Aventurier.h"
#include "Monstre.h"
#include "Position.h"

constexpr double UNQUART {1/4};
constexpr double TROISQUART {3/4};


Aventurier::Aventurier(int pointForce, int pointVie, Position position,
                       const Armure& armure, const Epee& epee,
                       const Bourse& bourse, bool amulette=false) :
    Personnage{pointForce, pointVie, position},
    d_armure{armure}, d_epee{epee}, d_bourse{bourse}, d_amulette{amulette}
{}

void Aventurier::RamasseAmulette()
{ d_amulette = true; }

void Aventurier::RamasseTasDePiece(int nombreDePiece) {
    d_bourse.ajouter(nombreDePiece);
}

void Aventurier::recoitAttaque(int degats) {
    int nb = static_cast<int>(UNQUART * degats);
    if (nb <= d_armure.pointSolidite())
        d_armure.reduireSolidite(nb);
    else {
        int reste = (UNQUART * degats) + (nb - d_armure.pointSolidite());
        d_pointVie -= reste;
    }
}


void Aventurier::attaque(Monstre &monstre) {
    int damage = d_pointForce + d_epee.pointSolidite();
    if ( rand() % 100  <  80)
        damage *=  0.9 ;
    d_epee.reduireSolidite(1);
    monstre.recoitAttaque(damage);
    if(! monstre.estVivant()){
        d_pointForce += monstre.pointForce() * UNQUART;
        d_pointVie += monstre.pointForce() * TROISQUART;
    }
}

void Aventurier::deplacer(const Direction& Direction){
    Position New{d_position};
    switch(Direction) {
        case Direction::HAUT : New.deplacerDe(0,-1);
                break;
        case Direction::BAS : New.deplacerDe(0,1);
            break;
        case Direction::DROITE : New.deplacerDe(1,0);
            break;
        case Direction::GAUCHE : New.deplacerDe(-1,0);
            break;
        case Direction::HAUTDROITE : New.deplacerDe(1,-1);
            break;
        case Direction::HAUTGAUCHE : New.deplacerDe(-1,-1);
            break;
        case Direction::BASDROITE : New.deplacerDe(1,1);
            break;
        case Direction::BASGAUCHE : New.deplacerDe(-1,1);
            break;
    }
    d_position = New;
//        if(terrain->cellule(d_aventurier->position.x(), d_aventurier->d_position.y()) != Cellule::TypeCellule::MUR)
//        {
//            d_terrain->miseajourcellule(d_position.x(),d_position.y(),Cellule::TypeCellule::VIDE);
//            d_terrain->miseajourcellule(d_position.x(),d_position.y(),Cellule::TypeCellule::JOUEUR);
//        }

}
int Aventurier::pieces()const
{
    return d_bourse.pieceMonnaie();
}

bool Aventurier::amulette() const
{
    return d_amulette;
}
Armure Aventurier::armure()const
{
    return d_armure;
}

Epee Aventurier::epee() const
{
    return d_epee;
}
