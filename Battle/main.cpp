#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board b(7,4);
//    b.printRow(3);
    b.printAll();

    cout<<'\n';
    return 0;
}
