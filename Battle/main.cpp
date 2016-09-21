#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

int main()
{
    srand(5);
    Board b(10,20);
    while( b.getFleet().size() < 13 ){
        bool vert = rand() % 2;
        u_int shipSz = rand() % 7 + 2;
        b.addShip( rand() % b.getRows(), rand() % b.getCols(), shipSz, vert );
    }

    b.printAll(false);
    b.getFleetInfo();
    cout<<'\n';
    return 0;
}

