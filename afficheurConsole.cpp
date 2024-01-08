#include <iomanip>

#include "afficheurConsole.h"
#include "Terrain.h"

afficheurJeuConsole::~afficheurJeuConsole()
{

}

int afficheurJeuConsole::afficherMenu() const
{
    system("cls");
    int choix{0};
    std::cout<<std::setw(8)<<"MENU\n";
    std::cout<<"1)Modifier le terrain\n";
    std::cout<<"2)Commencer le jeu\n";
    std::cout<<"3)Quitter\n";
    std::cin>>choix;
    return choix;
}

void afficheurJeuConsole::affciherTerrain(const Terrain& t) const
{
    for(int i =0; i<t.lignes(); i++)
    {
        for(int j=0; j<t.colonnes(); j++)
            std::cout << static_cast<char>(t.cellule(i,j));
        std::cout << std::endl;
    }
}

