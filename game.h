#ifndef GAME_H
#define GAME_H

#include <QObject>

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QMediaPlayer>

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


};

#endif // GAME_H
