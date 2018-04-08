#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "writer.h"
#include <iostream>


writer w;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    matr1_characteristics_changed();//создает матрицу 1х1
    matr2_characteristics_changed();//создает матрицу 1х1
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plus_clicked()
{
    clean_matr();
    read_matr1();
    read_matr2();
    if(is_ok1&&is_ok2)
    {
        int n1 = m1.getRows(), l1 = m1.getColomns(), n2 = m2.getRows(), l2 = m2.getColomns();
        if(n1!=n2 ||l1!=l2)
            show_error("Неверная размерность матрицы.", "Количество строк/стобцов не равны");
        else
        {
            res = m1.add_up(m2);
            show_result();
            w.write_result("+",m1,m2,res);
        }
    }
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
    bool ok = true;
    int line = ui->line_1->value();
    int col = ui->col_1->value();
    m1.setSize(line,col);
    m1_er.setSize(line,col);
    for(int i = 0;i<line;i++){
        for(int j = 0; j<col;j++){
            QString str;
            str = matr1->item(i,j)->text();
            float val = str.toFloat(&ok);
            if(ok==false){
                is_ok1 = false;
                m1_er.setValue(i,j, -1);
            }
            else
                m1_er.setValue(i,j, 1);
            m1.setValue(i,j,val);
        }
    }
    //вывод ошибок
    if(!is_ok1)
    {
        QString str_er;
        for(int i = 0;i<line;i++){
            for(int j = 0; j<col;j++){
                if(m1_er.getValue(i, j)==-1)
                {
                    str_er.append("Ошибка в ячейке: ( ").append(QString::number(i+1)).append(", ").append(QString::number(j+1)).append(" )").append('\n');
                }
            }
        }
        show_error("Некорректные данные в матрице 1: ", str_er);
    }

}
void MainWindow::read_matr2()
{
    bool ok = true;
    int line = ui->line_2->value();
    int col = ui->col_2->value();
    m2.setSize(line,col);
    m2_er.setSize(line,col);
    for(int i = 0;i<line;i++){
        for(int j = 0; j<col;j++){
            QString str;
            str = matr2->item(i,j)->text();
            float val = str.toFloat(&ok);
            if(ok==false){
                is_ok2 = false;
                m2_er.setValue(i,j, -1);
            }
            else
                m2_er.setValue(i,j, 1);
            m2.setValue(i,j,val);
        }
    }
    //вывод ошибок
    if(!is_ok2)
    {
        QString str_er;
        for(int i = 0;i<line;i++){
            for(int j = 0; j<col;j++){
                if(m2_er.getValue(i, j)==-1)
                    str_er.append("Ошибка в ячейке: ( ").append(QString::number(i+1)).append(", ").append(QString::number(j+1)).append(" )").append('\n');
            }
        }
        show_error("Некорректные данные в матрице 2: ", str_er);
    }
}

void MainWindow::on_powA_clicked()
{
    clean_matr();
    read_matr1();
    if(is_ok1)
    {
        int n1 = m1.getRows(), l1 = m1.getColomns();
        if(n1!=l1)
            show_error("Неверная размерность матрицы.", "Количество строк матрицы не равно количеству стобцов");
        else{
            int a = ui->num_powA->value();
            res = m1.elevate(a);
            show_result();
        }
    }
}
void MainWindow::on_powB_clicked(){
    clean_matr();
    read_matr2();
    if(is_ok2){
        int n1 = m2.getRows(), l1 = m2.getColomns();
        if(n1!=l1)
            show_error("Неверная размерность матрицы.", "Количество строк матрицы не равно количеству стобцов");
        else{
            int a = ui->num_powB->value();
            res = m2.elevate(a);
            show_result();
        }
    }
}

void MainWindow::on_detA_clicked(){
    clean_matr();
    read_matr1();
    if(is_ok1)
    {int n1 = m1.getRows(), l1 = m1.getColomns();
        if(n1!=l1)
            show_error("Неверная размерность матрицы.", "Количество строк матрицы не равно количеству стобцов");

        else{
            res.setSize(1, 1);
            res.setValue(0,0,m1.det());
            show_result();
        }
    }

}

