#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board b(8,10);
    b.printAll();
    b.addShip(2,6,4);
    b.addShip(3,1,4,0);
    b.printAll(true);

    cout<<'\n';
    return 0;
}

