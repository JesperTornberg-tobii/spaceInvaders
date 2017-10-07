#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView{
    Q_OBJECT

public:
    // constructors (parent allows the game to be included in an other window)
    Game(QWidget * parent=NULL);

    // methods
    void displayMainMenu();
    void displayGameOver();

    // attributes
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

public slots:
    void start();
    void displaySettingsMenu();

};

#endif // GAME_H
