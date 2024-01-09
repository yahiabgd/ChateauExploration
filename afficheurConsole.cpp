#include <iomanip>

#include "afficheurConsole.h"
#include "Terrain.h"

afficheurJeuConsole::~afficheurJeuConsole()
{

}

int afficheurJeuConsole::afficherMenu(const std::vector<std::string>& menu) const
{
    system("cls");
    int choix{0};
    std::cout<<std::setw(8)<<"MENU\n";
    for(size_t i = 0 ; i<menu.size() ; ++i)
        std::cout<<i<<")"<<menu[i]<<"\n";
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

