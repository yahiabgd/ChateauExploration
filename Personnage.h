#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include"Position.h"

class Personnage
{
    public:

        Personnage(int pointForce, int pointVie, Position position);
        virtual ~Personnage();
        int pointForce() const;
        int pointVie() const;
        void deplacement(char direction);
        virtual void recoitAttaque(int degats) = 0;
        bool estVivant() const;
        Position position()const;

    protected:
        int d_pointForce;
        Position d_position;
        int d_pointVie;

};

#endif // PERSONNAGE_H
