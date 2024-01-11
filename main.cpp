#include <iostream>
#include <conio.h>

#include"Position.h"
#include "Terrain.h"
#include "AdventureGame.h"
#include "afficheurConsole.h"
#include"MonstreVoyant.h"
#include "MonstreAveugle.h"
using namespace std;

void testposition()
{
    Position p{};
    Position p2{0,2};
    cout<<p2.distance(p); // affiche 2

}

void testterrain()
{
    try
    {
        Terrain t{"testmap.txt"};
        // MonstreVoyant m;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testConstructorAG()
{
    Aventurier av(100,100,Position{10,10},Armure{20},Epee{15},Bourse{0},false);
    std::vector<std::unique_ptr<Monstre>> monstres;
    for(int i=0 ; i<3 ; ++i)
        monstres.push_back(make_unique<MonstreVoyant>(10,100,Position{10,5},10) );
    Terrain t{"testmap.txt"};
    AdventureGame ad{av,std::move(monstres),t};
}

void testAdventureGame()
{
    Aventurier av(100,100,Position{15,2 },Armure{20},Epee{15},Bourse{0},false);
    std::vector<std::unique_ptr<Monstre>> monstres;
    for(int i=0 ; i<1 ; ++i)
        monstres.push_back(make_unique<MonstreAveugle>(10,100,Position{12,2},10));
    Terrain t{"testmap.txt"};
    AdventureGame ad{av,std::move(monstres),t};
    AfficheurJeuConsole aff;
    ad.commencer(aff);
}

void test_getch()
{
    while(char choix = _getch())
    {
        switch(choix)
        {
        case 'z':
            cout<<'z';
            break;
        case 'q':
            cout<<'q';
            break;
        default:
            cout<<"kb";
            break;
        }
    }
}
void AffciherTerrain(const Terrain& t)
{

    for(int y =0; y< t.lignes() ; y++)
    {
        for(int x=0; x<t.colonnes(); x++)
            std::cout << static_cast<char>(t.cellule(x,y));
        std::cout << std::endl;
    }
}
void testmonstreAveugle(){
    Aventurier av(100,100,Position{16,2 },Armure{20},Epee{15},Bourse{0},false);
    Terrain t{"testmap.txt"};
    MonstreAveugle m{10,100,Position{10,2},10};

    for(int i = 0 ; i<4;i++){
        m.deplacervers(av,t);
        std::cout<<std::endl;
        AffciherTerrain(t);
    }
}
void testMonstreVoyant(){
    Aventurier av(100,100,Position{16,2 },Armure{20},Epee{15},Bourse{0},false);
    Terrain t{"testmap.txt"};
    MonstreVoyant m{10,100,Position{10,2},10};
    for(int i = 0 ; i<4;i++){
        m.deplacervers(av,t);
        std::cout<<std::endl;
        AffciherTerrain(t);
    }


}
int main()
{
//    testterrain();
//testAdventureGame();
    testmonstreAveugle();
    //testMonstreVoyant();
//    test_getch();
    return 0;
}
