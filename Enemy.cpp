#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand()
#include "Game.h"

#include <QDebug>

extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsRectItem(){
    // set random postion
    int random_positon = rand() % 700;
    setPos(random_positon, 0);

    // Draw the enemy
    setRect(0, 0, 100, 100);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // Move enemy down
    setPos(x(), y()+5);
    if (pos().y() - rect().height() > 600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

}
