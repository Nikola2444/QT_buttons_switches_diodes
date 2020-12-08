#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <QIcon>
#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>
//#include "kbuttongroup"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void update_leds();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_checkBox_toggled(bool checked);

    void on_checkBox_2_clicked(bool checked);

    void on_checkBox_3_clicked(bool checked);

    void on_checkBox_4_clicked(bool checked);

    void on_pushButton_pressed();

    void button1_released();
    void button2_released();
    void button3_released();
    void button4_released();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_4_pressed();

private:
    Ui::MainWindow *ui;
    QTimer *led_timer;
    QIcon *off_switch, *on_switch;
    QPixmap *off_pix;
    QPixmap *on_pix;
    ifstream leds_file;
    fstream switch_file;
    fstream button_file;
    int i;
};

#endif // MAINWINDOW_H
