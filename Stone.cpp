#include "Stone.h"
#include <QDebug>
#include "define.h"
Stone::Stone()
{

}

Stone::~Stone()
{

}

QString Stone::name()
{
    switch(this->_type)
    {
    case R_CAR:
        return "车";
    case B_CAR:
        return "車";
    case R_HORSE:
        return "马";
    case B_HORSE:
        return "馬";
    case B_CANON:
    case R_CANON:
        return "炮";
    case B_PAWN:
        return "兵";
    case R_PAWN:
        return "卒";
    case R_KING:
        return "将";
    case B_KING:
        return "帅";
    case R_BISHOP:
        return "士";
    case B_BISHOP:
        return "仕";
    case R_ELEPHANT:
        return "象";
    case B_ELEPHANT:
        return "相";
    }
    return "错误";
}

void Stone::init(int id)
{
    struct {
        int row, col;
        int type;
    } pos[32] = {
    {0, 0, B_CAR},
    {0, 1, B_HORSE},
    {0, 2, B_ELEPHANT},
    {0, 3, B_BISHOP},
    {0, 4, B_KING},
    {0, 5, B_BISHOP},
    {0, 6, B_ELEPHANT},
    {0, 7, B_HORSE},
    {0, 8, B_CAR},
    {2, 1, B_CANON},
    {2, 7, B_CANON},
    {3, 0, B_PAWN},
    {3, 2, B_PAWN},
    {3, 4, B_PAWN},
    {3, 6, B_PAWN},
    {3, 8, B_PAWN},

    {9, 0, R_CAR},
    {9, 1, R_HORSE},
    {9, 2, R_ELEPHANT},
    {9, 3, R_BISHOP},
    {9, 4, R_KING},
    {9, 5, R_BISHOP},
    {9, 6, R_ELEPHANT},
    {9, 7, R_HORSE},
    {9, 8, R_CAR},
    {7, 1, R_CANON},
    {7, 7, R_CANON},
    {6, 0, R_PAWN},
    {6, 2, R_PAWN},
    {6, 4, R_PAWN},
    {6, 6, R_PAWN},
    {6, 8, R_PAWN},
};

    if(id < 32)
    {
        this->_col = pos[id].col;
        this->_row = pos[id].row;
        this->_type = pos[id].type;
    }
    else
    {
        this->_col = 8-pos[id-32].col;
        this->_row = 9-pos[id-32].row;
        this->_type = pos[id-32].type;
    }

    this->_dead = false;
    this->_red = id<16;
}

void Stone::rotate()
{
    this->_col = 8-this->_col;
    this->_row = 9-this->_row;
}
