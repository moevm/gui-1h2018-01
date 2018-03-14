#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include "algo.h"

class algo;

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int m1 [6][6];
    int m2 [6][6];
    int col_numb1();
    int col_numb2();
    int line_numb1();
    int line_numb2();
    void out(int a);
    void det()


private:

    Ui::MainWindow *ui;
    QStandardItemModel *matr1;
    QStandardItemModel *matr2;


private slots:
    void on_pushButton_clicked();//кнопка для добавления новой стрелки
    void on_pushButton_3_clicked();//кнопка для добавления новой стрелки
    //void on_plus_clicked();//кнопка для добавления новой стрелки
    void matr1_characteristics_changed();//добавить новую стрелку

};

#endif // MAINWINDOW_H
