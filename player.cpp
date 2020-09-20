#include "player.h"

#include <QKeyEvent>
#include "QDebug"
#include "bullet.h"
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

        if(game->m_bulletStatus->getValue() > 0)
        {
            qDebug() << "Fire";
            game->m_bulletStatus->decrease(1);

        //create bullet
        Bullet * ma_fleche = new Bullet;
        ma_fleche->setPos(x()+45,y());
        scene()->addItem(ma_fleche);

        //jouer le son de tire
        if(m_soundFire->state() == QMediaPlayer::PlayingState)
        {
            m_soundFire->setPosition(0);
        }
        else
        m_soundFire->play();

        //qDebug() << "detection : espace";
        }
        else {
            qDebug() << "Reload...";
        }

    }

    else if(event->key() == Qt::Key_R)
    {
        qDebug() << "Reload";
        game->m_bulletStatus->reload();
    }

    else if(event->key() == Qt::Key_Alt)
    {
        if(game->m_bulletStatus->getValue() >= 3)
        {
            game->m_bulletStatus->decrease(3);
        //creation de nouvelles fleches
        Bullet * f1 = new Bullet;
        Bullet * f2 = new Bullet;
        Bullet * f3 = new Bullet;
        f1->setPos(x()+45,y());
        f2->setPos(x()+45,y());
        f3->setPos(x()+45,y());
        f2->setDirection(5);
        f3->setDirection(-5);
        scene()->addItem(f1);
        scene()->addItem(f2);
        scene()->addItem(f3);

        //jouer le son de tire
        if(m_soundFire->state() == QMediaPlayer::PlayingState)
        {
            m_soundFire->setPosition(0);
        }
        else
        m_soundFire->play();

        //qDebug() << "detection : espace";
        }
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
