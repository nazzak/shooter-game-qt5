#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QUrl>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Sprite(int X = 0, int Y = 0,QObject *parent = 0);
    ~Sprite();
    int m_coorX;
    int m_coorY;


private slots:
    void nextFrame();   // Slot for turning images into QPixmap

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;


    QTimer *m_timer;      // Timer for turning images into QPixmap
    QPixmap *m_spriteImage;   // In this QPixmap object will be placed sprite
    int m_currentFrame;   // Coordinates X, which starts the next frame of the sprite
    QPixmap m_spriteImageScaled;

};

#endif // SPRITE_H
