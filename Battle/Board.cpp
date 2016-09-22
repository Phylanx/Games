#include "Board.h"

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

void Board::printAt(u_int row, u_int col, bool fogOfWar)
{
    if(row >= _rows || col >= _cols) { return; }
    if(!fogOfWar){ //display all ships by id
        std::cout << _board[row][col].first;
    }else if(_board[row][col].second){ //if hidden
        std::cout << '~';
    }else if(_board[row][col].first == 0){//if not a ship
        std::cout << 'M';
    }else if(_fleet[_board[row][col].first - 1]._health > 0){//not sunk yet...
        std::cout << 'H';
    }else{//you sunk my battleship!
        std::cout << 'S';
    }
}

void Board::printRow(u_int row, bool fogOfWar)
{
    const int w = 2;
    if(_cols < 1) return;
    printAt(row, 0, fogOfWar);
    for(u_int i = 1; i < _cols; ++i){
        std::cout << std::setw(w) << ' ';
        printAt(row, i, fogOfWar);
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

//returns H(hit), M(miss), S(sunk), or I(invalid range)
char Board::fire(u_int row, u_int col)
{
    if(row < _rows && col < _cols && _board[row][col].second){
        _board[row][col].second = false;
        u_int shipID = _board[row][col].first;
        if(shipID == 0){
            return 'M';
        }else{
            if(--_fleet[shipID - 1]._health == 0){
                return 'S';
            }else{
                return 'H';
            }
        }

    }
    return 'I';
}

void Board::getFleetInfo()
{
    std::cout << "\n\n" <<
                 "ID\t" <<
                 "Health\t" <<
                 "Size\t" <<
                 "Row/Col\t  " <<
                 "Vertical\n" <<
                 std::string(40, '-') + '\n';
    for(u_int i = 0; i < _fleet.size(); ++i){
        Ship* ship = &_fleet[i];
        std::cout << ship->_id << '\t' <<
                     ship->_health << '\t' <<
                     ship->_size << '\t' <<
                     ship->_beginRow << ',' << ship->_beginCol << "\t  ";
                     std::string vert = ship->_isVertical ? "Yes\n" : "No\n";
        std::cout << vert;
    }
}

bool Board::inRange(u_int row, u_int col){ return row < _rows && col < _cols; }

bool Board::shipInRange(u_int row, u_int col, u_int size, bool vertical)
{
    if(vertical && col < _cols && row + size - 1 < _rows){
        return true;
    }else if(!vertical && col + size - 1 < _cols && row < _rows){
        return true;
    }
    return false;
}

void Board::setShip(u_int row, u_int col, u_int size, bool vertical)
{
    if(vertical){
        for(u_int i = 0; i < size; ++i){
            _board[row+i][col].first = id_unique;
        }
    }else{
        for(u_int i = 0; i < size; ++i){
            _board[row][col+i].first = id_unique;
        }
    }
    _fleet.push_back(Ship(id_unique, size, row, col, vertical));
    ++id_unique;
}

bool Board::noShipOverlap(u_int row, u_int col, u_int size, bool vertical)
{
    if( !shipInRange(row, col, size, vertical) ) return false;
    if(vertical){
        for(u_int i = 0; i < size; ++i){
            if(_board[row+i][col].first > 0){ return false; }
        }
    }else{
        for(u_int i = 0; i < size; ++i){
            if(_board[row][col+i].first > 0){ return false; }
        }
    }
    return true;
}

bool Board::addShip(u_int row, u_int col, u_int size, bool vertical)
{
    if( noShipOverlap(row, col, size, vertical) ) {
        setShip(row, col, size, vertical);
        return true;
    }
    return false;
}
