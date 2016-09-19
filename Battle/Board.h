#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <utility>
#include <iostream>

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
    u_int** _board;
    std::vector<Ship> _fleet;
    u_int _rows, _cols;

public:
    Board(u_int row, u_int col);
    ~Board();
    void printRow(u_int row);
    void printAll();
    bool addShip(u_int row, u_int col, u_int size, bool vert = true);


};

#endif // BOARD_H
