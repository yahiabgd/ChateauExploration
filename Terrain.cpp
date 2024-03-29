#include "Terrain.h"

Terrain::Terrain(int lignes,int colonnes):d_lignes{lignes},d_colonnes{colonnes}
{
    d_terrain = vector<vector<Cellule>>(d_colonnes, vector<Cellule>(d_lignes, Cellule::TypeCellule::HORS));

}
Terrain::Terrain(const string& nomfichier)
{
    ifstream fichier(nomfichier);
    if (!fichier.is_open())
        throw runtime_error("Echec D'ouverture du fichier" + nomfichier);

    int fLignes, fColonnes;
    fichier >> fColonnes >> fLignes;

    if (fLignes <= 0 || fColonnes <= 0)
    {
        fichier.close();
        throw runtime_error("Dimensions invalide : " + nomfichier);
    }

    int nbLignes = 0, nbColonnes = 0;
    string sligne;
    getline(fichier, sligne);

    // Calcul du nombre de lignes et colonnes dans le fichier
    while (getline(fichier, sligne))
    {
        nbLignes++;
        nbColonnes = (nbColonnes > sligne.size()) ? nbColonnes : static_cast<int>(sligne.size());
    }

    if (nbLignes != fLignes || nbColonnes != fColonnes)
    {
        fichier.close();
        throw runtime_error("Dimensions invalide 2 : " + nomfichier);
    }

    d_colonnes = nbColonnes;
    d_lignes = nbLignes;

    // Resize and initialize the terrain with empty cells
    d_terrain.resize(d_colonnes, std::vector<Cellule>(d_lignes, Cellule(Cellule::TypeCellule::VIDE)));

    fichier.clear();
    fichier.seekg(0, ios::beg);
    getline(fichier, sligne);

    for (int y = 0; y < d_lignes; y++)
    {
        getline(fichier, sligne);

        for (int x = 0; x < d_colonnes; x++)
        {
            char type = (x < static_cast<int>(sligne.size())) ? sligne[x] : ' ';
            if (Cellule::estType(type))
            {
                d_terrain[x][y] = Cellule::TypeCellule(type);
            }
            else
            {
                fichier.close();
                throw runtime_error("Type de cellule inconnu : " + string{type});
            }
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

void Terrain::miseajourcellule(int x, int y, const Cellule::TypeCellule type)
{
    if(y <d_lignes && x < d_colonnes)
        d_terrain[x][y].changecontenu(type);
    else
        std::cerr << " Case hors des limites du terrain" << std::endl;
}
void Terrain::changenbcolonnes(int colonnes)
{
    for (auto& row : d_terrain)
    {
        row.resize(colonnes, Cellule::TypeCellule::VIDE);
    }
    d_colonnes = colonnes;
}
void Terrain::changenblignes(int lignes)
{
    d_terrain.resize(lignes, std::vector<Cellule>(d_colonnes, Cellule::TypeCellule::VIDE));
    d_lignes = lignes;
}
bool Terrain::sauvegarder(const std::string& nomfichier) const
{


    std::ofstream fichier(nomfichier);
    if (!fichier.is_open())
    {
        std::cerr << "Erreur d'ouverture du fichier : " << nomfichier << std::endl;
        return false;
    }
    fichier << d_colonnes << " " << d_lignes << "\n";
    for (int y = 0; y < d_lignes; ++y)
    {
        for (int x = 0; x < d_colonnes; ++x)
        {
            Cellule::TypeCellule contenu = cellule(x, y);
            fichier << static_cast<char>(contenu);
        }
        //Si ce n'est pas la derni�re ligne on ajoute un retour � la ligne
        if (y < d_lignes - 1)
            fichier << "\n";
    }

    fichier.close();
    return true;
}

bool Terrain::estvalide() const
{
    int joueur = 0;
    int sortie = 0;
    int amulette = 0;
    for (const auto& ligne : d_terrain)
    {
        for (const auto& cellule : ligne)
        {
            switch (cellule.contenu())
            {
            case Cellule::TypeCellule::JOUEUR:
                joueur++;
                break;
            case Cellule::TypeCellule::SORTIE:
                sortie++;
                break;
            case Cellule::TypeCellule::AMULETTE:
                amulette++;
                break;
            default:
                // Ne rien faire pour les autres types de cellules
                break;
            }
        }
    }
    // Le terrain est consid�r� valide s'il contient un seul joueur, au moins une sortie et une seule amulette
    return (joueur == 1) && (sortie > 0) && (amulette == 1);
}
bool Terrain::positionValide(int x, int y)const{
    bool valide = true;
     if (x < 0 || x >= d_terrain.size() || y < 0 || y >= d_terrain[0].size()) {
        valide=false;
    }
    return valide;
}
