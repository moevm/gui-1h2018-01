#include "writer.h"
#include <QDebug>
#include <ctime>
//написала для двух матриц пока и создала для текстового поток

writer::writer()//в конструкторе записывается в буфер заголовок для латеха
{
    QString str = "\\documentclass[14pt,a4paper]{scrartcl}\n";
    str.append("\\usepackage{amsmath}\n").append("\\renewcommand{\\baselinestretch}{1.5}\n")
            .append("\\begin{document}\n").append("\\noindent\n");
    buf_lat.enqueue(str);
}

void  writer::setPath(QString path){
    path.append("/");
    L_filename = path;
    T_filename = path;
}

inline void writer:: write_action(QString name, Array A, Array B, Array result){//вывод для действий с 2 матрицасм
    QString str_L = "$\n";
    if((A.getColomns() == 1) && (A.getRows() == 1)){
        str_L.append(write_Det(A));
        str_L.append(name).append("\n");
        str_L.append(write_matr_to_lat(B));
        str_L.append("=\n");
        str_L.append(write_matr_to_lat(result)).append("$\n\\\\\n");

        buf_lat.enqueue(str_L);
    }
    if((B.getColomns() == 1) && (B.getRows() == 1)){
        str_L.append(write_matr_to_lat(A));
        str_L.append(name).append("\n");
        str_L.append(write_Det(B));
        str_L.append("=\n");
        str_L.append(write_matr_to_lat(result)).append("$\n\\\\\n");

        buf_lat.enqueue(str_L);
    }
    if((A.getRows() != 1) && (A.getColomns() != 1)|| (B.getRows() != 1) && (B.getColomns() != 1)){
        str_L.append(write_matr_to_lat(A));
        str_L.append(name).append("\n");
        str_L.append(write_matr_to_lat(B));
        str_L.append("=\n");
        str_L.append(write_matr_to_lat(result)).append("$\n\\\\\n");
    }


    QString str_T;
    str_T.append("A =     ").append(write_matr_to_txt(A)).append("\n");
    str_T.append("B =     ").append(write_matr_to_txt(B)).append("\n");
    str_T.append("result = ").append(write_matr_to_txt(result)).append("\n");

    buf_txt.enqueue(str_T);
}


inline void writer:: writeAction(QString name, Array A, Array result){//вывод длядействий с одной матрицы
    QString str_L = "$\n";
    str_L.append(write_matr_to_lat(A));
    str_L.append("^").append(name).append("\n").append("=\n");
    str_L.append(write_matr_to_lat(result)).append("$\n\\\\\n");

    buf_lat.enqueue(str_L);

    QString str_T;
    str_T.append("M =     ").append(write_matr_to_txt(A)).append("\n");
    str_T.append("result = ").append(write_matr_to_txt(result)).append("\n");

    buf_txt.enqueue(str_T);
}


void writer:: writePow(int n, Array A, Array result){
    QString p = QString::number(n);

    QString str_L = "$\n";
    str_L.append(write_matr_to_lat(A));
    str_L.append("^").append(p).append("\n");
    str_L.append("=\n").append(write_matr_to_lat(result)).append("$\n\\\\\n");

    buf_lat.enqueue(str_L);

    QString str_T;
    str_T.append("Возведение матрицы в степень ").append(p).append("\n");
    str_T.append("M =     ").append(write_matr_to_txt(A)).append("\n");
    str_T.append("result = ").append(write_matr_to_txt(result)).append("\n");

    buf_txt.enqueue(str_T);
}


