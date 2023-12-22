#include "Bourse.h"

Bourse::Bourse(int pieceMonnaie) : d_pieceMonnaie{pieceMonnaie}
{}

int Bourse::pieceMonnaie() const
{ return d_pieceMonnaie; }

void Bourse::ajouter(int Monnaie)
{
    d_pieceMonnaie += Monnaie;
}

void Bourse::enlever(int Monnaie)
{
    d_pieceMonnaie -= Monnaie;
    if (d_pieceMonnaie < 0)
        d_pieceMonnaie = 0;
}
