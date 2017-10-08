#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand()
#include "Game.h"

#include <QDebug>

extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsRectItem(){
    // create a random seed based on system time
    srand((unsigned) time(0));

    // set random postion
    int random_positon = rand() % 700;
    setPos(random_positon, 0);

    // set random speed
    Enemy::speed = 3 + (rand() % 7);

    // Draw the enemy
    int random_width = 25 + (rand() % 100);
    int random_height = 25 + (rand() % 100);
    setRect(0, 0, random_width, random_height);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // randomize spawn time
    int spawn_time = rand() % 50;
    timer->start(spawn_time);
}

void Enemy::move(){

    // Move enemy down
    setPos(x(), y()+Enemy::speed);
    if (pos().y() - rect().height() > 600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

}
