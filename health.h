#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsItem>

class Health: public QGraphicsTextItem
{
public:
    Health();
    Health(int value);
    ~Health();

    void decrease();
    int getHealth();

private:
    int m_health;
};

#endif // HEALTH_H
