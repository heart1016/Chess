#include "Board.h"
#include <QPainter>
Board::Board(QWidget *parent) : QWidget(parent)
{

}

void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int d = 40;

    //画竖线
    for (int i = 1; i<=9; i++) {
        if (i == 1 || i == 9) {
            painter.drawLine(QPoint(i*d, d), QPoint(i*d, 10*d));
        } else {
            painter.drawLine(QPoint(i*d, d), QPoint(i*d, 5*d));
            painter.drawLine(QPoint(i*d, 6*d), QPoint(i*d, 10*d));
        }
    }

    //画横线
    for (int i = 1; i<=10; i++) {
        painter.drawLine(QPoint(d, i*d), QPoint(9*d, i*d));
    }

    QFont font;
    font.setPixelSize(18);
    painter.setFont(font);
    painter.drawText(QPoint(2*d+d/2-8, 6*d-d/2+8), "楚");
    painter.drawText(QPoint(3*d+d/2-8, 6*d-d/2+8), "河");
    painter.drawText(QPoint(6*d+d/2-8, 6*d-d/2+8), "漢");
    painter.drawText(QPoint(7*d+d/2-8, 6*d-d/2+8), "界");

    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);

    //边框粗线
    painter.drawLine(QPoint(d-5, d-5), QPoint(9*d+5, d-5));
    painter.drawLine(QPoint(d-5, 10*d+5), QPoint(9*d+5, 10*d+5));
    painter.drawLine(QPoint(d-5, d-5), QPoint(d-5, 10*d+5));
    painter.drawLine(QPoint(9*d+5, d-5), QPoint(9*d+5, 10*d+5));

    pen.setWidth(1);
    painter.setPen(pen);

    //设置九宫格
    painter.drawLine(QPoint(4*d, 1*d), QPoint(6*d, 3*d));
    painter.drawLine(QPoint(6*d, 1*d), QPoint(4*d, 3*d));
    painter.drawLine(QPoint(4*d, 8*d), QPoint(6*d, 10*d));
    painter.drawLine(QPoint(6*d, 8*d), QPoint(4*d, 10*d));

    //左上炮
    painter.drawLine(QPoint(2*d-2, 3*d-2), QPoint(2*d-10, 3*d-2));
    painter.drawLine(QPoint(2*d-2, 3*d-2), QPoint(2*d-2,  3*d-10));
    painter.drawLine(QPoint(2*d+2, 3*d-2), QPoint(2*d+10, 3*d-2));
    painter.drawLine(QPoint(2*d+2, 3*d-2), QPoint(2*d+2,  3*d-10));
    painter.drawLine(QPoint(2*d-2, 3*d+2), QPoint(2*d-10, 3*d+2));
    painter.drawLine(QPoint(2*d-2, 3*d+2), QPoint(2*d-2,  3*d+10));
    painter.drawLine(QPoint(2*d+2, 3*d+2), QPoint(2*d+10, 3*d+2));
    painter.drawLine(QPoint(2*d+2, 3*d+2), QPoint(2*d+2,  3*d+10));

    //右上炮
    painter.drawLine(QPoint(8*d-2, 3*d-2), QPoint(8*d-10, 3*d-2));
    painter.drawLine(QPoint(8*d-2, 3*d-2), QPoint(8*d-2,  3*d-10));
    painter.drawLine(QPoint(8*d+2, 3*d-2), QPoint(8*d+10, 3*d-2));
    painter.drawLine(QPoint(8*d+2, 3*d-2), QPoint(8*d+2,  3*d-10));
    painter.drawLine(QPoint(8*d-2, 3*d+2), QPoint(8*d-10, 3*d+2));
    painter.drawLine(QPoint(8*d-2, 3*d+2), QPoint(8*d-2,  3*d+10));
    painter.drawLine(QPoint(8*d+2, 3*d+2), QPoint(8*d+10, 3*d+2));
    painter.drawLine(QPoint(8*d+2, 3*d+2), QPoint(8*d+2,  3*d+10));

    //左下炮
    painter.drawLine(QPoint(2*d-2, 8*d-2), QPoint(2*d-10, 8*d-2));
    painter.drawLine(QPoint(2*d-2, 8*d-2), QPoint(2*d-2,  8*d-10));
    painter.drawLine(QPoint(2*d+2, 8*d-2), QPoint(2*d+10, 8*d-2));
    painter.drawLine(QPoint(2*d+2, 8*d-2), QPoint(2*d+2,  8*d-10));
    painter.drawLine(QPoint(2*d-2, 8*d+2), QPoint(2*d-10, 8*d+2));
    painter.drawLine(QPoint(2*d-2, 8*d+2), QPoint(2*d-2,  8*d+10));
    painter.drawLine(QPoint(2*d+2, 8*d+2), QPoint(2*d+10, 8*d+2));
    painter.drawLine(QPoint(2*d+2, 8*d+2), QPoint(2*d+2,  8*d+10));

    //右下炮
    painter.drawLine(QPoint(8*d-2, 8*d-2), QPoint(8*d-10, 8*d-2));
    painter.drawLine(QPoint(8*d-2, 8*d-2), QPoint(8*d-2,  8*d-10));
    painter.drawLine(QPoint(8*d+2, 8*d-2), QPoint(8*d+10, 8*d-2));
    painter.drawLine(QPoint(8*d+2, 8*d-2), QPoint(8*d+2,  8*d-10));
    painter.drawLine(QPoint(8*d-2, 8*d+2), QPoint(8*d-10, 8*d+2));
    painter.drawLine(QPoint(8*d-2, 8*d+2), QPoint(8*d-2,  8*d+10));
    painter.drawLine(QPoint(8*d+2, 8*d+2), QPoint(8*d+10, 8*d+2));
    painter.drawLine(QPoint(8*d+2, 8*d+2), QPoint(8*d+2,  8*d+10));

    //左上卒①
    painter.drawLine(QPoint(d+2, 4*d-2), QPoint(d+10, 4*d-2));
    painter.drawLine(QPoint(d+2, 4*d-2), QPoint(d+2,  4*d-10));
    painter.drawLine(QPoint(d+2, 4*d+2), QPoint(d+10, 4*d+2));
    painter.drawLine(QPoint(d+2, 4*d+2), QPoint(d+2,  4*d+10));

    //左上卒②
    painter.drawLine(QPoint(3*d-2, 4*d-2), QPoint(3*d-10, 4*d-2));
    painter.drawLine(QPoint(3*d-2, 4*d-2), QPoint(3*d-2,  4*d-10));
    painter.drawLine(QPoint(3*d+2, 4*d-2), QPoint(3*d+10, 4*d-2));
    painter.drawLine(QPoint(3*d+2, 4*d-2), QPoint(3*d+2,  4*d-10));
    painter.drawLine(QPoint(3*d-2, 4*d+2), QPoint(3*d-10, 4*d+2));
    painter.drawLine(QPoint(3*d-2, 4*d+2), QPoint(3*d-2,  4*d+10));
    painter.drawLine(QPoint(3*d+2, 4*d+2), QPoint(3*d+10, 4*d+2));
    painter.drawLine(QPoint(3*d+2, 4*d+2), QPoint(3*d+2,  4*d+10));

    //左上卒③
    painter.drawLine(QPoint(5*d-2, 4*d-2), QPoint(5*d-10, 4*d-2));
    painter.drawLine(QPoint(5*d-2, 4*d-2), QPoint(5*d-2,  4*d-10));
    painter.drawLine(QPoint(5*d+2, 4*d-2), QPoint(5*d+10, 4*d-2));
    painter.drawLine(QPoint(5*d+2, 4*d-2), QPoint(5*d+2,  4*d-10));
    painter.drawLine(QPoint(5*d-2, 4*d+2), QPoint(5*d-10, 4*d+2));
    painter.drawLine(QPoint(5*d-2, 4*d+2), QPoint(5*d-2,  4*d+10));
    painter.drawLine(QPoint(5*d+2, 4*d+2), QPoint(5*d+10, 4*d+2));
    painter.drawLine(QPoint(5*d+2, 4*d+2), QPoint(5*d+2,  4*d+10));

    //左上卒④
    painter.drawLine(QPoint(7*d-2, 4*d-2), QPoint(7*d-10, 4*d-2));
    painter.drawLine(QPoint(7*d-2, 4*d-2), QPoint(7*d-2,  4*d-10));
    painter.drawLine(QPoint(7*d+2, 4*d-2), QPoint(7*d+10, 4*d-2));
    painter.drawLine(QPoint(7*d+2, 4*d-2), QPoint(7*d+2,  4*d-10));
    painter.drawLine(QPoint(7*d-2, 4*d+2), QPoint(7*d-10, 4*d+2));
    painter.drawLine(QPoint(7*d-2, 4*d+2), QPoint(7*d-2,  4*d+10));
    painter.drawLine(QPoint(7*d+2, 4*d+2), QPoint(7*d+10, 4*d+2));
    painter.drawLine(QPoint(7*d+2, 4*d+2), QPoint(7*d+2,  4*d+10));

    //左上卒⑤
    painter.drawLine(QPoint(9*d-2, 4*d-2), QPoint(9*d-10, 4*d-2));
    painter.drawLine(QPoint(9*d-2, 4*d-2), QPoint(9*d-2,  4*d-10));
    painter.drawLine(QPoint(9*d-2, 4*d+2), QPoint(9*d-10, 4*d+2));
    painter.drawLine(QPoint(9*d-2, 4*d+2), QPoint(9*d-2,  4*d+10));

    //右下卒①
    painter.drawLine(QPoint(d+2, 7*d-2), QPoint(d+10, 7*d-2));
    painter.drawLine(QPoint(d+2, 7*d-2), QPoint(d+2,  7*d-10));
    painter.drawLine(QPoint(d+2, 7*d+2), QPoint(d+10, 7*d+2));
    painter.drawLine(QPoint(d+2, 7*d+2), QPoint(d+2,  7*d+10));

    //右下卒②
    painter.drawLine(QPoint(3*d-2, 7*d-2), QPoint(3*d-10, 7*d-2));
    painter.drawLine(QPoint(3*d-2, 7*d-2), QPoint(3*d-2,  7*d-10));
    painter.drawLine(QPoint(3*d+2, 7*d-2), QPoint(3*d+10, 7*d-2));
    painter.drawLine(QPoint(3*d+2, 7*d-2), QPoint(3*d+2,  7*d-10));
    painter.drawLine(QPoint(3*d-2, 7*d+2), QPoint(3*d-10, 7*d+2));
    painter.drawLine(QPoint(3*d-2, 7*d+2), QPoint(3*d-2,  7*d+10));
    painter.drawLine(QPoint(3*d+2, 7*d+2), QPoint(3*d+10, 7*d+2));
    painter.drawLine(QPoint(3*d+2, 7*d+2), QPoint(3*d+2,  7*d+10));

    //右下卒③
    painter.drawLine(QPoint(5*d-2, 7*d-2), QPoint(5*d-10, 7*d-2));
    painter.drawLine(QPoint(5*d-2, 7*d-2), QPoint(5*d-2,  7*d-10));
    painter.drawLine(QPoint(5*d+2, 7*d-2), QPoint(5*d+10, 7*d-2));
    painter.drawLine(QPoint(5*d+2, 7*d-2), QPoint(5*d+2,  7*d-10));
    painter.drawLine(QPoint(5*d-2, 7*d+2), QPoint(5*d-10, 7*d+2));
    painter.drawLine(QPoint(5*d-2, 7*d+2), QPoint(5*d-2,  7*d+10));
    painter.drawLine(QPoint(5*d+2, 7*d+2), QPoint(5*d+10, 7*d+2));
    painter.drawLine(QPoint(5*d+2, 7*d+2), QPoint(5*d+2,  7*d+10));

    //右下卒④
    painter.drawLine(QPoint(7*d-2, 7*d-2), QPoint(7*d-10, 7*d-2));
    painter.drawLine(QPoint(7*d-2, 7*d-2), QPoint(7*d-2,  7*d-10));
    painter.drawLine(QPoint(7*d+2, 7*d-2), QPoint(7*d+10, 7*d-2));
    painter.drawLine(QPoint(7*d+2, 7*d-2), QPoint(7*d+2,  7*d-10));
    painter.drawLine(QPoint(7*d-2, 7*d+2), QPoint(7*d-10, 7*d+2));
    painter.drawLine(QPoint(7*d-2, 7*d+2), QPoint(7*d-2,  7*d+10));
    painter.drawLine(QPoint(7*d+2, 7*d+2), QPoint(7*d+10, 7*d+2));
    painter.drawLine(QPoint(7*d+2, 7*d+2), QPoint(7*d+2,  7*d+10));

    //右下卒⑤
    painter.drawLine(QPoint(9*d-2, 7*d-2), QPoint(9*d-10, 7*d-2));
    painter.drawLine(QPoint(9*d-2, 7*d-2), QPoint(9*d-2,  7*d-10));
    painter.drawLine(QPoint(9*d-2, 7*d+2), QPoint(9*d-10, 7*d+2));
    painter.drawLine(QPoint(9*d-2, 7*d+2), QPoint(9*d-2,  7*d+10));
}
