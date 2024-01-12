#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include"Position.h"
#include "Cellule.h"
class Personnage
{
    public:

        Personnage(int pointForce, int pointVie, Position position);
        virtual ~Personnage();
        int pointForce() const;
        int pointVie() const;
        void reduirePointVie(int points);
        virtual void recoitAttaque(int degats) = 0;
        bool estVivant() const;
        Position position()const;
        Cellule::TypeCellule estSur() const;
        Cellule::TypeCellule modifieEstSur(Cellule::TypeCellule type);

    protected:
        Cellule::TypeCellule d_estSur;
        int d_pointForce;
        int d_pointVie;
        Position d_position;

};

#endif // PERSONNAGE_H
