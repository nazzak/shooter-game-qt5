#include "game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>

#include <QApplication>

//#define IOS


Game::Game() :
    m_scene{nullptr},
    m_quit{nullptr},
    m_music{nullptr},
    m_player{nullptr}

{
    // Building the scene
    m_scene = new QGraphicsScene();
    setScene(m_scene);

    // Create exit button thet lives with the scene
    m_quit = new QPushButton("Quit");
    m_quit->setGeometry(m_scene->width()-100,0,100,50);
    m_quit->setStyleSheet("QPushButton { background-color: yellow; }");
    m_scene->addWidget(m_quit);

    m_music = new QMediaPlayer;
    m_music->setMedia(QUrl("qrc:/music/bg.mp3"));
    m_music->play();

    QObject::connect(m_quit, &QPushButton::clicked, qApp, &QApplication::quit);

    //Build the player
    m_player = new Player;
    m_player->setRect(0,0,100,100); //position 0,0  size 100,100px
    //add it to  the scene
    m_scene->addItem(m_player);
    // put the focus on the player (link the keyboard to it)
    m_player->setFlag(QGraphicsItem::ItemIsFocusable);
    m_player->setFocus();

    //disable scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    setFixedSize(1000,1000); // set size window
    m_scene->setSceneRect(0,0,800,1000); // set the scene on the screen
    m_player->setPos((m_scene->width()/2)-50, m_scene->height() - m_player->rect().height());


}

Game::~Game()
{
    //1
    if(m_music)
    {
        m_music->stop();
        delete m_music;
        m_music = nullptr;
    }

    //2
    if(m_quit)
    {
        delete m_quit;
        m_quit = nullptr;
    }

    //3
    if(m_scene)
    {
        delete m_scene;
        m_scene = nullptr;
    }
}

void Game::stop()
{

}
