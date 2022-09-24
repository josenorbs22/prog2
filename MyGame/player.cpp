#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>

#include <QTimer>
#include "player.h"
#include "bullet.h"
#include "enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    indexSprite = 0;
    sprites.push_back(QPixmap(":/images/Images/png/playerLeft.png"));


    //setPixmap(QPixmap(":/images/Images/png/player.png"));
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(animation()));

    timer->start(100);

    bulletsound = new QMediaPlayer();
    bulletsound->setSource(QUrl("qrc:/sounds/sounds/Laser.mp3"));
}

void Player::animation(){
    setPixmap(sprites.at(indexSprite));
    indexSprite++;
    if(indexSprite == sprites.size())
        indexSprite = 0;
}

void Player::move(QKeyEvent *event){
    //qDebug() << "Key pressed detected";
    if(event->key() == Qt::Key_A){
        if(pos().x() > 0)
            setPos(x()-10, y());
    } else if(event->key() == Qt::Key_D){
        if(pos().x() + 100 < 800)
            setPos(x() + 10, y());
    } else if(event->key() == Qt::Key_W){
        setPos(x(), y() - 10);
    } else if(event->key() == Qt::Key_S){
        setPos(x(), y() + 10);
    } else if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y() + 15);
        scene()->addItem(bullet);

        if(bulletsound->playbackState() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        } else if(bulletsound->playbackState() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
}

void Player::spawn(){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::changeChar(int index){
    sprites.clear();
    qDebug() << index;
    indexSprite = 0;
    if(index == 0){
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_1.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_2.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_3.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_4.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_5.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_6.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_7.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_8.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_9.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_10.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_11.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_12.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_13.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_14.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_15.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_16.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_17.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_18.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_19.png"));
        sprites.push_back(QPixmap(":/images/Images/tank_sprites/moving_20.png"));
    } else if(index == 1){
        sprites.push_back(QPixmap(":/images/Images/heli_sprites/moving_1.png"));
        sprites.push_back(QPixmap(":/images/Images/heli_sprites/moving_2.png"));
        sprites.push_back(QPixmap(":/images/Images/heli_sprites/moving_3.png"));
        sprites.push_back(QPixmap(":/images/Images/heli_sprites/moving_4.png"));
        sprites.push_back(QPixmap(":/images/Images/heli_sprites/moving_5.png"));
        sprites.push_back(QPixmap(":/images/Images/heli_sprites/moving_6.png"));
        sprites.push_back(QPixmap(":/images/Images/heli_sprites/moving_7.png"));
        sprites.push_back(QPixmap(":/images/Images/heli_sprites/moving_8.png"));
        sprites.push_back(QPixmap(":/images/Images/heli_sprites/moving_9.png"));
    } else if(index == 2){
        sprites.push_back(QPixmap(":/images/Images/jet_sprites/moving_1.png"));
        sprites.push_back(QPixmap(":/images/Images/jet_sprites/moving_2.png"));
        sprites.push_back(QPixmap(":/images/Images/jet_sprites/moving_3.png"));
        sprites.push_back(QPixmap(":/images/Images/jet_sprites/moving_4.png"));
        sprites.push_back(QPixmap(":/images/Images/jet_sprites/moving_5.png"));
    } else if(index == 3){
        sprites.push_back(QPixmap(":/images/Images/png/playerLeft.png"));
    }
}
