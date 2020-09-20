#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent=0);
    void increase();
    int getScore();

private:
    int m_score;
    QString m_scoreText;
};

#endif // SCORE_H
