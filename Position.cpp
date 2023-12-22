#include "Position.h"


Position::~Position()
{
    //dtor
}

Position::Position(): d_x{0}, d_y{0}
{

}

Position::Position(int x, int y):d_x{x},d_y{y}
{

}

void Position::deplacerEn(int x,int y){
    d_x=x;
    d_y=y;
}
void Position::deplacerDe(int x,int y){
    d_x+=x;
    d_y+=y;
}

 double Position::distance(Position p)const{
    return std::sqrt(std::pow(p.d_x - d_x , 2 ) + pow(p.d_y - d_y , 2 ) );
 }
int Position::x()const{
    return d_x;
}
int Position::y()const{
    return d_y;
}
