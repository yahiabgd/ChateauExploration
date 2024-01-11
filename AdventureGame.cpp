#include <windows.h>
#include <iomanip>
#include <conio.h>

#include "AdventureGame.h"
#include "afficheur.h"
#include "Aventurier.h"
#include "Cellule.h"


AdventureGame::AdventureGame()
    :d_aventurier{ Aventurier{20,100,Position{0,0},Armure{100},Epee{100},Bourse{0},false} }, d_monstres(),d_terrain{DEFAUT_TERRAIN}
{
}
AdventureGame::AdventureGame(const Aventurier& aventurier, const std::vector<std::shared_ptr<Monstre>>& monstres,
                             std::vector<std::shared_ptr<ObjetRamassable>>&objets,const std::string& fichierTerrain)
    :d_aventurier{ aventurier }, d_monstres(monstres), d_terrain{fichierTerrain},d_objets{objets}
{
    inisialiserMap();
}
AdventureGame::AdventureGame(const Aventurier& aventurier, const std::vector<std::shared_ptr<Monstre>>& monstres,
                             std::vector<std::shared_ptr<ObjetRamassable>>&objets, const Terrain& terrain)
    :d_aventurier{aventurier}, d_monstres(monstres), d_terrain{terrain},d_objets{objets}
{
     inisialiserMap();
//    for(int i=0 ; i<monstres.size() ; ++i)
//        d_monstres.push_back(std::move(monstres[i]));
}
AdventureGame::~AdventureGame() {}

void AdventureGame::inisialiserMap(){
    d_terrain.miseajourcellule(d_aventurier.position().x(),d_aventurier.position().y(),Cellule::TypeCellule::JOUEUR);
    for(const auto& monstre : d_monstres){
        d_terrain.miseajourcellule(monstre->position().x(),monstre->position().y(),Cellule::TypeCellule::MONSTRE);
    }
    for(const auto& objet : d_objets){
        if(objet->Type()=="AMULETTE")
            d_terrain.miseajourcellule(objet->position().x(),objet->position().y(),Cellule::TypeCellule::AMULETTE);
        if(objet->Type()=="PIECE"){
            d_terrain.miseajourcellule(objet->position().x(),objet->position().y(),Cellule::TypeCellule::PIECE);
        }
    }
}
int AdventureGame::getMonstreIndiceParPosition(const Position& position)
{
    int i=0;
    for (const auto& monstre : d_monstres){
        if(monstre->position().x() == position.x() && monstre->position().y() == position.y())
            break;
        i++;
    }
    return i;
}
int AdventureGame::getObjetIndiceParPosition(const Position& position)
{
    int i=0;
    for (const auto& objet : d_objets){
        if(objet->position().x() == position.x() && objet->position().y() == position.y())
            break;
        i++;
    }
    return i;

}
void AdventureGame::DeplacerAventurier(const Position& position)
{
    //Mise à jour du terrain
    d_terrain.miseajourcellule(d_aventurier.position().x(),d_aventurier.position().y(),Cellule::TypeCellule::VIDE);
    d_terrain.miseajourcellule(position.x(),position.y(),Cellule::TypeCellule::JOUEUR);
    //Mise à jour la position de l'objet aventurier
    d_aventurier.deplacer(position);
}
void AdventureGame::ActeAventurier()
{
     Direction d;
        Position New = d_aventurier.position();
        switch(std::tolower(_getch()))
        {
        case 'z' :
            New.deplacerDe(0,-1);
            break;
        case 'q' :
            New.deplacerDe(-1,0);
            break;
        case 'd' :
            New.deplacerDe(1,0);
            break;
        case 's' :
            New.deplacerDe(0,1);
            break;
        case 'a' :
            New.deplacerDe(-1,-1);
            break;
        case 'e' :
            New.deplacerDe(1,-1);
            break;
        case 'w' :
            New.deplacerDe(-1,1);
            break;
        case 'c' :
            New.deplacerDe(1,1);
            break;
        }
        Cellule nouvelleCellule{d_terrain.cellule(New.x(),New.y())};
        if(nouvelleCellule.contenu() != Cellule::TypeCellule::MUR && nouvelleCellule.contenu() != Cellule::TypeCellule::HORS )
        {
            if (nouvelleCellule.contenu() == Cellule::TypeCellule::MONSTRE || nouvelleCellule.contenu() == Cellule::TypeCellule::SMONSTRE)
            {

            }
            else
            {
                DeplacerAventurier(New);
                if (nouvelleCellule.contenu() == Cellule::TypeCellule::PIECE || nouvelleCellule.contenu() == Cellule::TypeCellule::AMULETTE)
                    {
                        int idxObj = getObjetIndiceParPosition(New);
                        d_objets[idxObj]->ramasser(d_aventurier);
                    }

                if (nouvelleCellule.contenu() == Cellule::TypeCellule::SORTIE)
                    {

                    }
                else//case vide
                    {
                    }
                }

        }

}
void AdventureGame::commencerJeu(const AfficheurJeu& afficheur)
{
    while(true)
    {
        afficheur.AffciherTitre();
        afficheur.AffciherTerrain(d_terrain);

        //Acte d'aventurier
        ActeAventurier();

        //Acte des monstres
        for(auto& m : d_monstres)
        {
            m->deplacervers(d_aventurier,d_terrain);


        }
    }
}

