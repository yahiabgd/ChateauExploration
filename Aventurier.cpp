#include "Aventurier.h"
#include "Monstre.h"
#include "Position.h"

constexpr double UNQUART {1.0/4.0};
constexpr double TROISQUART {3.0/4.0};


Aventurier::Aventurier(int pointForce, int pointVie, const Position& position,
                       const Armure& armure, const Epee& epee,
                       const Bourse& bourse, bool amulette=false) :
    Personnage{pointForce, pointVie, position},
    d_armure{armure}, d_epee{epee}, d_bourse{bourse}, d_amulette{amulette}
{}
Aventurier::Aventurier( const Position& position):Personnage{25, 100, position},
    d_armure{20}, d_epee{15}, d_bourse{0}, d_amulette{false}
{

}
void Aventurier::reparerEquipements()
{
    int pieces= d_bourse.pieceMonnaie();
    int reste = pieces - pieces/2;
    d_armure.reparer(reste);
    d_epee.reparer(pieces/2);
    d_bourse.enlever(pieces);
}
void Aventurier::RamasseAmulette()
{ d_amulette = true; }

void Aventurier::RamasseTasDePiece(int nombreDePiece) {
    d_bourse.ajouter(nombreDePiece);
}

void Aventurier::recoitAttaque(int degats) {
    int nb = static_cast<int>(TROISQUART * degats);
    int resteattaque=degats -nb;
    if(d_armure.pointSolidite() > 0 )
    {
        int restearmure =  d_armure.pointSolidite() - (nb/2);
        if(restearmure >= 0)
            d_armure.reduireSolidite(nb/2 );
        else
        {
            resteattaque+=(-restearmure);
            d_armure.reduireSolidite(d_armure.pointSolidite());
        }
        reduirePointVie(resteattaque);
    }
    else
    {
        reduirePointVie(degats);
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

void Aventurier::deplacer(const Position& position){
    d_position = position;
    /*switch(position) {
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
            */
//        if(terrain->cellule(d_aventurier->position.x(), d_aventurier->d_position.y()) != Cellule::TypeCellule::MUR)
//        {
//
//        }

}
void Aventurier::deplacer(const Direction& direction){
    Position New = position();
    switch(direction) {
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
