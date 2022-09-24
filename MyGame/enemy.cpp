#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>

#include "game.h"
#include "enemy.h"

extern Game *game;

Enemy::Enemy()
{
    int random_number = rand() % 500;
    setPos(800, random_number);
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":images/Images/png/enemyShip.png"));

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(13);
}

void Enemy::move(){
    setPos(x() - 2, y());

    if(pos().x() < -50){
        scene()->removeItem(this);
        game->health->decrease();
        delete this;
        //qDebug() << "Enemy removed";
    }
}
