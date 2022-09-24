#include <QTimer>
#include <QDebug>
#include <QList>

#include "game.h"
#include "bullet.h"
#include "enemy.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    indexSprite = 0;
    sprites.push_back(QPixmap(":/images/Images/missile_sprites/missile_1.png"));
    sprites.push_back(QPixmap(":/images/Images/missile_sprites/missile_2.png"));
    sprites.push_back(QPixmap(":/images/Images/missile_sprites/missile_3.png"));
    sprites.push_back(QPixmap(":/images/Images/missile_sprites/missile_4.png"));
    sprites.push_back(QPixmap(":/images/Images/missile_sprites/missile_5.png"));
    sprites.push_back(QPixmap(":/images/Images/missile_sprites/missile_6.png"));

    QTimer * timerMovement = new QTimer();
    QTimer * timerAnimation = new QTimer();
    connect(timerMovement, SIGNAL(timeout()), this, SLOT(move()));
    connect(timerAnimation, SIGNAL(timeout()), this, SLOT(animation()));

    timerMovement->start(13);
    timerAnimation->start(100);
}

void Bullet::animation(){
    setPixmap(sprites.at(indexSprite));
    indexSprite++;
    if(indexSprite == sprites.size())
        indexSprite = 0;
}

void Bullet::move(){
    QList<QGraphicsItem*> colliding_item = collidingItems();

    for(int i = 0, n = colliding_item.size(); i < n; i++){
        if(typeid(*(colliding_item[i])) == typeid(Enemy)){
            game->score->increase();
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);

            delete colliding_item[i];
            delete this;
            return;
        }
    }
    setPos(x() + 3, y());

    if(pos().y() < -10){
        scene()->removeItem(this);
        delete this;
        //qDebug() << "Bullet removed";
    }
}
