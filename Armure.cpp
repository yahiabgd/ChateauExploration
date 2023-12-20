#include "Armure.h"

Armure::Armure(int pointSolidite) : Equipement{pointSolidite}
{}

void Armure::reduireSolidite(int force)
{
    int nb = ((3/4) * force);
    d_pointSolidite -= nb;
    if (d_pointSolidite < 0)
            d_pointSolidite = 0;
}
