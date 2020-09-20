#ifndef GAME_H
#define GAME_H

#include <QObject>

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QMediaPlayer>
#include "player.h"
#include "health.h"

class Game: public QGraphicsView
{
public:
    Game();
    ~Game();
    void stop();

private:
    QGraphicsScene * m_scene;
    QPushButton *m_quit;
    QMediaPlayer * m_music;

    Player * m_player;
    QTimer * m_enemyTimer;

    Health * m_health;


};

#endif // GAME_H
