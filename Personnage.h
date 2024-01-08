#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include"Position.h"

class Personnage
{
    public:

        Personnage(int pointForce, int pointVie, Position position);
        virtual ~Personnage();
        void deplacement(char direction);
        virtual void recoitAttaque(int degats);
        bool estVivant()const;
        Position position()const;

    protected:
        int d_pointForce;
        int d_pointVie;
        Position d_position;

};

#endif // PERSONNAGE_H
