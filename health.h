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
    void setHealth(const int &);

private:
    int m_health;
    QString m_text;
    QString m_gameOverText;
};

#endif // HEALTH_H