void AdventureGame::ChangerTerrain(const AfficheurJeu& afficheur)
{
    std::vector<string> menu = {"Creer Terrain","Importer un nouveau terrain","Retour"};
    int choix = afficheur.AfficherMenu(menu);
    while(choix != menu.size() )
    {
        switch(choix)
            {
            case 1 :
                {
                    try{
                //Creer Terrain
                Terrain tmp=d_terrain;
                int ligne = std::stoi(afficheur.Input("Entrer le nouveau nombre nombre de ligne : "));
                int colonne= std::stoi(afficheur.Input("Entrer le nouveau nombre nombre de colenne : "));
                tmp.changenbcolonnes(colonne);
                tmp.changenblignes(ligne);
                for(int x=0 ; x<ligne ; ++x)
                {
                    for(int y=0; y<colonne ; ++y)
                    {
        //            Cellule contenu= afficheur.Input("Entrer le nouveau contenu:");
    //                tmp.miseajourcellule(x,y,contenu));
                    }
                }
                if(tmp.estvalide())
                {
                    d_terrain=tmp;
//                    try
//                    {
                        d_terrain.sauvegarder("terrain.txt");

//                    }catch(const std::exception& e)
//                    {
//                        afficheur.PrintError(e.what());
//                    }
                }
                else
                    afficheur.PrintError("Terrain n'est pas valide");
                break;
                    }catch(const std::exception& e)
                {
                    afficheur.PrintError(e.what());
                }
            }
        case 2 :
            std::string fic;
            fic = afficheur.Input("Entrer le nom du fichier qui contient le terrain : ");
            try
            {
                d_terrain = Terrain{fic};

            }
            catch(const std::exception& e)
            {
                afficheur.PrintError(e.what());
            }
            break;
        }
        choix = afficheur.AfficherMenu(menu);

    }

}

void AdventureGame::ConfigurerTerrain(const AfficheurJeu& afficheur)
{
    std::vector<string> menu = {"Changer contenu", "Retoure"};
    int choix = afficheur.AfficherMenu(menu);
    while(choix != menu.size())
    {
        switch(choix)
        {
        case 1:
            {
                try
                {

                //changement de contenu
                int x= std::stoi(afficheur.Input("Entrer l'indice de ligne: "));
                int y= std::stoi(afficheur.Input("Entrer l'indice de colonne: "));
    //            Cellule contenu= afficheur.Input("Entrer le nouveau contenu:");
                Terrain tmp = d_terrain;
                if(tmp.positionValide(x,y))
                {
    //                tmp.miseajourcellule(x,y,contenu));
                }
                else{
                    afficheur.PrintError("Position non valide");
                }
                if(tmp.estvalide())
                    d_terrain = tmp;
                else{
                    afficheur.PrintError("Terrain n'est pas valide");
                }
                }catch(const std::exception& e)
                {
                    afficheur.PrintError(e.what());
                }
                break;
            }
        }
        choix = afficheur.AfficherMenu(menu);
    }
}
void AdventureGame::commencer(const AfficheurJeu& afficheur)
{
    std::vector<string> menu = {"Changer le terrain","Configurer le terrain","Commencer le jeu","Info de jeu", "Quitter"};
    int choix=afficheur.AfficherMenu(menu);
    while( choix != menu.size())
    {
        switch(choix)
        {
        case 1 :
            ChangerTerrain(afficheur);
            break;
        case 2:
            ConfigurerTerrain(afficheur);
            break;
        case 3 :
            commencerJeu(afficheur);
            break;
        case 4 :
            afficheur.Print("Infos : \nz: Haut, s: Bas, q:Gauche, d:Droite\n");
            break;
        default:
            break;

        }
        choix=afficheur.AfficherMenu(menu);
    }
}

bool AdventureGame::finJeu() const
{
    //l'aventurier a pris l'amulette et passe par la sortie
    if(!d_aventurier.estVivant()) return true;
    else
    {
        Position positionAventurier{d_aventurier.position()};
        if( d_aventurier.amulette() && d_terrain.cellule(positionAventurier.x(),positionAventurier.y()) )
        {
            return true;
        }
        return false;
    }
}
