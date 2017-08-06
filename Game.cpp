#include "Game.h"
#include <QTimer>
#include <QMediaPlayer>
#include "Enemy.h"
#include "Button.h"

#include <QFileInfo>
#include <iostream>

Game::Game(QWidget * parent){

    int sceneWidth = 1024;
    int sceneHeight = 768;

    // set up screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(sceneWidth, sceneHeight);

    // set up scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
    setScene(scene);
}


void Game::start(){
    // clear the screen
    scene->clear();

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

}

void Game::displayMainMenu(){
    // create title text
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Space Invaders"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int xTitlePos = this->width()/2 - titleText->boundingRect().width()/2;
    int yTitlePos = 150;
    titleText->setPos(xTitlePos, yTitlePos);
    scene->addItem(titleText);

    // create play button
    Button *playButton = new Button(QString("Play"));
    int xPlayPos = this->width()/2 - playButton->boundingRect().width()/2;
    int yPlayPos = 275;
    playButton->setPos(xPlayPos, yPlayPos);
    connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    // create quit button
    Button *quitButton = new Button(QString("Quit"));
    int xQuitPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int yQuitPos = 350;
    quitButton->setPos(xQuitPos, yQuitPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);

}
