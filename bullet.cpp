#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "enemy.h"
#include "game.h"
#include "sprite.h"
#include <typeinfo>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{

    setRect(0,0,5,5);
    m_direct = 0;

    //connect timer to move bullet
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(direction()));

    timer->start(100);
}


void Bullet::direction() {
    //check collision with enemy
    QList<QGraphicsItem *> obj_collision = collidingItems();
    for (int i= 0, n= obj_collision.size(); i<n; ++i)
            {

        if (typeid(*obj_collision[i]) == typeid(Enemy))
        {
            qDebug() << "Enemy hit";

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

    setPos(x()+m_direct, y()-10);
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
    if(m_timer)
    {
        m_timer->stop();
        delete m_timer;
        m_timer = nullptr;
    }
}
