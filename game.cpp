#include "game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include "FactoryEnemy.h"

#include <QApplication>



Game::Game() :
    m_scene{nullptr},
    m_quit{nullptr},
    m_music{nullptr},
    m_player{nullptr},
    m_health{nullptr},
    m_enemyTimer{nullptr}

{
    // Building the scene
    m_scene = new QGraphicsScene();
    setScene(m_scene);
    setBackgroundBrush(QPixmap(":/image/military_background.png"));

    setFixedSize(600,1000); // set size window
    m_scene->setSceneRect(0,0,600,1000); // set the scene on the screen
    //disable scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Create exit button thet lives with the scene
    m_quit = new QPushButton("Give Up");
    m_quit->setGeometry(500,0,100,50);
    m_quit->setStyleSheet("QPushButton { background-color: red; color: white; border: 5px solid black; border-radius: 999px;}");

    m_scene->addWidget(m_quit);

    QObject::connect(m_quit, &QPushButton::clicked, qApp, &QApplication::quit, Qt::UniqueConnection);

    //Build the player
    m_player = Player::instance();
    //add it to  the scene
    m_scene->addItem(m_player);
    // put the focus on the player (link the keyboard to it)
    m_player->setFlag(QGraphicsItem::ItemIsFocusable);
    m_player->setFocus();
    m_player->setPos((m_scene->width()/2)-50, m_scene->height() - 100);

    // sound effect for destroyed enemy
    m_destroyedEnemy =  new QMediaPlayer();
    m_destroyedEnemy->setMedia(QUrl("qrc:/sound/1023.mp3"));

    // Build an enemy every 1.1 second
    m_enemyTimer = new QTimer;
    QObject::connect(m_enemyTimer, &QTimer::timeout, [this](){
        int random_number = rand() % 3;
        Enemy * e = getEnemy(random_number); // if random == 0 => redEnemy
        connect(e, &Enemy::notifyCollision, [this](){
            m_health->decrease();
            if(m_destroyedEnemy->state() == QMediaPlayer::PlayingState)
            {
                m_destroyedEnemy->setPosition(0);
            }
            else
                m_destroyedEnemy->play();
        });
        m_scene->addItem(e);
    });
    m_enemyTimer->start(1100);

    //Build score
    m_score = new Score;
    m_scene->addItem(m_score);

    //Build bullet status
    m_bulletStatus = new BulletStatus;
    m_scene->addItem(m_bulletStatus);

    m_health = new Health;
    m_scene->addItem(m_health);

    m_music = new QMediaPlayer;
    m_music->setMedia(QUrl("qrc:/music/videoplayback.m4a"));
    m_music->play();

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
    if(m_player)
    {
        m_player->deleteLater();
    }

    //4
    if(m_scene)
    {
        delete m_scene;
        m_scene = nullptr;
    }

    //5
    if(m_destroyedEnemy)
    {
        delete m_destroyedEnemy;
        m_destroyedEnemy = nullptr;
    }
}

void Game::stop()
{
    m_scene->removeItem(m_player);
    m_player->deleteLater();

    //stop building new enemies
    m_enemyTimer->stop();

}
