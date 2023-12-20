#ifndef ARMURE_H
#define ARMURE_H
#include "Equipement.h"


class Armure : public Equipement
{
    public:
        Armure(int pointSolidite);
        void reduireSolidite(int force) override;

};

#endif // ARMURE_H
