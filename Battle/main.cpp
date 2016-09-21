#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

int main()
{
    cout<<false<<" = False\n";
    srand(5);
    Board b(10,20);
    b.addShip(0,0,5,true);
    char c = b.fire(0,0); cout << c << '\n';
    c = b.fire(1,0); cout << c << '\n';
    c = b.fire(2,0); cout << c << '\n';
    c = b.fire(3,0); cout << c << '\n';
    c = b.fire(5,0); cout << c << '\n';
    c = b.fire(4,0); cout << c << '\n';

    b.printAll(false);
    b.getFleetInfo();



    cout<<'\n';
    return 0;
}

