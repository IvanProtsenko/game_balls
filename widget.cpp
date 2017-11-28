#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMessageBox>
#include <ctime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->hide();
    for(int i = 0; i<NUM; i++) {
        balls[i] = new Ball(width(), height());
    }
    started = false;
    player = new Player(width(), height());
    connect(&timer, SIGNAL(timeout()), this, SLOT(moveAll()));
    timer.start(100);
}

Widget::~Widget()
{
    for(int i = 0; i<NUM; i++) {
        delete balls[i];
    }
    delete ui;
}
void Widget::on_pushButton_2_clicked()
{
    started = true;
    gamestart = time(NULL);
    ui->lcdNumber->show();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
}

void Widget::on_pushButton_clicked()
{
    this->close();
}
void Widget::paintEvent(QPaintEvent *e)
{
    if(started) {
        ui->lcdNumber->show();
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        QPainter painter(this);
        for(int i = 0; i<NUM; i++) {
            balls[i] -> draw(painter);
        }
        player->draw(painter);
    }
}
void Widget::stop() {
    if(started) {
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(moveAll()));
        timer.stop();
        started = false;
        QMessageBox::warning(this, "Balls", "Игра окончена! Результат - "+QString::number(time(0)-gamestart) + " секунд.");
        lives = 10;
        for(int i = 0; i<NUM; i++) {
            delete balls[i];
        }
        delete player;
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->lcdNumber->hide();
        for(int i = 0; i<NUM; i++) {
            balls[i] = new Ball(width(), height());
        }
        player = new Player(width(), height());
        connect(&timer, SIGNAL(timeout()), this, SLOT(moveAll()));
        timer.start(100);
    }
}
void Widget::moveAll()
{
    if(started) {
        for(int i = 0; i<NUM; i++) {
            for(int j = i+1; j<NUM; j++) {
                if(balls[i]->is_collaided(balls[j])) {
                    balls[i]->reverse();
                    balls[j]->reverse();
                }
            }
        }
        for(int i = 0; i<NUM; i++) {
            if(player->is_collaided(balls[i])) {
                player->minus_lives();
                balls[i]->reverse();
            }
        }
        for(int i = 0; i<NUM; i++) {
            balls[i] -> move(width(), height());
        }
        if(player->return_lives() == 0) Widget::stop();
        Widget::on_lcdNumber_overflow();
        this->repaint();
    }
}

void Widget::keyPressEvent(QKeyEvent *k)
{
    if(started) {
        if(k->key() == Qt::Key_W) {
            player->move(width(), height(), k->key());
            qDebug() << "Go up";
        }
        if(k->key() == Qt::Key_A) {
            player->move(width(), height(), k->key());
            qDebug() << "Go left";
        }
        if(k->key() == Qt::Key_S) {
            player->move(width(), height(), k->key());
            qDebug() << "Go down";
        }
        if(k->key() == Qt::Key_D) {
            player->move(width(), height(), k->key());
            qDebug() << "Go right";
        }
    }
}

void Widget::on_lcdNumber_overflow()
{
    if(started) {
        ui->lcdNumber->display(player->return_lives());
    }
}


