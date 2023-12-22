#ifndef MONSTRE_H
#define MONSTRE_H

#include"Personnage.h"
#include"Aventurier.h"

class Monstre : public Personnage
{
    public:
        Monstre();
        virtual ~Monstre();
        // void deplacement();
        virtual void deplacervers(const Aventurier& aventurier);
        void attaque(Aventurier& ennemi);
        void recoitAttaque(int degats) override;

    private:
        int d_habilete;
};

#endif // MONSTRE_H
