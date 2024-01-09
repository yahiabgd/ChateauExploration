#include "Armure.h"

Armure::Armure(int pointSolidite) : Equipement{pointSolidite}
{}

void Armure::reduireSolidite(int force)
{
    d_pointSolidite -= force;
}
