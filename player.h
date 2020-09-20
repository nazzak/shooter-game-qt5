#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QGraphicsItem>

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Player();
    ~Player();

    void keyPressEvent(QKeyEvent *event);

private:
    QMediaPlayer * m_soundFire;

signals:

public slots:
    void buildEnemy();

};

#endif // PLAYER_H
