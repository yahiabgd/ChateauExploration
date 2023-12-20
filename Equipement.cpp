#include "Equipement.h"

Equipement::Equipement(int pointSolidite) : d_pointSolidite{pointSolidite}
{}

int Equipement::pointSolide() const
{ return d_pointSolidite; }

void Equipement::reparer(int pieceMonnaie)
{
    d_pointSolidite += pieceMonnaie;
}
