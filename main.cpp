#include <QApplication>
#include "Board.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Board board;
    board.show();
a
    return app.exec();
}
