#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <ctime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    gamestart = time(NULL);
    int lives = 20;
    connect(timer, SIGNAL(timeout()), this, SLOT());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

}

void Widget::on_progressBar_destroyed()
{

}
