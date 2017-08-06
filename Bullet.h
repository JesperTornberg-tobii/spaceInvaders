#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet();
public slots:
    // "public slots" means it can be connected to a signal
    void move();
};

#endif // BULLET_H
