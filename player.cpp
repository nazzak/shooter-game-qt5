#include "player.h"

#include <QKeyEvent>
#include "QDebug"
#include "bullet.h"
#include "game.h"
#include "redEnemy.h"
#include <QVector>

extern Game * game;
Player *Player::s_instance = 0;

Player::Player() :
    m_soundFire{nullptr}
{
    setPixmap(QPixmap(":/image/Rambo.png"));
    setPixmap(pixmap().scaled(QSize(60,100)));

    m_soundShotgun = new QMediaPlayer;
    m_soundShotgun->setMedia(QUrl("qrc:/sound/shotgun.mp3"));

    m_soundFire = new QMediaPlayer;
    m_soundFire->setMedia(QUrl("qrc:/sound/fire.mp3"));

    m_destroyedEnemy =  new QMediaPlayer();
    m_destroyedEnemy->setMedia(QUrl("qrc:/sound/1023.mp3"));

    m_gunReload =  new QMediaPlayer();
    m_gunReload->setMedia(QUrl("qrc:/sound/GunReload.m4a"));
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
        if(pos().y() > 0) //keep the player in the scene
        {
            setPos(x(),y()-50);
            qDebug() << "move up";
        }
    }

    else if(event->key() == Qt::Key_Down)
    {
        if(pos().y()+100 < scene()->height()) //keep the player in the scene
        {
            setPos(x(),y()+50);
            qDebug() << "move down";
        }
    }

    else if(event->key() == Qt::Key_W)
    {

        if(game->m_bulletStatus->getRemainBullets() > 0)
        {
            qDebug() << "Fire";
            game->m_bulletStatus->decrease(1);

            //create bullet
            Bullet * bullet = new Bullet;

            // Play explosion effect
            connect(bullet, &Bullet::notifyCollision, this, [this](){
                if(m_destroyedEnemy->state() == QMediaPlayer::PlayingState)
                {
                    m_destroyedEnemy->setPosition(0);
                }
                else
                    m_destroyedEnemy->play();
            });
            bullet->setPos(x()+45,y());
            scene()->addItem(bullet);

            //play sound : Fire
            if(m_soundFire->state() == QMediaPlayer::PlayingState)
            {
                m_soundFire->setPosition(0);
            }
            else
                m_soundFire->play();

            qDebug() << "detection : espace bar";
        }
        else {
            qDebug() << "Reload...";
        }
    }

    else if(event->key() == Qt::Key_R)
    {
        qDebug() << "Reload";
        game->m_bulletStatus->reload();
        //play sound : gun reload
        if(m_gunReload->state() == QMediaPlayer::PlayingState)
        {
            m_gunReload->setPosition(0);
        }
        else
            m_gunReload->play();
    }

    else if(event->key() == Qt::Key_Space)
    {
        if(game->m_bulletStatus->getRemainBullets() >= 9)
        {
            game->m_bulletStatus->decrease(9);

            QVector<Bullet *> vec(9, nullptr);
            for(auto &t: vec)
            {
                t = new Bullet;
            }

            for(int position = -80, i = 0; i < vec.size(); ++i)
            {
                vec.at(i)->setPos(x()+45+position ,y());
                position += 20;
                scene()->addItem(vec.at(i));
            }

            //play fire sound
            if(m_soundShotgun->state() == QMediaPlayer::PlayingState)
            {
                m_soundShotgun->setPosition(0);
            }
            else
                m_soundShotgun->play();

        }
    }

    else if(event->key() == Qt::Key_E)
    {
        if(game->m_bulletStatus->getRemainBullets() >= 3)
        {
            game->m_bulletStatus->decrease(3);

            QVector<Bullet *> vec(3, nullptr);
            for(auto &t: vec)
            {
                t = new Bullet;
            }

            for(int direction = -5, i = 0; i < vec.size(); ++i)
            {
                vec.at(i)->setPos(x()+45+direction ,y());
                vec.at(i)->setDirection(direction);
                direction += 5;
                scene()->addItem(vec.at(i));
            }

            //play fire sound
            if(m_soundFire->state() == QMediaPlayer::PlayingState)
            {
                m_soundFire->setPosition(0);
            }
            else
                m_soundFire->play();

        }
    }
}
