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
AfficheurJeuConsole::AfficheurJeuConsole() : AfficheurJeu{}
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
char AfficheurJeuConsole::InputLettre(const std::string& str) const
{
    char lettre;
    const std::string lettresvalide = "zqdsaewcr";

    do {
        lettre = std::tolower(_getch());
    } while (lettresvalide.find(lettre) == std::string::npos);

    return lettre;
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
void AfficheurJeuConsole::AffciherTitre() const{
        system("cls");
        std::cout<<"\t\t\t\t\t   ***********************************************************\n";
        std::cout<<"\t\t\t\t\t   *              Exploration de ruines de chateau           *     \n";
        std::cout<<"\t\t\t\t\t   ***********************************************************\n";
    }

void AfficheurJeuConsole::AffciherInfoAventurier(const Aventurier& aventurier) const {
        std::cout<<"\t\t\t\t\t   ================ Information Aventurier ===================\n";
        std::cout<<"\t\t\t\t\t   |            Point de vie : " << aventurier.pointVie()<<"\t\t\t     |\n";
        std::cout<<"\t\t\t\t\t   |            Point de force : " <<aventurier.pointForce()<<"\t\t\t     |\n";
        std::cout<<"\t\t\t\t\t   |            Armure : " << aventurier.armure().pointSolidite()<<"         Epee : "<< aventurier.epee().pointSolidite()<<"\t\t     |\n";
        std::cout<<"\t\t\t\t\t   |            Amulette ramasser : " <<aventurier.amulette() <<"\t\t\t     |\n";
        std::cout<<"\t\t\t\t\t   |            Bourse: " <<aventurier.pieces() <<"\t\t\t\t     |\n";
        std::cout<<"\t\t\t\t\t   ===========================================================\n";
        /*std::cout<<"Position Player : " <<aventurier.position().x() << aventurier.position().y() <<"\n"; */

    }
    void AfficheurJeuConsole::AfficherInstruction() const{
    std::cout<<"\t\t\t\t\t   ***********************************************************\n";
    std::cout<<"\t\t\t\t\t   |      Pour reparer vos equipements, cliquez sur R        |\n";
    std::cout<<"\t\t\t\t\t   ***********************************************************\n";
}

void AfficheurJeuConsole::AffciherInfoMonstre(const std::shared_ptr<Monstre>monstre) const {
    std::cout<<"\t\t\t\t\t   =================== Information Monstre ==================\n";
    std::cout<<"\t\t\t\t\t   |            Point de vie : " << monstre->pointVie()<<"\t\t\t     |\n";
    std::cout<<"\t\t\t\t\t   |            Point de force : " <<monstre->pointForce()<< "\t\t\t     |\n";
    std::cout<<"\t\t\t\t\t   |            habilete : " << monstre->habilete() <<" \t\t\t\t     | \n";
    std::cout<<"\t\t\t\t\t   ===========================================================\n";
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

