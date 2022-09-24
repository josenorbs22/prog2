#include <QFont>
#include "health.h"

Health::Health(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    health = 10;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("comics sans", 16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("comics sans", 16));
}

int Health::getHealth(){
    return health;
}
