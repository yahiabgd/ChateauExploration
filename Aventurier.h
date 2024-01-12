#ifndef AVENTURIER_H
#define AVENTURIER_H

#include <memory>

#include "Personnage.h"
#include "Bourse.h"
#include "Epee.h"
#include "Armure.h"
#include "Terrain.h"

class Monstre;

enum class Direction {HAUT , BAS , DROITE, GAUCHE, HAUTDROITE, HAUTGAUCHE, BASDROITE, BASGAUCHE};
class Aventurier : public Personnage
{
    public:
        Aventurier(int pointForce, int pointVie, const Position& position,const Armure& armure, const Epee& epee, const Bourse& bourse, bool amulette);
        Aventurier( const Position& position);
        void RamasseAmulette();
        void RamasseTasDePiece(int nombreDePiece);
        void recoitAttaque(int degats) override;
        void reparerEquipements();
        void attaque(Monstre &monstre);
        bool amulette() const;
        void deplacer(const Position& position);
        void deplacer(const Direction& direction);
        int pieces()const;
        Armure armure()const;
        Epee epee() const;

    private:
        int d_pointVie;
        Armure d_armure;
        Epee d_epee;
        Bourse d_bourse;
        bool d_amulette;

};

#endif // AVENTURIER_H
