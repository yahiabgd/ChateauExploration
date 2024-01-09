#ifndef MONSTREVOYANT_H
#define MONSTREVOYANT_H

#include <queue>
#include <algorithm>
#include "Monstre.h"


#include"Position.h"

class MonstreVoyant : public Monstre
{
    public:
        MonstreVoyant(int pointForce, int pointVie, Position position, int habilete);
        virtual ~MonstreVoyant();
        void deplacervers( Aventurier& aventurier,  Terrain& terrain) override;

    protected:

    private:
        void deplacementAleatoire(Terrain& terrain)override;

        // elle renvoi le chemin le plus court vers l'aventurier
        std::vector<Position> cheminVersAventurier(const Aventurier& aventurier, Terrain& terrain);
};

#endif // MONSTREVOYANT_H
