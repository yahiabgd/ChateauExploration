#include "Epee.h"

Epee::Epee(int pointSolidite) : Equipement{pointSolidite}
{}

void Epee::reduireSolidite(int force)
{
    d_pointSolidite -= 1;
}
