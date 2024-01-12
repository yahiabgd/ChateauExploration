#include "Cellule.h"

Cellule::Cellule(const TypeCellule type):d_contenu{type}
{

}
Cellule::TypeCellule Cellule::contenu() const
{
    return d_contenu;
}
void Cellule::changecontenu(const TypeCellule contenu)
{
    d_contenu = contenu;
}
bool Cellule::estType(char type)
{
    return (type == static_cast<char>(TypeCellule::VIDE) || type == static_cast<char>(TypeCellule::MUR) || type == static_cast<char>(TypeCellule::AMULETTE) || type == static_cast<char>(TypeCellule::MONSTRE)||type == static_cast<char>(TypeCellule::SMONSTRE)|| type == static_cast<char>(TypeCellule::JOUEUR)|| type == static_cast<char>(TypeCellule::PIECE)|| type == static_cast<char>(TypeCellule::SORTIE)|| type == static_cast<char>(TypeCellule::HORS));
}
Cellule::TypeCellule toTypeCellule(const char c)
{
    switch(c)
    {
        case ' ' : return Cellule::TypeCellule::VIDE;
        case '#' : return Cellule::TypeCellule::MUR ;
        case 'A' : return Cellule::TypeCellule::AMULETTE;
        case 'm' : return Cellule::TypeCellule::MONSTRE;
        case 'M' : return Cellule::TypeCellule::SMONSTRE;
        case 'P' : return Cellule::TypeCellule::JOUEUR;
        case '$' : return Cellule::TypeCellule::PIECE;
        case '-' : return Cellule::TypeCellule::SORTIE;
        case '*' : return Cellule::TypeCellule::HORS;
        default :
            return Cellule::TypeCellule::VIDE;
    }
}