void writer::write_result(QString name, Array A, Array B,  Array result)//пока для 2 матриц и результата
{
 //операция на 2 матрицы в латех
    if (name == "{-1}"){
        buf_txt.enqueue("Поиск обратной матрицы: \n");
        writeAction(name, A, result);
    }
    if (name == "T"){
        buf_txt.enqueue("Поиск транспонированой матрицы: \n");
        writeAction(name, A, result);
    }
    if (name == "+"){
        buf_txt.enqueue("Сложение двух матриц: \n");
        write_action(name, A, B, result);
    }
    if (name == "*"){
        if((A.getRows() == 1) && (A.getColomns() == 1)|| (B.getRows() == 1) && (B.getColomns() == 1)){
            buf_txt.enqueue("Умножение матрицы на число: \n");
            write_action(name, A, B,  result);
        }
        else{
            buf_txt.enqueue("Умножение двух матриц: \n");
            write_action(name, A, B,  result);
        }
    }
    if (name == "-"){
        buf_txt.enqueue("Вычитание двух матриц: \n");
        write_action(name, A, B, result);
    }
    if (name == "det"){
        QString str_L;
        QString str_T;
        str_L.append("$\n").append("det").append(write_matr_to_lat(A));
        str_L.append("=\n").append(write_Det(result)).append("$\n\\\\\n");
        str_T.append("Определитель матрицы:\n");
        str_T.append("M =     ").append(write_matr_to_txt(A)).append("\n");
        str_T.append("result = ").append(write_matr_to_txt(result)).append("\n");

        buf_txt.enqueue(str_T);
        buf_lat.enqueue(str_L);
    }

}

QString writer::write_matr_to_lat(Array A){//запись матриц в латехе
    QString M ="\\begin{pmatrix}\n";
    for(int i = 0; i < A.getRows(); i++)
    {
        for(int j = 0; j < A.getColomns();j++)
        {
            QString b;
            b.setNum(A.getValue(i,j));
            M.append(b).append("&");
        }
        M.append("\\\\");
    }
    M.append("\\end{pmatrix}\n");
    return M;
}

QString writer::write_matr_to_txt(Array A){//запись матриц в текстовый
    QString M;
    for(int i = 0; i < A.getRows(); i++)
    {
        M.append("\t");
        for(int j = 0; j < A.getColomns();j++)
        {
            QString b;
            b.setNum(A.getValue(i,j));
            M.append(b).append("\t");
        }
        M.append("\n\t");
    }
    return M;
}

QString writer::write_Det(Array A){
    QString M ="\\begin{matrix}\n";
    for(int i = 0; i < A.getRows(); i++)
    {
        for(int j = 0; j<A.getColomns();j++)
        {
            QString b;
            b.setNum(A.getValue(i,j));
            M.append(b).append("&");
        }
        M.append("\\\\");
    }
    M.append("\\end{matrix}\n");
    return M;
}

QString writer::writeDet(Array A){//запись матриц в латехе

    QString M ="\\begin{vmatrix}\n";
    for(int i = 0; i < A.getRows(); i++)
    {
        for(int j = 0; j<A.getColomns();j++)
        {
            QString b;
            b.setNum(A.getValue(i,j));
            M.append(b).append("&");
        }
        M.append("\\\\");
    }
    M.append("\\end{vmatrix}\n");
    return M;
}

void writer::save_files(){
    buf_lat.enqueue("\\end{document}\n");
//даем название файлу (время дата)
    time_t t;
    tm *tk;
    time(&t);
    tk=localtime(&t);
    QString p;
    QString l = QString::number(tk->tm_hour).append("_").append(QString::number(tk->tm_min)).append("_")
            .append(QString::number(tk->tm_mday)).append(".")
            .append(QString::number(tk->tm_mon+1))
            .append(".").append(QString::number(1900+tk->tm_year));
    p=l;
    L_filename.append(l.append(".tex"));
    T_filename.append(p.append(".txt"));
    qDebug()<<L_filename;
    //открываем поток
    std::ofstream file_L;
    std::ofstream file_T;

    file_L.open(L_filename.toStdString(),std::ofstream::out | std::ofstream::app);//открываем поток для латеха
    file_T.open(T_filename.toStdString(),std::ofstream::out | std::ofstream::app);//для текстового
    //запись в поток
    QString str = buf_lat.head();//заголовок латеха

    while(!buf_lat.empty())
    {
        file_L<<buf_lat.dequeue().toStdString();
    }
    buf_lat.enqueue(str);//сохраняем заголовок латеха

    while(!buf_txt.empty())
    {
        file_T<<buf_txt.dequeue().toStdString();

    }
    //закрываем поток

    file_L.close();
    file_T.close();

}
