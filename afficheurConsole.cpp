#include <iomanip>
#include <conio.h>

#include "afficheurConsole.h"
#include"Aventurier.h"
#include"Monstre.h"
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
    void AfficheurJeuConsole::AffciherTitre() const{
        system("cls");
        std::cout<<"\t\t\t  ==================================================================================\n";
        std::cout<<"\t\t\t  =                 ------Exploration de ruines de chateau------                   =\n";
        std::cout<<"\t\t\t  ==================================================================================\n";
        //std::cout<<"\t\t\t ";
    }

    void AfficheurJeuConsole::AffciherInfoAventurier(const Aventurier& aventurier) const {
        std::cout<<"\t\t\t\t\t================ Information Aventurier ================\n";
        std::cout<<"\t\t\t\t\t=            Point de vie : " << aventurier.pointVie()<<"\n";
        std::cout<<"\t\t\t\t\t=            Point de force : " <<aventurier.pointForce()<<"        \n";
        std::cout<<"\t\t\t\t\t=            Armure : " << aventurier.armure().pointSolidite()<<"         Epee : "<< aventurier.epee().pointSolidite()<<"\n";
        std::cout<<"\t\t\t\t\t=            Amulette ramasser : " <<aventurier.amulette() <<"\n";
        std::cout<<"\t\t\t\t\t=            Bourse: " <<aventurier.pieces() <<"\n";
        std::cout<<"\t\t\t\t\t=========================================================\n";
        /*std::cout<<"Position Player : " <<aventurier.position().x() << aventurier.position().y() <<"\n"; */

    }
void AfficheurJeuConsole::AfficherInstruction() const{
    std::cout<<"***********************************************************\n";
    std::cout<<"|      Pour reparer vos equipements, cliquez sur R        |\n";
    std::cout<<"***********************************************************\n";
}

void AfficheurJeuConsole::AffciherInfoMonstre(const std::shared_ptr<Monstre>monstre) const {
    std::cout<<"\t\t\t\t\t================ Information Monstre ================\n";
    std::cout<<"\t\t\t\t\t            Point de vie : " << monstre->pointVie()<<"\n";
    std::cout<<"\t\t\t\t\t            Point de force : " <<monstre->pointForce()<< "\n";
    std::cout<<"\t\t\t\t\t            habilete : " << monstre->habilete() <<" % \n";

}

