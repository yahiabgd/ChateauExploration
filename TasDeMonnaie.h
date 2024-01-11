#ifndef TASDEMONNAIE_H
#define TASDEMONNAIE_H

#include "Position.h"
#include "Aventurier.h"
#include "ObjetRamassable.h"

class TasDeMonnaie : public ObjetRamassable
{
    public:
        TasDeMonnaie(const Position& position, int nombrePiece);
        int nombrePiece() const;
        string Type()const override;
        void ramasser(Aventurier& aventurier) override;

    private:
        int d_nombrePiece;
};

#endif // TASDEMONNAIE_H
