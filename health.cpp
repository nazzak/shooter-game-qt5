#include "health.h"
#include <QFont>
#include "game.h"

extern Game * game;

Health::Health(int value) :
    m_health{value},
    m_text{"Health : "},
    m_gameOverText{"Game Over"}
{
    setPlainText(m_text + QString::number(m_health));
    setPos(x(),y()+20);
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

Health::Health() : Health(5)
{
}

Health::~Health()
{

}

int Health::getHealth()
{
    return m_health;
}

void Health::setHealth(const int & _val)
{
    m_health = _val;
}

void Health::decrease()
{
    --m_health;

    if (m_health > 0)
    {
        setPlainText(m_text + QString::number(m_health));
    }
    else if (m_health == 0)
    {
        setPlainText(m_gameOverText);
        setPos((scene()->width()/2 - 80), scene()->height()/2);
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",50));
        game->stop();
    }
    else if (m_health < 0)
    {
        //setPlainText("WHAAAAT");
    }
}
