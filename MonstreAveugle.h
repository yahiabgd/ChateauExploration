#ifndef MONSTREAVEUGLE_H
#define MONSTREAVEUGLE_H

#include "Monstre.h"


class MonstreAveugle : public Monstre
{
    public:
        MonstreAveugle(int pointForce, int pointVie, Position position, int habilete);
        virtual ~MonstreAveugle();
        void deplacervers(const Aventurier& aventurier, Terrain& terrain) override;
    protected:

    private:
        void deplacementAleatoire(Terrain& terrain)override;
};

#endif // MONSTREAVEUGLE_H
