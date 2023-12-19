#include "MonstreVoyant.h"

MonstreVoyant::MonstreVoyant()
{
    //ctor
}

MonstreVoyant::~MonstreVoyant()
{
    //dtor
}


void MonstreVoyant::deplacervers(const Aventurier& aventurier){
    if(aventurier.d_position.distance(d_position)<=8){
        // il faut savoir la direction
        //puis on utilise la fonction +deplacement(direction : ) : void
    }
}
