#include "Terrain.h"

Terrain::Terrain(int lignes,int colonnes):d_lignes{lignes},d_colonnes{colonnes}
{
    d_terrain = vector<vector<Cellule>>(d_lignes, vector<Cellule>(d_colonnes, Cellule::TypeCellule::VIDE));
}
int Terrain::colonnes() const
{
    return d_colonnes;
}
int Terrain::lignes() const
{
    return d_lignes;
}
Cellule::TypeCellule Terrain::cellule(int x,int y)const
{
    return d_terrain[x][y].contenu();
}

void Terrain::miseajourcellule(int x , int y , const Cellule::TypeCellule type)
{
    d_terrain[x][y].changecontenu(type);
}
void Terrain::afficher()
{
    for(int i =0;i<d_lignes;i++)
    {
        for(int j=0;j<d_colonnes;j++)
            cout << static_cast<char>(cellule(i,j));
        cout << endl;
    }
}
