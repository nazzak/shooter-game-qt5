#include "bulletstatus.h"
#include <QFont>
#include "game.h"

extern Game * game;

BulletStatus::BulletStatus()
{
    m_remaining = 20;

    setPlainText("Balles : " + QString::number(m_remaining));
    setPos(x(),y()+40);
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
}

int BulletStatus::getValue()
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

}

void BulletStatus::reload()
{
    m_remaining = 20;
    setPlainText("Bullets : " + QString::number(m_remaining));
}
