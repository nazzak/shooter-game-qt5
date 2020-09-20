#include "player.h"

#include <QKeyEvent>
#include "QDebug"

#include "enemy.h"
#include "game.h"

extern Game * game;

Player::Player() :
    m_soundFire{nullptr}
{
    m_soundFire = new QMediaPlayer;
    m_soundFire->setMedia(QUrl("qrc:/son/tire.mp3"));
}

Player::~Player()
{
    if(m_soundFire)
    {
        m_soundFire->stop();
        delete m_soundFire;
        m_soundFire = nullptr;
    }
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
        {
            setPos(x()-50,y());
            qDebug() << "move left";
        }
    }

    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x()+100 < scene()->width()) //keep the player in the scene
        {
            setPos(x()+50 ,y());
            qDebug() << "move right";
        }
    }

    else if(event->key() == Qt::Key_Up)
    {
        if(pos().y() > 0) //empecher le rectangle de sortir de la scene
        {
        setPos(x(),y()-50);
        qDebug() << "move up";
        }
    }

    else if(event->key() == Qt::Key_Down)
    {
        if(pos().y()+100 < scene()->height()) //empecher le rectangle de sortir de la scene
        {
        setPos(x(),y()+50);
        qDebug() << "move down";
        }
    }

    else if(event->key() == Qt::Key_Space)
    {
        qDebug() << "Fire";

    }

    else if(event->key() == Qt::Key_R)
    {
        qDebug() << "Reload";
    }

    else if(event->key() == Qt::Key_Alt)
    {

    }
}

void Player::buildEnemy()
{
    Enemy * enemy = new Enemy;
    int random_number = rand() % 3;
    if (random_number == 0)
    {
        enemy->setSpeed(10);
    }
    scene()->addItem(enemy);
}
