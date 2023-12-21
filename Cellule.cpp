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
