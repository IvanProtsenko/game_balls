#ifndef BALL_H
#define BALL_H
#include <QtGui>
#include <QPainter>

class Ball
{
protected:
    int vx, vy;
    int r;
    QColor color;
    QPoint point;
public:
    Ball(int w, int h);
    void move(int w, int h);
    void draw(QPainter& painter);
    bool is_collaided(Ball * b);
    void reverse();
};
#endif
