#include "redEnemy.h"
#include "player.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "game.h"
#include <QTime>
#include <typeinfo>
#include "sprite.h"

extern Game * game;


RedEnemy::RedEnemy(QGraphicsItem *parent):
    Enemy(),
    m_timerEnemy{new QTimer}
{
    //random position

    setPixmap(QPixmap(":/image/48.png"));
    setPixmap(pixmap().scaled(QSize(100,100)));
    m_speed = 5;


    int random_number = rand() % (static_cast<int>(game->scene()->width()-pixmap().width()));
    setPos(random_number, 0);

    QObject::connect(m_timerEnemy, &QTimer::timeout, this, &RedEnemy::move);

    m_timerEnemy->start(50);
}

RedEnemy::~RedEnemy()
{
    if(m_timerEnemy)
    {
        m_timerEnemy->stop();
        delete m_timerEnemy;
        m_timerEnemy = nullptr;
    }
}

void RedEnemy::move()
{
    //check collision with player
    QList<QGraphicsItem *> obj_collision = collidingItems();
    for (int i= 0, n= obj_collision.size(); i<n; ++i)
    {

        if (typeid(*obj_collision[i]) == typeid(Player)) //check if type Player
        {
            qDebug() << "Alert";
            emit notifyCollision();

            Sprite * sp = new Sprite(x(),y());
            scene()->addItem(sp);

            m_timerEnemy->stop();
            delete m_timerEnemy;
            m_timerEnemy = nullptr;
            scene()->removeItem(this);
            delete this;
            return;     //stop moving after delete this
        }
    }

    //move down
    setPos(x(), y()+m_speed);
    if(pos().y() > scene()->height())
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "out of screen, enemy removed";
    }
}

void RedEnemy::setSpeed(const int &_speed)
{
    m_speed = _speed;
}
