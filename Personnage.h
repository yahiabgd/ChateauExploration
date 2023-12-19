#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include"Position.h"

class Personnage
{
    public:

        Personnage();
        virtual ~Personnage();
        void deplacement(char direction);
        virtual void recoitAttaque(int degats);
        bool estVivant();
        Position position();

    protected:
        int d_pointForce;
        Position d_position;
        int d_pointVie;

};

#endif // PERSONNAGE_H
