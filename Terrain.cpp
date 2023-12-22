#include "Terrain.h"

Terrain::Terrain(int lignes,int colonnes):d_lignes{lignes},d_colonnes{colonnes}
{
    d_terrain = vector<vector<Cellule>>(d_lignes, vector<Cellule>(d_colonnes, Cellule::TypeCellule::VIDE));
}
Terrain::Terrain(const string& nomfichier)
{
    ifstream fichier(nomfichier);
    if (!fichier.is_open())
        throw runtime_error("Echec D'ouverture du fichier" + nomfichier);
    int fLignes,fColonnes;
    fichier>>fLignes>>fColonnes;
    if(fLignes <= 0 || fColonnes<=0)
        throw runtime_error("Dimensions invalide : " + nomfichier);
    int nbLignes =0,nbColonnes=0;
    string sligne;
    getline(fichier, sligne);
    //calcul du nombre de lignes et colonnes dans le fichier
    while (getline(fichier, sligne)) {
        nbLignes++;
        nbColonnes = (nbColonnes> sligne.size())? nbColonnes:  sligne.size() ;
    }
    if(nbLignes != fLignes || nbColonnes != fColonnes)
        throw runtime_error("Dimensions invalide 2 : " + nomfichier);
    d_colonnes= nbColonnes;
    d_lignes=nbLignes;
    d_terrain.resize(d_lignes, std::vector<Cellule>(d_colonnes,Cellule(Cellule::TypeCellule::VIDE)));
    fichier.clear();
    fichier.seekg(0, ios::beg);
    getline(fichier, sligne);
    for(int i =0; i<d_lignes;i++)
    {
        getline(fichier,sligne);
        for(int j=0; j < d_colonnes;j++)
        {
            char type = (j < sligne.size()) ? sligne[j] : ' ';
            d_terrain[i][j] = Cellule::TypeCellule(type);
        }
    }
    fichier.close();
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
void Terrain::afficher() const
{
    for(int i =0;i<d_lignes;i++)
    {
        for(int j=0;j<d_colonnes;j++)
            cout << static_cast<char>(cellule(i,j));
        cout << endl;
    }
}
void Terrain::changenbcolonnes(int colonnes)
{
     for (auto& row : d_terrain) {
        row.resize(colonnes, Cellule::TypeCellule::VIDE);
    }
     d_colonnes = colonnes;
}
void Terrain::changenblignes(int lignes)
{
     d_terrain.resize(lignes, std::vector<Cellule>(d_colonnes, Cellule::TypeCellule::VIDE));
      d_lignes = lignes;
}

