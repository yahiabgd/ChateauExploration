#ifndef MONSTREAVEUGLE_H
#define MONSTREAVEUGLE_H

#include "Monstre.h"


class MonstreAveugle : public Monstre , public Personnage
{
    public:
        MonstreAveugle();
        virtual ~MonstreAveugle();
        void deplacervers(const Aventurier& aventurier) override;

    protected:

    private:
};

#endif // MONSTREAVEUGLE_H
