#include <iomanip>

#include "afficheurConsole.h"
#include "Terrain.h"

AfficheurJeuConsole::~AfficheurJeuConsole()
{

}

int AfficheurJeuConsole::AfficherMenu(const std::vector<std::string>& menu) const
{
    system("cls");
    int choix{0};
    std::cout<<std::setw(10)<<"MENU\n";
    for(size_t i = 0 ; i<menu.size() ; ++i)
        std::cout<<i+1<<")"<<menu[i]<<"\n";
    std::cin>>choix;
    if(std::cin.good())
        return choix;
    else
        return menu.size();
}

void AfficheurJeuConsole::AffciherTerrain(const Terrain& t) const
{
    system("cls");
    Print("TERRAIN\n");
    for(int i =0; i< t.lignes() ; i++)
    {
        for(int j=0; j<t.colonnes(); j++)
            std::cout << static_cast<char>(t.cellule(i,j));
        std::cout << std::endl;
    }
    AttendAppuisSurBoutton('q');
}
std::string AfficheurJeuConsole::Input(const std::string& str ) const
{
    std::string res;
    std::cout<<str;
    std::cin>>res;
    return res;
}
void AfficheurJeuConsole::Print(const std::string& str) const
{
    std::cout<<str;
}
void AfficheurJeuConsole::PrintError(const std::string& str) const
{
    std::cout<<"Ereur : "<<str<<std::endl;
    Print("q : quitter");
    while(getchar() != 'q')
    {
    }
}

void AfficheurJeuConsole::AttendAppuisSurBoutton(const char c) const
{
    std::cout<<c<<" : quitter";
    while(getchar() != c)
    {
    }
}

