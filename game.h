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
#include "bulletstatus.h"
#include "score.h"

class Game: public QGraphicsView
{
public:
    Game();
    ~Game();
    void stop();
    BulletStatus * m_bulletStatus;
    Score * m_score;
    Health * m_health;

private:
    QGraphicsScene * m_scene;
    QPushButton *m_quit;
    QMediaPlayer * m_music;

    Player * m_player;
    QTimer * m_enemyTimer;

    QMediaPlayer * m_destroyedEnemy;






};

#endif // GAME_H
