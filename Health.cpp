#include "Health.h"
#include <QFont>
#include <QApplication>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Initialize to 0
    health = 3;

    // draw text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease(){
    health--;
    if (gameOver()){
        // Close the application
        QApplication::quit();
    } else {
        // Update the text
        setPlainText(QString("Health: ") + QString::number(health));
    }
}

int Health::getHealth(){
    return health;
}

bool Health::gameOver(){
    return health < 1;
}
