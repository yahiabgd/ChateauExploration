#include <windows.h>
#include <iomanip>

#include "AdventureGame.h"
#include "afficheur.h"
#include "Aventurier.h"

AdventureGame::AdventureGame()
{
    //ctor
}
AdventureGame::~AdventureGame() {}


void AdventureGame::commencerJeu(const afficheurJeu& afficheur)
{

}
AdventureGame::~AdventureGame()
{
    while( finJeu())
    {
        /* Manque code aventurier
        char c;
        std::cin>>c;

        */
        for(auto& m : d_monstres)
        {
            m->deplacervers(*d_aventurier,*d_terrain);
            m->attaque(*d_aventurier);
        }

    }
}
void AdventureGame::ModifierTerrain(const afficheurJeu& afficheu)
{

}
void AdventureGame::commencer(const afficheurJeu& afficheur)
{
    int choix=afficheur.afficherMenu();
    while( choix != 3)
    {
        switch(choix)
        {
        case 1 :
            ModifierTerrain(afficheur);
            break;
        case 2 :
            commencerJeu(afficheur);
        }
    }
}


bool AdventureGame::finJeu() const
{
    //l'aventurier a pris l'amulette et passe par la sortie
    if(!d_aventurier->estVivant()) return true;
    else
    {
        int i=0;
        while(i<d_monstres.size() && !d_monstres[i]->estVivant())
            ++i;
        return i == d_monstres.size();
    }
}

