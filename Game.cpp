#include "Game.h"
#include <QTimer>
#include <QMediaPlayer>
#include "Enemy.h"

#include <QFileInfo>
#include <iostream>

Game::Game(QWidget * parent){
    // create scene
    scene = new QGraphicsScene();
    int sceneWidth = 800;
    int sceneHeight = 600;
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);

    // add view
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(sceneWidth, sceneHeight);

    // create the player, make it focusable and add to the scene
    player = new Player();
    int playerWidth = 100;
    int playerHeight = 100;
    player->setRect(0,0, playerWidth, playerHeight);
    player->setPos(scene->width()/2 - player->rect().width()/2,
                   scene->height() - player->rect().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // create the score
    score = new Score();
    scene->addItem(score);

    // Create health
    health = new Health();
    // Position the health 25 pixels below the score
    int yTextOffset = 25;
    health->setPos(health->x(), health->y() + yTextOffset);
    scene->addItem(health);

    // spawn enemies, might not want to keep it inside "player"
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    int spawnTime = 2000;
    timer->start(spawnTime);

    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgmusic.mp3"));
    music->setVolume(100);
    music->play();
    qDebug() << music->errorString();

    // show view
    show();

}
