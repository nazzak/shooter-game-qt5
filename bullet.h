#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bullet(QGraphicsItem * parent=0);
    void setDirection(const int &);
    QTimer *m_timer;
    ~Bullet();

public slots:
    void move();

signals:
    void notifyCollision();

private :
    int m_direct;
};

#endif // BULLET_H
