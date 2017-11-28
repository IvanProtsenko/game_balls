#ifndef PLAYER_H
#define PLAYER_H
#include <QtGui>
#include <QPainter>
#include "balls.h"

class Player : public Ball
{
protected:
    int lives;
public:
    Player(int w, int h);
    void minus_lives();
    int return_lives();
    void move(int w, int h, int key);
    void draw(QPainter& painter);
};

#endif // PLAYER_H
