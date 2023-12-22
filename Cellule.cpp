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
