#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Initialize to 0
    score = 0;

    // draw text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase(){
    score++;
    // Update the text
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}
