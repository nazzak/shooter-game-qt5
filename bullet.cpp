#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "Enemy.h"
#include "game.h"
#include "sprite.h"
#include <typeinfo>
#include "redEnemy.h"
#include "greenenemy.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{

    setRect(0,0,5,5);
    setBrush(Qt::white);
    m_direct = 0;

    //connect timer to move bullet
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &Bullet::move);

    timer->start(50);
}


void Bullet::move() {
    //check collision with enemy
    QList<QGraphicsItem *> obj_collision = collidingItems();
    for (int i= 0, n= obj_collision.size(); i<n; ++i)
    {

        if (typeid(*obj_collision[i]) == typeid(RedEnemy) || typeid(*obj_collision[i]) == typeid(GreenEnemy))
        {
            qDebug() << "Enemy hit";
            game->m_score->increase();
            emit notifyCollision();

            Sprite *sp = new Sprite(obj_collision[i]->pos().x(),obj_collision[i]->pos().y());
            scene()->addItem(sp);
            //timer->stop();
            scene()->removeItem(obj_collision[i]); //enemy
            scene()->removeItem(this); //remove bullet
            //delete timer;
            delete obj_collision[i];
            delete this;
        }
    }

    setPos(x()+m_direct, y()-20);
    if(pos().y() + rect().height() < 0)
    {
        //remove bullet when out of scene
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::setDirection(const int &direction)
{
    m_direct = direction;
}

Bullet::~Bullet()
{
    //    if(m_timer)
    //    {
    //        m_timer->stop();
    //        delete m_timer;
    //        m_timer = nullptr;
    //    }
}
