#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "Personnage.h"
#include "Bourse.h"
#include "Epee.h"
#include "Armure.h"

class Monstre;

class Aventurier : public Personnage
{
    public:
        Aventurier(const Armure& armure, const Epee& epee, const Bourse& bourse, bool amulette);

    private:
        Armure d_armure;
        Epee d_epee;
        Bourse d_bourse;
        bool d_amulette;

};

#endif // AVENTURIER_H
