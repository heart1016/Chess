#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "Stone.h"
class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);

    Stone _s[32];

    int _r;

    //返回象棋棋盘行列对应的像素坐标
    QPoint center(int row, int col);
    QPoint center(int id);
    void drawStone(QPainter& painter, int id);

    virtual void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // BOARD_H