void MainWindow::on_detB_clicked(){
    clean_matr();
    read_matr2();
    if(is_ok2)
    {int n1 = m2.getRows(), l1 = m2.getColomns();
        if(n1!=l1)
            show_error("Неверная размерность матрицы.", "Количество строк матрицы не равно количеству стобцов");
        else{
            res.setSize(1, 1);
            res.setValue(0,0,m2.det());
            show_result();
        }
    }
}

void MainWindow::on_reverseA_clicked(){
    clean_matr();
    read_matr1();
    if(is_ok1)
    { int n1 = m1.getRows(), l1 = m1.getColomns();
        if(n1!=l1)
            show_error("Неверная размерность матрицы.", "Количество строк матрицы не равно количеству стобцов");
        else{
            if(m1.det()==0)
                show_error("Обратной матрицы не существует.", "Определитель матрицы равен 0");
            else{
                res = m1.inverse();
                show_result();
            }
        }
    }
}

void MainWindow::on_reverseB_clicked(){
    clean_matr();
    read_matr2();
    int n1 = m2.getRows(), l1 = m2.getColomns();
    if(is_ok2)
    {
        if(n1!=l1)
            show_error("Неверная размерность матрицы.", "Количество строк матрицы не равно количеству стобцов");
        else{

            if(m2.det()==0){
                show_error("Обратной матрицы не существует.", "Определитель матрицы равен 0");
            }else{
                res = m2.inverse();
                show_result();
            }

        }
    }

}

void MainWindow::clean_matr(){
    is_ok1=true;
    is_ok2=true;
    for(int i = 0;i<5;i++){
        for(int j = 0; j<5;j++){
            res.setValue(i,j,0);
            m2.setValue(i,j,0);
            m1.setValue(i,j,0);
            m1_er.setValue(i,j,0);
            m2_er.setValue(i,j,0);
        }
    }

}

void MainWindow::on_minus_clicked(){
    clean_matr();
    read_matr1();
    read_matr2();
    if(is_ok1&&is_ok2){
        int n1 = m1.getRows(), l1 = m1.getColomns(), n2 = m2.getRows(), l2 = m2.getColomns();
        if(n1!=n2 ||l1!=l2)
        {
            show_error("Неверная размерность матрицы.", "Количество строк/стобцов не равны");
        }
        else
        {
            res = m1.subtruct(m2);
            show_result();
            w.write_result("-",m1,m2,res);
        }
    }
}

void MainWindow::on_mult_clicked(){
    clean_matr();
    read_matr1();
    read_matr2();
    if(is_ok1&&is_ok2)
    {
        if((ui->col_1->value()==1)&&(ui->line_1->value()==1))
        {
                res = m2.multiply(m1.getValue(0,0));
                show_result();
        }
        else{
            if((ui->col_2->value()==1)&&(ui->line_2->value()==1))
            {
                res = m1.multiply(m2.getValue(0,0));
                show_result();
            }
            else{
                int l1 = m1.getColomns(), n2 = m2.getRows();
                if(l1 == n2)
                {
                    res = m1.multiply(m2);
                    show_result();
                    w.write_result("*",m1,m2,res);
                }
                else
                {
                    show_error("Невозможно произвести умножение!","Количество столбцов первой матрицы не равно количеству строк второй матрицы");
                }
            }
        }
    }
}



void MainWindow::on_transpA_clicked(){
    clean_matr();
    read_matr1();
    if(is_ok1)
    {
        res = m1.transpose();
        show_result();
    }
}

void MainWindow::on_transpB_clicked(){
    clean_matr();
    read_matr2();
    if(is_ok2){
        res = m2.transpose();
        show_result();
     }
}
void MainWindow::on_save_clicked(){//типо закончили работу и сохраняеи все дерьмо что наделали
        w.delete_files();
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

void MainWindow::show_error(QString er, QString ev){
    QMessageBox msgBox;
    msgBox.setText(er);
    msgBox.setInformativeText(ev);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();

    m = new QStandardItemModel;
    QStandardItem *item;
    item = new QStandardItem("Error");
    m->setItem(0, 0, item);
    ui->result->setModel(m);
    ui->result->resizeRowsToContents();
    ui->result->resizeColumnsToContents();
}


