#include "Board.h"

Board::Board(u_int row, u_int col):id_unique(0), _rows(row), _cols(col)
{
    _board = new u_int*[_rows];
    for(u_int i = 0; i < _rows; ++i){
        _board[i] = new u_int[_cols];
        for(u_int k = 0; k < _cols; ++k){
            _board[i][k] = 0;
        }
    }
}

Board::~Board()
{
    for(u_int i = 0; i < _rows; ++i){
        delete[] _board[i];
    }
    delete[] _board;
}

void Board::printRow(u_int row)
{
    if(_cols < 1) return;
    std::cout << _board[row][0];
    for(u_int i = 1; i < _cols; ++i){
        std::cout << ' ' << _board[row][i];
    }
}

void Board::printAll()
{
    if(_rows < 1) return;
    printRow(0);
    for(u_int i = 1; i < _rows; ++i){
        std::cout << '\n';
        printRow(i);
    }
}

bool Board::addShip(u_int row, u_int col, u_int size, bool vert){
    if(vert){
        if(row + size <= _rows &&
                        col < _cols){
            _fleet.push_back(Ship::Ship(id_unique++, size, row, col));
            for(u_int i = 0; i < size; ++i){
                //add values to _board
            }
            return true;
        }
    }else{
        if(col + size <= _cols &&
                        row < _rows){
            _fleet.push_back(Ship::Ship(id_unique++, size, row, col, false));
            for(u_int i = 0; i < size; ++i){
                //add values to _board
            }
            return true;
        }
    }
    return false;
}
