#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->line_1, SIGNAL(valueChanged(int)), this, SLOT(matr1_characteristics_changed()));
    QObject::connect(ui->col_1, SIGNAL(valueChanged(int)), this, SLOT(matr1_characteristics_changed()));
    QObject::connect(ui->line_2, SIGNAL(valueChanged(int)), this, SLOT(matr2_characteristics_changed()));
    QObject::connect(ui->col_2, SIGNAL(valueChanged(int)), this, SLOT(matr2_characteristics_changed()));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_3_clicked()
{
}
void MainWindow::on_pushButton_clicked()
{


    int line = ui->line_1->value();
    int col = ui->col_1->value();
    for(int i = 0;i<line;i++){
        for(int j = 0; j<col;j++){
            QString str;
           str = matr1->item(i,j)->text();
           m1[i][j]=str.toInt();
           ui->result->addItem(QString::number(m1[i][j]));

        }

    }

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
void MainWindow::out(int a){
    ui->result->addItem(QString::number(a));
}

