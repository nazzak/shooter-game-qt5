#ifndef BULLETSTATUS_H
#define BULLETSTATUS_H

#include <QGraphicsItem>

class BulletStatus: public QGraphicsTextItem{
public:
    BulletStatus();
    void decrease(const int &);
    int getValue();
    void reload();

private:
    int m_remaining;
};

#endif // BULLETSTATUS_H
