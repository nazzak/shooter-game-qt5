#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) :
    QGraphicsTextItem(parent),
    m_score{0},
    m_scoreText{"Score: "}
{
    //display score
    setPlainText(m_scoreText + QString::number(m_score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));

}

void Score::increase()
{
    m_score++;
    setPlainText(m_scoreText + QString::number(m_score));
}

int Score::getScore()
{
    return m_score;
}
