#include <QApplication>
#include "Game.h"

/*
Topics:
- QGraphicsScene
- QGraphicsItem
- QGraphicsView
*/

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
