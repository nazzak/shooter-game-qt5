#include "sprite.h"
#include "qdebug.h"

Sprite::Sprite(int X, int Y, QObject *parent) :
    QObject(parent),
    QGraphicsItem(),
    m_coorX{X},
    m_coorY{Y},
    m_currentFrame{0} // Sets the coordinates of the current frame of the sprite
{
    m_spriteImage = new QPixmap(":/image/qpixmap_sprite.png"); // Load the sprite image QPixmap
    m_spriteImageScaled = m_spriteImage->scaled(QSize(1500, 100)); //rescale the image from 20X300 vers 100X1500

    m_timer = new QTimer();   // Create a timer for sprite animation
    connect(m_timer, &QTimer::timeout, this, &Sprite::nextFrame);
    m_timer->start(50);   // Run the sprite on the signal generation with a frequency of 25 ms
}

Sprite::~Sprite() {
    if(m_timer) {
        delete m_timer;
        m_timer = nullptr;
    }

    if(m_spriteImage)
    {
        delete m_spriteImage;
        m_spriteImage = nullptr;
    }
    qDebug() << "Effect removed from memory";
}

QRectF Sprite::boundingRect() const
{
    return QRectF(m_coorX,m_coorY,100,100);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* In the graphic renderer we draw the sprite
     * The first two arguments - is the X and Y coordinates of where to put QPixmap
     * The third argument - a pointer to QPixmap
     * 4 and 5 of the arguments - The coordinates in the image QPixmap, where the image is displayed
     * By setting the X coordinate with the variable currentFrame we would like to move the camera on the sprite
     * and the last two arguments - the width and height of the displayed area, that is, the frame
     * */

    //painter->scale(2,2);
    painter->drawPixmap(m_coorX, m_coorY, m_spriteImageScaled, m_currentFrame,0,100,100);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Sprite::nextFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */
    m_currentFrame += 100;
    if (m_currentFrame >= 1500 )
    {
        m_currentFrame = 0;
        delete this;
    }

    update(m_coorX,m_coorY,100,100);
}
