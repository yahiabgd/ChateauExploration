#include <iostream>
#include"Position.h"
#include "Terrain.h"
using namespace std;

void testposition(){
    Position p{};
    Position p2{0,2};
    cout<<p2.distance(p); // affiche 2

}
void testterrain()
{
    Terrain t{20,10};
    t.miseajourcellule(5,5,Cellule::TypeCellule::JOUEUR);
    t.changenbcolonnes(6);
    t.changenblignes(6);
    t.afficher();
}
int main()
{
    Position p{1,1};
    Position p2{2,2};
    cout << "Hello world!" << endl;
    return 0;
}
