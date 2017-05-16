#ifndef STONE_H
#define STONE_H


class Stone
{
public:
    Stone();
    ~Stone();

    enum TYPE {JIANG, JU, PAO, MA, ZU, SHI, XIANG};

    int _row;
    int _col;
    int _id;
    bool _dead;
    bool _red;
    bool _type;
};

#endif // STONE_H
