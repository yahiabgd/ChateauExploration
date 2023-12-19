#ifndef MONSTREVOYANT_H
#define MONSTREVOYANT_H

#include "Monstre.h"


class MonstreVoyant : public Monstre
{
    public:
        MonstreVoyant();
        virtual ~MonstreVoyant();
        void deplacervers(const Aventurier& aventurier) override;

    protected:

    private:
};

#endif // MONSTREVOYANT_H
