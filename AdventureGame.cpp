#include <windows.h>
#include <iomanip>

#include "AdventureGame.h"
#include "afficheur.h"
#include "Aventurier.h"

std::string AdventureGame::DEFAUT_TERRAIN{"testmap.txt"};

AdventureGame::AdventureGame()
:d_aventurier{ std::make_unique<Aventurier>(20,100,Position{0,0},Armure{100},Epee{100},Bourse{0},false) }, d_monstres() , d_terrain{std::make_unique<Terrain>(DEFAUT_TERRAIN) }
{
}
AdventureGame::AdventureGame(const Aventurier& aventurier, const std::vector<Monstre>& monstres , const std::string& fichierTerrain)
:d_aventurier{ std::make_unique<Aventurier>(aventurier) }, d_monstres() , d_terrain{std::make_unique<Terrain>(fichierTerrain) }
{
    for(const auto& monstre : monstres)
        d_monstres.push_back(std::make_unique<Monstre>(monstre));
}
AdventureGame::AdventureGame(const Aventurier& aventurier, const std::vector<Monstre>& monstres , const Terrain& terrain)
:d_aventurier{ std::make_unique<Aventurier>(aventurier) }, d_monstres(/*monstres.size()*/) , d_terrain{std::make_unique<Terrain>(terrain) }
{}
AdventureGame::~AdventureGame() {}

void AdventureGame::commencerJeu(const AfficheurJeu& afficheur)
{
    while(!finJeu())
    {
        //Acte d'aventurier

        //Acte des monstres
        for(auto& m : d_monstres)
        {
            m->deplacervers(*d_aventurier,*d_terrain);
            m->attaque(*d_aventurier);
        }
    }
}
void AdventureGame::ModifierTerrain(const AfficheurJeu& afficheur)
{
    std::vector<string> menu ={"Modifier le terrain","Importer un nouveau terrain","Quitter"};
    int choix = afficheur.AfficherMenu(menu);
    while(choix != menu.size() )
    {
        switch(choix)
        {
        case 1 :
            //Modifier terrain cellule par cellule
            break;
        case 2 :
            std::string fic;
            fic = afficheur.Input("Entrer le nom du fichier qui contient le terrain : ");
            try
            {
                d_terrain = std::make_unique<Terrain>(fic);

            }catch(const std::exception& e)
            {
                afficheur.PrintError(e.what());
            }
            break;
        }
        choix = afficheur.AfficherMenu(menu);

    }

}
void AdventureGame::commencer(const AfficheurJeu& afficheur)
{
    std::vector<string> menu ={"Modifier le terrain","Voir le terrain" ,"Commencer le jeu", "Quitter"};
    int choix=afficheur.AfficherMenu(menu);
    while( choix != menu.size())
    {

        switch(choix)
        {
        case 1 :
            ModifierTerrain(afficheur);
            break;
        case 2:
            afficheur.AffciherTerrain(*d_terrain);
            break;
        case 3 :
            commencerJeu(afficheur);
            break;

        }
        choix=afficheur.AfficherMenu(menu);
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

