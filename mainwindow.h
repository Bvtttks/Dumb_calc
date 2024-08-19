#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString result_str = "0";
    bool is_num_setted = 0;
    std::vector<std::pair<double, QChar>> operations;

private slots:
    void Digit_numbers();
    void AC_clicked();
    void Choose_action();
    void Dot_clicked();
    void Calc_Result();
};
#endif // MAINWINDOW_H


/*
обычный ввод направляется сразу в result_str
----------------------------------------------------------------------------------------------------------
храним вектор операций- operations
каждый элемент- std pair(int, char)- цифра и знак после неё, что дальше делать
нажатие на действие просто добавляет запись в кеш операций- число из result_str и нажатый знак

нажатие на равно запускает обход кеша
     _______
  .-'       '-.
 /             \
|               |
|,  .-. .-.  ,  |
| )(__/ \__)(   |
|/     /\     \ |
(_     ^^     _)
 \__|IIIIII|__/
  | \IIIIII/ |
  \          /
   `--------`



 /\_/\
( o.o )
 > ^ <
*/
