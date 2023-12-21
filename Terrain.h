#ifndef TERRAIN_H
#define TERRAIN_H
#include "Cellule.h"
#include <vector>
#include <iostream>
using namespace std;
class Terrain
{
    public:
        Terrain(int lignes,int colonnes);
        int colonnes()const;
        int lignes() const;
        Cellule::TypeCellule cellule(int x,int y)const;
        void miseajourcellule(int x , int y , const Cellule::TypeCellule type);
        void afficher();
    private:
        vector<vector<Cellule>> d_terrain;
        int d_colonnes;
        int d_lignes;
};

#endif // TERRAIN_H
