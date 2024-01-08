#ifndef TERRAIN_H
#define TERRAIN_H
#include "Cellule.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;
class Terrain
{
    public:
        Terrain(int lignes,int colonnes);
        Terrain(const string& nomfichier);
        int colonnes()const;
        int lignes() const;
        Cellule::TypeCellule cellule(int i, int j)const;
        void miseajourcellule(int i, int j , const Cellule::TypeCellule type);
        void changenbcolonnes(int colonnes);
        void changenblignes(int lignes);
        void afficher() const;
        bool estvalide() const;
        bool positionValide(int x, int y)const;
        bool sauvegarder(const string& nomfichier) const;
    private:
        vector<vector<Cellule>> d_terrain;
        int d_colonnes;
        int d_lignes;
};

#endif // TERRAIN_H
