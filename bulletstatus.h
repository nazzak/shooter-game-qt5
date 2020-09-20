#ifndef BULLETSTATUS_H
#define BULLETSTATUS_H

#include <QGraphicsItem>

class BulletStatus: public QGraphicsTextItem{
public:
    BulletStatus();
    BulletStatus(const int &);
    void decrease(const int &);
    int getRemainBullets();
    void setNbBullets(const int &);
    void reload();

private:
    int m_remaining;
};

#endif // BULLETSTATUS_H
