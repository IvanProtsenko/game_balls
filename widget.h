#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "balls.h"
#include "player.h"
#include <QTimer>
#include <QPaintEvent>
#include <QKeyEvent>

namespace Ui {
    class Widget;
}

const int NUM = 5;

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
    Ball * balls[NUM];
    Player * player;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void keyPressEvent(QKeyEvent * k);
    void paintEvent(QPaintEvent * e);
protected slots:
    void moveAll();
    void stop();
private slots:
    void on_lcdNumber_overflow();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    bool started;
    int lives;
    int gamestart;
    Ui::Widget *ui;
};
#endif
