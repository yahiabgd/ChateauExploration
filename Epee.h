#ifndef EPEE_H
#define EPEE_H
#include "Equipement.h"


class Epee : public Equipement
{
    public:
        Epee(int pointSolidite);
        void reduireSolidite(int force) override;
};

#endif // EPEE_H
