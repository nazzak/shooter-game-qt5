#ifndef REDENEMY_H
#define REDENEMY_H

#include "Enemy.h"
#include <QTimer>

class RedEnemy : public Enemy
{
    Q_OBJECT
public :
    RedEnemy(QGraphicsItem * parent=0);
    ~RedEnemy() override;
    void setSpeed(const int &) override;


private:
    QTimer *m_timerEnemy;

public slots:
    void move() override;

private :
    int m_speed;
};

#endif // REDENEMY_H
