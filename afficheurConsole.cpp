#include <iomanip>
#include <conio.h>

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
    for(int y =0; y< t.lignes() ; y++)
    {
        for(int x=0; x<t.colonnes(); x++)
            std::cout << static_cast<char>(t.cellule(x,y));
        std::cout << std::endl;
    }
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
    AttendAppuisSurBoutton('q');
}
void AfficheurJeuConsole::PrintError(const std::string& str) const
{
    std::cout<<"Erreur : "<<str<<std::endl;
    AttendAppuisSurBoutton('q');
}

void AfficheurJeuConsole::AttendAppuisSurBoutton(const char c) const
{
    std::cout<<c<<" : retoure";
    while(_getch() != c)
    {
    }
}

