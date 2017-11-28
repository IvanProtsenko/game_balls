#include "player.h"
#include <QDebug>
Player::Player(int w, int h): Ball(w,h)
{
    r = 25;
    vx = 10;
    vy = 10;
    lives = 10;
}
void Player::draw(QPainter &painter) {
    qDebug() << r<<point;
    painter.setBrush(QBrush(Qt::black));
    painter.drawImage(point.x()-r, point.y()-r, QImage(":/image/images/player.png").scaled(2*r, 2*r));
}
void Player::minus_lives() {
    lives--;
}

int Player::return_lives() {
    return lives;
}

void Player::move(int w, int h, int key)
{
    if(key == Qt::Key_W) {
        point -= QPoint(0, vy);
    }
    if(key == Qt::Key_A) {
        point -= QPoint(vx, 0);
    }
    if(key == Qt::Key_S) {
        point += QPoint(0, vy);
    }
    if(key == Qt::Key_D) {
        point += QPoint(vx, 0);
    }

    if(point.x() + r >= w) {
        point -= QPoint(vx, 0);
    }
    if(point.y() + r >= h) {
        point -= QPoint(0, vy);
    }
    if(point.x() - r <= 0) {
        point += QPoint(vx, 0);
    }
    if(point.y() - r <= 0) {
        point += QPoint(0, vy);
    }
}
