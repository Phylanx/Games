#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <utility>
#include <iostream>
#include <iomanip>

#define u_int unsigned int

struct Ship{
    Ship(u_int id, u_int size, u_int row, u_int col, bool vert = true)
        :_id(id), _health(size), _size(size), _beginRow(row), _beginCol(col), _isVertical(vert) {}
    u_int _id, _health, _size, _beginRow, _beginCol;
    bool _isVertical;
};

class Board
{
    u_int id_unique; //id = ship index
    std::pair<u_int, bool>** _board;
    std::vector<Ship> _fleet;
    u_int _rows, _cols;

public:
    Board(u_int row, u_int col);
    ~Board();
    void printRow(u_int row, bool fogOfWar);
    void printAll(bool fogOfWar = true);
    bool addShip(u_int row, u_int col, u_int size, bool vert = true);
    char fire(u_int row, u_int col);
    u_int getRows(){ return _rows; }
    u_int getCols(){ return _cols; }
    std::vector<Ship>& getFleet(){ return _fleet; }
    void getFleetInfo();

};

#endif // BOARD_H
