#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void timerer();
    void on_lcdNumber_overflow();

    void on_lcdNumber_2_overflow();

    void on_progressBar_destroyed();

private:
    int lives;
    Ui::Widget *ui;
};

#endif // WIDGET_H
