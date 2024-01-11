#ifndef MONSTRE_H
#define MONSTRE_H

#include <vector>
#include"Personnage.h"
#include"Aventurier.h"
#include"Terrain.h"

class Monstre : public Personnage
{
    public:
        Monstre(int pointForce, int pointVie, Position position, int habilete);
        virtual ~Monstre();
        virtual void deplacervers(Aventurier& aventurier,Terrain& terrain);
        void attaque(Aventurier& ennemi);
        int habilete()const;
        void recoitAttaque(int degats) override;

    private:
        virtual void deplacementAleatoire(Terrain& terrain);
        int d_habilete; // un pourcentage par exemple 100%
};

#endif // MONSTRE_H
