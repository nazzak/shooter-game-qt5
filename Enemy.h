#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public :
    Enemy(QGraphicsItem * parent=0){};
    virtual ~Enemy(){};
    virtual void setSpeed(const int &) = 0;

public slots:
    virtual void move() = 0;

signals:
    void notifyCollision();
};

#endif // ENEMY_H
