#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QMessageBox>
#include "array.h"

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    QStandardItemModel *matr1;
    QStandardItemModel *matr2;
    QStandardItemModel *m;
    Array m1;
    Array m2;
    Array res;
    void read_matr1();
    void read_matr2();
    void show_result();
    void clean_matr();

private slots:
    //кнопки операций
    void on_plus_clicked();
    void on_minus_clicked();
    void on_mult_clicked();
    void on_transpA_clicked();
    void on_transpB_clicked();
    void on_powA_clicked();
    void on_powB_clicked();
    void on_detA_clicked();
    void on_detB_clicked();
    void on_reverseA_clicked();
    void on_reverseB_clicked();
    //изменение размеров матрицы
    void matr1_characteristics_changed();
    void matr2_characteristics_changed();
    //выбор степени матрицы


};

#endif // MAINWINDOW_H
