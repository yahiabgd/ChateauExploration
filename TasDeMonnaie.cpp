#include "TasDeMonnaie.h"

TasDeMonnaie::TasDeMonnaie(const Position& position, int nombrePiece) : ObjetRamassable{position}, d_nombrePiece{nombrePiece}
{}

int TasDeMonnaie::nombrePiece() const
{ return d_nombrePiece; }

void TasDeMonnaie::ramasser(Aventurier& aventurier) {

    aventurier.RamasseTasDePiece(nombrePiece());
}
string TasDeMonnaie::Type()const {
    return "PIECE";
}
