#include <windows.h>
#include <iomanip>
#include <conio.h>

#include "AdventureGame.h"
#include "afficheur.h"
#include "Aventurier.h"
#include "TasDeMonnaie.h"
#include "Amulette.h"
#include "Cellule.h"
#include "MonstreAveugle.h"
#include "MonstreVoyant.h"
AdventureGame::AdventureGame()
    :d_aventurier{ Aventurier{20,100,Position{0,0},Armure{100},Epee{100},Bourse{0},false} }, d_monstres(),d_terrain{DEFAUT_TERRAIN}
{
}
AdventureGame::AdventureGame(const Aventurier& aventurier, const std::vector<std::shared_ptr<Monstre>>& monstres,
                             std::vector<std::shared_ptr<ObjetRamassable>>&objets,const std::string& fichierTerrain)
    :d_aventurier{ aventurier }, d_monstres(monstres), d_terrain{fichierTerrain},d_objets{objets},d_finjeu{false}
{

}
AdventureGame::AdventureGame(const Terrain& terrain)
        :d_monstres{}, d_terrain{terrain},d_objets{},d_aventurier{Position{0,0}},d_finjeu{false}
{
//    for(int i=0 ; i<monstres.size() ; ++i)
//        d_monstres.push_back(std::move(monstres[i]));
    //inisialiserMap();
}
AdventureGame::AdventureGame(const Aventurier& aventurier, const std::vector<std::shared_ptr<Monstre>>& monstres,
                             std::vector<std::shared_ptr<ObjetRamassable>>&objets, const Terrain& terrain)
    :d_aventurier{aventurier}, d_monstres(monstres), d_terrain{terrain},d_objets{objets},d_finjeu{false}
{
     inisialiserMap();
//    for(int i=0 ; i<monstres.size() ; ++i)
//        d_monstres.push_back(std::move(monstres[i]));
}

AdventureGame::~AdventureGame() {}

void AdventureGame::Initialiserlejeu()
{
    d_objets.clear();
    d_monstres.clear();
    d_finjeu=false;
    for(int y=0;y<d_terrain.lignes();y++)
    {
        for(int x = 0; x<d_terrain.colonnes();x++)
        {
            Cellule cellule= d_terrain.cellule(x,y);
            switch (cellule.contenu())
            {
                case Cellule::TypeCellule::JOUEUR:
                {
                    Aventurier av{Position{x, y}};
                    d_aventurier = av;
                    break;
                }
                case Cellule::TypeCellule::PIECE:
                {
                    d_objets.push_back(std::make_shared<TasDeMonnaie>(Position{x, y}, 3));
                    break;
                }
                case Cellule::TypeCellule::AMULETTE:
                {
                    d_objets.push_back(std::make_shared<Amulette>(Position{x, y}));
                    break;
                }
                case Cellule::TypeCellule::MONSTRE:
                {
                    d_monstres.push_back(std::make_shared<MonstreAveugle>(10, 100, Position{x, y}, 10));
                    break;
                }
                case Cellule::TypeCellule::SMONSTRE:
                {
                    d_monstres.push_back(std::make_shared<MonstreVoyant>(25, 100, Position{x, y}, 10));
                    break;
                }
                default:
                    break;
            }
        }
    }
}

void AdventureGame::inisialiserMap()
{

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
    //Mise � jour du terrain
    d_terrain.miseajourcellule(d_aventurier.position().x(),d_aventurier.position().y(),d_aventurier.estSur());
    d_terrain.miseajourcellule(position.x(),position.y(),Cellule::TypeCellule::JOUEUR);
    //Mise � jour la position de l'objet aventurier
    d_aventurier.deplacer(position);
}
char AdventureGame::InputLettre()
{
    char lettre;
    const std::string lettresvalide = "zqdsaewc";

    do {
        lettre = std::tolower(_getch());
    } while (lettresvalide.find(lettre) == std::string::npos);

    return lettre;
}

void AdventureGame::ActeAventurier()
{
        Direction d;
        Position New = d_aventurier.position();
        switch(InputLettre())
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
        default:
            break;

        }
        Cellule nouvelleCellule{d_terrain.cellule(New.x(),New.y())};
        Cellule::TypeCellule typenouvelleCellule =nouvelleCellule.contenu();
        if(typenouvelleCellule != Cellule::TypeCellule::MUR && typenouvelleCellule != Cellule::TypeCellule::HORS )
        {
            if (typenouvelleCellule == Cellule::TypeCellule::MONSTRE || typenouvelleCellule == Cellule::TypeCellule::SMONSTRE)
            {

            }
            else
            {

                if (typenouvelleCellule == Cellule::TypeCellule::PIECE || typenouvelleCellule == Cellule::TypeCellule::AMULETTE)
                    {
                        int idxObj = getObjetIndiceParPosition(New);
                        d_objets[idxObj]->ramasser(d_aventurier);
                        typenouvelleCellule = Cellule::TypeCellule::VIDE;
                    }

                if(typenouvelleCellule == Cellule::TypeCellule::SORTIE)
                    {
                        if(d_aventurier.amulette())
                            d_finjeu = true;
                    }
                else//case vide
                    {
                    }
            DeplacerAventurier(New);
            d_aventurier.modifieEstSur(typenouvelleCellule);
            }

        }

}
void AdventureGame::ActeMonstre()
{
    for(auto& m : d_monstres)
    {
        m->deplacervers(d_aventurier,d_terrain);
    }
}
void AdventureGame::commencerJeu(const AfficheurJeu& afficheur)
{

    if(finJeu())
    {
        d_terrain=DEFAUT_TERRAIN;
    }

    Initialiserlejeu();
    while(!finJeu() )

    {
        afficheur.AffciherTitre();
        afficheur.AffciherInfoAventurier(d_aventurier);
        afficheur.AffciherTerrain(d_terrain);
        for(auto& m : d_monstres)
        {
            if(d_aventurier.position().distance(m->position())<=sqrt(2)){
                afficheur.AffciherInfoMonstre(m);
            }
        }

            //Acte d'aventurier
        ActeAventurier();


            //Acte des monstres
        ActeMonstre();

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
    std::vector<string> menu = {"Changer contenu","Creer Terrain","Importer un nouveau terrain", "Retoure"};
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
            case 2 :
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
        case 3 :
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
void AdventureGame::commencer(const AfficheurJeu& afficheur)
{
    std::vector<string> menu = {"Configurer le terrain","Commencer le jeu","Info de jeu", "Quitter"};
    int choix=afficheur.AfficherMenu(menu);
    while( choix != menu.size())
    {
        switch(choix)
        {
        case 1 :
            ConfigurerTerrain(afficheur);
            break;
        case 2 :
            commencerJeu(afficheur);
            break;
        case 3 :
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
    if(!d_aventurier.estVivant())
        return true;
    return d_finjeu;
}
