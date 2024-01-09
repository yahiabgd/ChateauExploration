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
void AdventureGame::ModifierTerrain(const afficheurJeu& afficheur)
{
    std::vector<string> menu ={"Modifier terrain","test","test"};
    int choix = afficheur.afficherMenu(menu);

}
void AdventureGame::commencer(const afficheurJeu& afficheur)
{
    std::vector<string> menu ={"Modifier terrain","Commencer le jeu","Quitter"};

    while( int choix=afficheur.afficherMenu(menu))
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
        size_t i=0;
        while(i<d_monstres.size() && !d_monstres[i]->estVivant())
            ++i;
        return i == d_monstres.size();
    }
}

