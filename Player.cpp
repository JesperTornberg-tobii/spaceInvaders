#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"

#include <QDebug>

extern Game * game;

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_A){
        // Move left
        if (pos().x() > 0)
            setPos(x()-20, y());
    }
    else if (event->key() == Qt::Key_D) {
        // Move right
        if (pos().x() + 100 < (game->sceneWidth))
            setPos(x()+20, y());
    }
    else if (event->key() == Qt::Key_Space){
        // Create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + rect().width()/2, y());
        scene()->addItem(bullet);
    }

}

void Player::spawn(){
    // create enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

