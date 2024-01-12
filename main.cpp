#include <iostream>
#include <conio.h>

#include"Position.h"
#include "Terrain.h"
#include "AdventureGame.h"
#include "ObjetRamassable.h"
#include "afficheurConsole.h"
#include "Amulette.h"
#include "MonstreVoyant.h"
#include "MonstreAveugle.h"
#include "TasDeMonnaie.h"
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


//void testConstructorAG()
//{
//    Aventurier av(100,100,Position{10,10},Armure{20},Epee{15},Bourse{0},false);
//    std::vector<Monstre> monstres;
//    for(int i=0 ; i<3 ; ++i)
//        monstres.push_back( MonstreAveugle(10,100,Position{10,5},10) );
//    Terrain t{"testmap.txt"};
//    AdventureGame ad{av,monstres,t};
//}

void testAdventureGame()
{
    Aventurier av(100,100,Position{18,3},Armure{20},Epee{15},Bourse{10},false);
    std::vector<std::shared_ptr<Monstre>> monstres;
    std::vector<std::shared_ptr<ObjetRamassable>> objets;

    for(int i=0 ; i<1 ; ++i)
        monstres.push_back(make_shared<MonstreAveugle>(10,100,Position{10,2},10));
    objets.push_back(make_shared<Amulette>(Position{12,2}));
    objets.push_back(make_shared<TasDeMonnaie>(Position{20,2},4));
    Terrain t{"testmap.txt"};

    Amulette amulette{{16,1}};
    AdventureGame ad{av,monstres,objets,t};
    AfficheurJeuConsole aff;
    ad.commencer(aff);
}
void testAdventureGame2()
{
    Terrain t{"impossible.txt"};
    AdventureGame ad{t};
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
    testAdventureGame2();
    //testType();
//    test_getch();
    return 0;
}
