#ifndef STONE_H
#define STONE_H

#include <QString>

class Stone
{
public:
    Stone();

    enum TYPE {JIANG, JU, PAO, MA, ZU, SHI, XIANG};

    int _row;
    int _col;
    int _id;
    bool _dead;
    bool _red;
    TYPE _type;

    void init(int id)
    { struct {
            int row, col;
            Stone::TYPE type;
        } pos[16] = {
        {0, 0, Stone::JU},
        {0, 1, Stone::MA},
        {0, 2, Stone::XIANG},
        {0, 3, Stone::SHI},
        {0, 4, Stone::JIANG},
        {0, 5, Stone::SHI},
        {0, 6, Stone::XIANG},
        {0, 7, Stone::MA},
        {0, 8, Stone::JU},

        {2, 1, Stone::PAO},
        {2, 7, Stone::PAO},
        {3, 0, Stone::ZU},
        {3, 2, Stone::ZU},
        {3, 4, Stone::ZU},
        {3, 6, Stone::ZU},
        {3, 8, Stone::ZU},
        };

       _id = id;
       _dead = false;
       _red = id<16;

       if (id < 16) {
           _row = pos[id].row;
           _col = pos[id].col;
           _type = pos[id].type;
       } else {
           _row = 9 - pos[id-16].row;
           _col = 8 - pos[id-16].col;
           _type =  pos[id-16].type;
       }
    }

    QString getText()
    {
        switch (this->_type) {
        case JIANG:
            return "将";
        case JU:
            return "車";
        case PAO:
            return "炮";
        case MA:
            return "馬";
        case ZU:
            return "卒";
        case SHI:
            return "士";
        case XIANG:
            return "象";
        }
        return "错误";
    }
};

#endif // STONE_H
