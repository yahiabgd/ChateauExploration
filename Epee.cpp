#include "Epee.h"

Epee::Epee(int pointSolidite) : Equipement{pointSolidite}
{}

void Epee::reduireSolidite(int force)
{
    if(d_pointSolidite > 0)
        d_pointSolidite -= force;
}
