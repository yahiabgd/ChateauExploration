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
    try
    {
    Terrain t{"testmap.txt"};
    t.afficher();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
int main()
{
    Position p{1,1};
    Position p2{2,2};
    testterrain();
    return 0;
}
