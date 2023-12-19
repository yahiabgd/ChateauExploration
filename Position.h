#ifndef POSITION_H
#define POSITION_H
#include<cmath>


class Position
{
    public:
        virtual ~Position();
        Position();
        Position(int x, int y);
        void deplacerEn(int x,int y);
        void deplacerDe(int x,int y);
        double distance(Position p)const;

    private:
        int d_x,d_y;
};

#endif // POSITION_H
