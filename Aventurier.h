#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "Personnage.h"
#include "Bourse.h"
#include "Epee.h"
#include "Armure.h"
#include "Terrain.h"

class Monstre;

class Aventurier : public Personnage
{
    public:
        Aventurier(int pointForce, int pointVie, Position position,const Armure& armure, const Epee& epee, const Bourse& bourse, bool amulette);
        void recoitAttaque(int degats) override;
        void attaque(Monstre &monstre);
        enum class Direction {HAUT , BAS , DROITE, GAUCHE, HAUTDROITE, HAUTGAUCHE, BASDROITE, BASGAUCHE};
        void deplacer(const Direction& Direction, const Terrain& terrain);

    private:
        Armure d_armure;
        Epee d_epee;
        Bourse d_bourse;
        bool d_amulette;

};

#endif // AVENTURIER_H
