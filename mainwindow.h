#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>


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
    void out(int a);

private:

    Ui::MainWindow *ui;
    QStandardItemModel *matr1;
    QStandardItemModel *matr2;


private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void matr1_characteristics_changed();
    void matr2_characteristics_changed();

};

#endif // MAINWINDOW_H
