#include <iostream>
#include <conio.h>

#include"Position.h"
#include "Terrain.h"
#include "AdventureGame.h"
#include "afficheurConsole.h"
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
    std::vector<Monstre> monstres;
    for(int i=0 ; i<3 ; ++i)
        monstres.push_back( MonstreAveugle(10,100,Position{10,5},10) );
    Terrain t{"testmap.txt"};
    AdventureGame ad{av,monstres,t};
}

void testAdventureGame()
{
    Aventurier av(100,100,Position{10,10},Armure{20},Epee{15},Bourse{0},false);
    std::vector<Monstre> monstres;
    for(int i=0 ; i<3 ; ++i)
        monstres.push_back(MonstreAveugle(10,100,Position{10,5},10));
    Terrain t{"testmap.txt"};
    AdventureGame ad{av,monstres,t};
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

int main()
{
//    testterrain();
    testAdventureGame();
//    test_getch();
    return 0;
}
