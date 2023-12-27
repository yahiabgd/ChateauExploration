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
        virtual void deplacervers(const Aventurier& aventurier,Terrain& terrain);
        void attaque(Aventurier& ennemi);
        void recoitAttaque(int degats) override;

    private:
        virtual void deplacementAleatoire(Terrain& terrain);
        int d_habilete; // un pourcentage
};

#endif // MONSTRE_H
