#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

#include <QDebug>

// there is an external global object called game of type game pointer
extern Game * game;

Bullet::Bullet(){
    // draw bullet
    setRect(0,0,10,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Set the timer to 50 [ms] (timeout is emitted)
    timer->start(50);

}

void Bullet::move(){
    // if bullet collides with enemy, destroy both

    // collidingItems() contains a list of pointers to all items the bullet is colliding with
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int id = 0, n = colliding_items.size(); id < n; ++id) {
        // dereference the current pointer and check its  typeid
        bool isEnemy = typeid(*(colliding_items[id])) == typeid(Enemy);
        if (isEnemy) {
            // increase the score
            game->score->increase();

            // remove both
            scene()->removeItem(colliding_items[id]);
            scene()->removeItem(this);

            // delete both
            delete colliding_items[id];
            delete this;

            // Ensure following code is not executed (i.e. move up)
            return;
        }
    }

    // Bullet move up
    setPos(x(), y()-10);

    // Delete the bullet if it leaves the scene
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    };
}
