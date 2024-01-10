#ifndef OBJETRAMASSABLE_H
#define OBJETRAMASSABLE_H

#include "Position.h"
#include "Aventurier.h"

class ObjetRamassable
{
    public:
        ObjetRamassable(const Position& position);
        virtual ~ObjetRamassable();
        Position position() const;
        virtual void ramasser(Aventurier& venturier) = 0;

    private:
        Position d_position;
};

#endif // OBJETRAMASSABLE_H
