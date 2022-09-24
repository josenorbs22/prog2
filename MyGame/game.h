#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QKeyEvent>

#include "player.h"
#include "score.h"
#include "health.h"


class Game : public QGraphicsView
{
public:
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    QWidget * mainMenu;
    Player * player;
    Score * score;
    Health * health;
    void keyPressEvent(QKeyEvent *event);
    bool isMenuOpen;

public slots:
    void openMenu();
    void openMessageBox();
    void closeMenu();
};

#endif // GAME_H
