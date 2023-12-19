#include <iostream>
#include"Position.h"
using namespace std;

void testposition(){
    Position p{};
    Position p2{0,2};
    cout<<p2.distance(p); // affiche 2

}

int main()
{
    Position p{1,1};
    Position p2{2,2};

    cout << "Hello world!" << endl;

    return 0;
}
