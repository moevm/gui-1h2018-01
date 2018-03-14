#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ограничения на размерность матрицы
    ui->line_1->setMaximum(5);
    ui->line_1->setMinimum(1);
    ui->line_2->setMaximum(5);
    ui->line_2->setMinimum(1);
    ui->col_1->setMaximum(5);
    ui->col_1->setMinimum(1);
    ui->col_2->setMaximum(5);
    ui->col_2->setMinimum(1);

    QObject::connect(ui->line_1, SIGNAL(valueChanged(int)), this, SLOT(matr1_characteristics_changed()));
    QObject::connect(ui->col_1, SIGNAL(valueChanged(int)), this, SLOT(matr1_characteristics_changed()));
    QObject::connect(ui->line_2, SIGNAL(valueChanged(int)), this, SLOT(matr2_characteristics_changed()));
    QObject::connect(ui->col_2, SIGNAL(valueChanged(int)), this, SLOT(matr2_characteristics_changed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plus_clicked()
{
    read_matr1();
    read_matr2();
    res = m1.add_up(m2);
    show_result();
}
void MainWindow::show_result(){
     m = new QStandardItemModel;
     QStandardItem *item;
     QString s;
     int line = res.getRows();
     int col = res.getColomns();

     for(int i = 0; i<line;i++)
     {
         for(int j = 0;j<col;j++ )
         {
             s.setNum(res.getValue(i,j));
             item = new QStandardItem(s);
             m->setItem(i, j, item);
         }
     }

     ui->result->setModel(m);
     ui->result->resizeRowsToContents();
     ui->result->resizeColumnsToContents();
}

void MainWindow::read_matr1()
{
    int line = ui->line_1->value();
    int col = ui->col_1->value();
    m1.setSize(line,col);
    for(int i = 0;i<line;i++){
        for(int j = 0; j<col;j++){
            QString str;
           str = matr1->item(i,j)->text();
           m1.setValue(i,j,str.toFloat());
        }
    }
}
void MainWindow::read_matr2()
{
    int line = ui->line_2->value();
    int col = ui->col_2->value();
    m2.setSize(line,col);
    for(int i = 0;i<line;i++){
        for(int j = 0; j<col;j++){
            QString str;
           str = matr2->item(i,j)->text();
           m2.setValue(i,j,str.toFloat());
        }
    }
}
void MainWindow::on_pushButton_clicked()
{


}

void MainWindow::on_minus_clicked(){
    read_matr1();
    read_matr2();
    res = m1.subtruct(m2);
    show_result();
}

void MainWindow::matr1_characteristics_changed()
{
    matr1 = new QStandardItemModel;
    QStandardItem *item;
    int line = ui->line_1->value();
    int col = ui->col_1->value();

    for(int i = 0; i<line;i++)
    {
        for(int j = 0;j<col;j++ )
        {
            item = new QStandardItem(QString("0"));
            matr1->setItem(i, j, item);
        }
    }

    ui->matr1->setModel(matr1);
    ui->matr1->resizeRowsToContents();
    ui->matr1->resizeColumnsToContents();

}

void MainWindow::matr2_characteristics_changed()
{
    matr2 = new QStandardItemModel;
    QStandardItem *item;
    int line = ui->line_2->value();
    int col = ui->col_2->value();

    for(int i = 0; i<line;i++)
    {
        for(int j = 0;j<col;j++ )
        {
            item = new QStandardItem(QString("0"));
            matr2->setItem(i, j, item);
        }
    }

    ui->matr2->setModel(matr2);
    ui->matr2->resizeRowsToContents();
    ui->matr2->resizeColumnsToContents();

}


