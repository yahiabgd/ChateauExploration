#include <iomanip>
#include <conio.h>
#include <windows.h>

#include "afficheurConsole.h"
#include"Aventurier.h"
#include"Monstre.h"
#include "Terrain.h"
#include "Position.h"

AfficheurJeuConsole::~AfficheurJeuConsole()
{

}
void AfficheurJeuConsole::effacer() const
{
    system("cls");
}
int AfficheurJeuConsole::AfficherMenu(const std::vector<std::string>& menu) const
{
    effacer();
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
    std::cout<<c<<" : retoure\n";
    while(_getch() != c)
    {
    }
}
void AfficheurJeuConsole::AffciherTitre() const
{
    effacer();
    std::cout<<"        ------Exploration de ruines de chateau------          \n";
}

void AfficheurJeuConsole::AffciherInfoAventurier(const Aventurier& aventurier) const
{
    std::cout<<"=== Information Aventurier ===\n";
    std::cout<<"Point de vie : " << aventurier.pointVie()<<"\n";
    std::cout<<"Point de force : " <<aventurier.pointForce()<<"\n";
    std::cout<<"Armure : " << aventurier.armure().pointSolidite()<<"         Epee : "<< aventurier.epee().pointSolidite()<<"\n";
    std::cout<<"Amulette ramasser : " <<aventurier.amulette() <<"\n";
    std::cout<<"Bourse: " <<aventurier.pieces() <<"\n" <<"\n";
    /*std::cout<<"Position Player : " <<aventurier.position().x() << aventurier.position().y() <<"\n"; */

}

void AfficheurJeuConsole::AffciherInfoMonstre(const std::shared_ptr<Monstre>monstre) const
{
    std::cout<<"=== Information Monstre ===\n";
    std::cout<<"Point de vie : " << monstre->pointVie()<<"\n";
    std::cout<<"Point de force : " <<monstre->pointForce()<< "\n";
    std::cout<<"habilete : " << monstre->habilete() <<" % \n";

}
    Position AfficheurJeuConsole::getPositionCurseur() const
    {
        POINT positionPoint ;
        GetCursorPos(&positionPoint);
        Position res {positionPoint.x,positionPoint.y };
    }
    void AfficheurJeuConsole::setPositionCursor(const Position& p) const
    {
        HANDLE handle;
        handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coordinates;
        coordinates.X = p.x();
        coordinates.Y = p.y();
        handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(handle, coordinates);


    }

