#include "Board.h"
#include <QPainter>
#include <QMouseEvent>

Board::Board(QWidget *parent) : QWidget(parent)
{
    for (int i = 0; i<32; i++) {
        _s[i].init(i);
    }
    _selectid = -1;
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int d = 40;
    _r = d/2;
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

    //绘制棋子
    for (int i = 0; i<32; i++) {
        drawStone(painter, i);
    }
}

QPoint Board::center(int row, int col)
{
    QPoint ret;

    ret.rx() = (col+1) * _r * 2;
    ret.ry() = (row+1) * _r * 2;
    return ret;
}

QPoint Board::center(int id) {
    return center(_s[id]._row, _s[id]._col);
}

void Board::drawStone(QPainter &painter, int id)
{
    if (_s[id]._dead) {
        return;
    }
    QPoint c = center(id);
    QRect rect = QRect(c.x()-_r, c.y()-_r, _r*2, _r*2);

    if (id == _selectid) {
        painter.setBrush(QBrush(Qt::gray));
    } else {
        painter.setBrush(QBrush(Qt::yellow));
    }
    painter.setPen(Qt::black);
    painter.drawEllipse(center(id), _r, _r);
    if (_s[id]._red) {
        painter.setPen(Qt::red);
    }
    painter.setFont(QFont("system", _r, 700));
    painter.drawText(rect, _s[id].getText(), QTextOption(Qt::AlignCenter));
}

bool Board::getRowCol(QPoint pt, int &row, int &col)
{
    for (row = 0; row<=9; row++) {
        for (col = 0; col <= 8; col++) {
            QPoint c = center(row, col);
            int dx = c.x() - pt.x();
            int dy = c.y() - pt.y();
            int dist = dx*dx + dy*dy;
            if (dist < _r*_r) {
                return true;
            }
        }
    }
    return false;
}

void Board::mouseReleaseEvent(QMouseEvent *ev)
{
    QPoint pt = ev->pos();
    int row, col;
    bool bRet = getRowCol(pt, row, col);
    if (bRet ==  false) {
        return;
    }

    int i;
    int clickid = -1;
    for (i = 0; i<32; i++) {
        if (_s[i]._row == row && _s[i]._col == col && _s[i]._dead == false) {
            break;
        }
    }

    if (i < 32) {
        clickid = i;
    }


    if (_selectid == -1) {
        if (clickid != -1) {
            _selectid = clickid;
            update();
        }
    } else {
        _s[_selectid]._row = row;
        _s[_selectid]._col = col;
        if (clickid != -1) {
            _s[clickid]._dead = true;
        }
        _selectid = -1;
        update();
    }
}
