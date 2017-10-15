#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand()
#include "Game.h"

#include <iostream>
#include <QDebug>

extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsRectItem(){
    // create a random seed based on system time
    srand((unsigned) time(0));

    // set random postion
    int random_positon = rand() % (game->sceneWidth);
    setPos(random_positon, 0);

    // set random speed (something weird is going on as the speed
    // sometimes seems disconnected from the actual velocity of
    // the enemy i.e. moving way faster than they should)
    int extraSpeed = rand() % 7;
    std::cout << "Random extra speed: " << extraSpeed << std::endl;
    Enemy::speed = 3 + extraSpeed;

    // Draw the enemy
    int random_width = 25 + (rand() % 100);
    int random_height = 25 + (rand() % 100);
    setRect(0, 0, random_width, random_height);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // randomize spawn time
    int spawn_time = rand() % 50;
    std::cout << "Spawn time: " << spawn_time << std::endl << std::endl;
    timer->start(spawn_time);
}

void Enemy::move(){

    // Move enemy down
    setPos(x(), y()+Enemy::speed);
    if (pos().y() - rect().height() > (game->sceneHeight)){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

}
