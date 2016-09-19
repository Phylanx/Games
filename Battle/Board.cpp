#include "Board.h"
#include <iomanip>

Board::Board(u_int row, u_int col):id_unique(1), _rows(row), _cols(col)
{
    //_board of pair<id, isHidden
    _board = new std::pair<u_int, bool>*[_rows];
    for(u_int i = 0; i < _rows; ++i){
        _board[i] = new std::pair<u_int, bool>[_cols];
        for(u_int k = 0; k < _cols; ++k){
            _board[i][k] = std::pair<u_int, bool>(0, true);
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

void Board::printRow(u_int row, bool fogOfWar)
{
    const int w = 2;
    if(_cols < 1) return;
    if(fogOfWar && _board[row][0].second){
        std::cout << '~';
    }else{
        std::cout << _board[row][0].first;
    }
    for(u_int i = 1; i < _cols; ++i){
        if(fogOfWar && _board[row][i].second){
            std::cout << std::setw(w) << '~';
        }else{
            std::cout << std::setw(w) << _board[row][i].first;
        }
    }
}

void Board::printAll(bool fogOfWar)
{
    std::cout << "\n\n";
    if(_rows < 1) return;
    printRow(0, fogOfWar);
    for(u_int i = 1; i < _rows; ++i){
        std::cout << "\n";
        printRow(i, fogOfWar);
    }
}

//return false if out of bounds or overlapping another ship
bool Board::addShip(u_int row, u_int col, u_int size, bool vert){
    if(vert){
        if(row + size <= _rows && col < _cols){
            //push a ship onto _fleet
            _fleet.push_back(Ship(id_unique, size, row, col, true));
            //check if there is a ship in the way
            for(u_int i = 0; i < size; ++i){
                if(_board[i + row][col].first != 0){
                    return false;
                }
            }
            for(u_int i = 0; i < size; ++i){
                //add id values to _board
                _board[i + row][col].first = id_unique;
            }
            ++id_unique;
            return true;
        }
    }else{
        if(col + size <= _cols && row < _rows){
            _fleet.push_back(Ship(id_unique, size, row, col, false));
            //check if there is a ship in the way
            for(u_int i = 0; i < size; ++i){
                if(_board[row][i + col].first != 0){
                    return false;
                }
            }
            for(u_int i = 0; i < size; ++i){
                //add values to _board
                _board[row][i + col].first = id_unique;
            }
            ++id_unique;
            return true;
        }
    }
    return false;
}
