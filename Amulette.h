#ifndef AMULETTE_H
#define AMULETTE_H

#include "ObjetRamassable.h"
#include "Aventurier.h"
#include "Position.h"


class Amulette : public ObjetRamassable
{
    public:
        Amulette(const Position& position);
        void ramasser(Aventurier& aventurier) override;

    private:
};

#endif // AMULETTE_H
