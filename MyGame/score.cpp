#include <QFont>
#include "score.h"

Score::Score(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("comics sans", 16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("comics sans", 16));
}

int Score::getScore(){
    return score;
}
