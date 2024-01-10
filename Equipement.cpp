#include "Equipement.h"

Equipement::Equipement(int pointSolidite) : d_pointSolidite{pointSolidite}
{}

int Equipement::pointSolidite() const
{ return d_pointSolidite; }

void Equipement::reparer(int pieceMonnaie)
{
    d_pointSolidite += pieceMonnaie;
}
