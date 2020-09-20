#include "bulletstatus.h"
#include <QFont>
#include "game.h"

extern Game * game;

BulletStatus::BulletStatus() :
    BulletStatus(20)
{

}

BulletStatus::BulletStatus(const int &nb)
{
    m_remaining = nb;

    setPlainText("Balles : " + QString::number(m_remaining));
    setPos(x(),y()+40);
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void BulletStatus::setNbBullets(const int & _nb)
{
    m_remaining = _nb;
}

int BulletStatus::getRemainBullets()
{
    return m_remaining;
}

void BulletStatus::decrease(const int &quantite)
{
    if(m_remaining > 0)
        m_remaining = m_remaining - quantite;

    if (m_remaining > 0)
    {
        setPlainText("Bullets : " + QString::number(m_remaining));
    }
    else if (m_remaining == 0)
    {
        setPlainText("Bullets : RELOAD");
    }
    else if (m_remaining < 0)
    {
        setPlainText("WTF");
    }

}

void BulletStatus::reload()
{
    setNbBullets(20);
    setPlainText("Bullets : " + QString::number(m_remaining));
}
