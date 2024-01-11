#include "Amulette.h"

Amulette::Amulette(const Position& position) : ObjetRamassable{position}
{}

void Amulette::ramasser(Aventurier& aventurier){
    aventurier.RamasseAmulette();
}
string Amulette::Type()const{
    return "AMULETTE";
}
