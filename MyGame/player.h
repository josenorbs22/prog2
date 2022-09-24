#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <vector>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = 0);
    void move(QKeyEvent *event);

public slots:
    void spawn();
    void animation();
    void changeChar(int index);

private:
    QMediaPlayer * bulletsound;
    std::vector<QPixmap> sprites;
    int indexSprite;
};

#endif // PLAYER_H
