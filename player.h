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

    static Player *instance()
    {
        if (!s_instance)
          s_instance = new Player;
        return s_instance;
    }
    void keyPressEvent(QKeyEvent *event);

private:
    static Player *s_instance;
    Player();
    ~Player();
    QMediaPlayer * m_soundFire;

signals:

public slots:
    void buildEnemy();

};

#endif // PLAYER_H
