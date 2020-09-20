#ifndef GREENENEMY_H
#define GREENENEMY_H

#include "Enemy.h"
#include <QTimer>

class GreenEnemy: public Enemy
{
    Q_OBJECT
public :
    GreenEnemy(QGraphicsItem * parent=0);
    ~GreenEnemy() override;
    void setSpeed(const int & =3) override;


private:
    QTimer *m_timerEnemy;

public slots:
    void move() override;

private :
    int m_speed;
};

#endif // GREENENEMY_H
