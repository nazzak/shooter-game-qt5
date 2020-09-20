#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public :
    Enemy(QGraphicsItem * parent=0);
    ~Enemy();
    void setSpeed(const int &);


private:
    QTimer *m_timerEnemy;

public slots:
    void move();

private :
    int m_speed;
};

#endif // ENEMY_H
