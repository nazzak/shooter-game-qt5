#include "health.h"
#include <QFont>
#include "game.h"

extern Game * game;

Health::Health(int value) :
    m_health{value}
{
    setPlainText("Vie : " + QString::number(m_health));
    setPos(x(),y()+20);
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

Health::Health() : m_health(5)
{
    setPlainText("Vie : " + QString::number(m_health));
    setPos(x(),y()+20);
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

Health::~Health()
{

}

int Health::getHealth()
{
    return m_health;
}

void Health::decrease()
{
    --m_health;

    if (m_health > 0)
    {
        setPlainText("Vie : " + QString::number(m_health));
    }
    else if (m_health == 0)
    {
        setPlainText("Perdu");
        setPos(scene()->width()/2, scene()->height()/2);
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",50));
        game->stop();
    }
    else if (m_health < 0)
    {
        //setPlainText("YOU LOSE");
    }
}
