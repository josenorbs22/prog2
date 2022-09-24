#include <QGraphicsTextItem>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QComboBox>

#include "enemy.h"
#include "game.h"


Game::Game(QWidget *parent)
{
    isMenuOpen = false;
    scene = new QGraphicsScene();

    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QPixmap(":/images/Images/png/Background/metalBackground.png")));
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(800,600);

    player = new Player();
    //player->setRect(0,0,100,100);
    player->setPos(10,300);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    QPushButton * menuButton = new QPushButton();
    menuButton->setIcon(QPixmap(":/images/Images/png/hamburger_button.png"));
    menuButton->setGeometry(750,10,25,25);
    connect(menuButton, &QPushButton::clicked, this, &Game::openMenu);
    scene->addWidget(menuButton);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    QMediaPlayer * music = new QMediaPlayer();
    music->setSource(QUrl(":/sounds/Sounds/Hall of the Mountain King.mp3"));
    music->setLoops(QMediaPlayer::Infinite);

    music->play();
    qDebug() << music->mediaStatus();

    show();
}

void Game::keyPressEvent(QKeyEvent *event){
    isMenuOpen = !isMenuOpen;
    if(event->key() == Qt::Key_Escape){
        openMenu();
    } else
        player->move(event);
}

void Game::openMenu(){
    mainMenu = new QWidget();
    QVBoxLayout * layout = new QVBoxLayout(mainMenu);
    mainMenu->setGeometry(250,200,300,200);
    QPushButton * about = new QPushButton(mainMenu);
    about->setText("Sobre o autor");
    layout->addWidget(about);

    QComboBox * charChoice = new QComboBox(mainMenu);
    charChoice->addItem("Tanque");
    charChoice->addItem("Helicóptero");
    charChoice->addItem("Jato");
    charChoice->addItem("Nave");
    layout->addWidget(charChoice);
    QPushButton * cancel = new QPushButton(mainMenu);
    cancel->setText("Cancelar");
    layout->addWidget(cancel);
    mainMenu->

    connect(charChoice, &QComboBox::currentIndexChanged, player, &Player::changeChar);
    connect(cancel, &QPushButton::clicked, this, &Game::closeMenu);

    connect(about, &QPushButton::clicked, this, &Game::openMessageBox);
    mainMenu->setFocus();
    scene->addWidget(mainMenu);


}

void Game::openMessageBox(){
    QMessageBox perfil;
    perfil.setText("José Norberto Fagundes Isaias");
    perfil.setInformativeText("Matrícula: 19202785");
    perfil.setIconPixmap(QPixmap(":/images/Images/fotoPerfil.png"));
    perfil.exec();
}

void Game::closeMenu(){
    //scene->
    //delete mainMenu;
}
