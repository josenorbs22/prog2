#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <vector>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent = 0);
public slots:
    void move();
    void animation();

private:
    std::vector<QPixmap> sprites;
    int indexSprite;
};

#endif // BULLET_H
