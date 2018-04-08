#include "writer.h"
#include <QDebug>
#include <ctime>
//написала для двух матриц пока и создала для текстового поток


writer::writer()//в конструктор подадим путь пользователь когда нибудь
{
    time_t t;
    tm *tk;
    time(&t);
    tk=localtime(&t);
    QString p;
    //пишем путь до файла tex
    QString l = QString::number(tk->tm_mday).append(".")
            .append(QString::number(tk->tm_mon+1))
            .append(".").append(QString::number(1990+tk->tm_year));
    l.push_front("Z:\\calc_result\\");
    p=l;
    L_filename=l.append(".tex");
    T_filename=p.append(".txt");
    file_L.open(L_filename.toStdString(),std::ofstream::out | std::ofstream::app);//открываем поток для латеха
    file_L<<"\\documentclass{article}\n";
    file_L<<"\\usepackage{amsmath}\n";
    file_L<<"\\begin{document}\n";
    file_T.open(T_filename.toStdString(),std::ofstream::out | std::ofstream::app);//для текстового
}

void writer::write_result(QString name, Array A, Array B, Array result)//пока для 2 матриц и результата
{
    file_T<<"hjh";

//операция на 2 матрицы в латех
    file_L<<write_matr_to_lat("A",A).toStdString();
    file_L<<write_matr_to_lat("B",B).toStdString();
    file_L<<write_matr_to_lat("Result",result).toStdString();

}

QString writer::write_matr_to_lat(QString let, Array A){//запись матриц в латехе
    QString M ="\\[";
    M.append(let).append("=\n\\begin{pmatrix}\n");
    for(int i = 0;i<A.getRows();i++)
    {
        for(int j = 0; j<A.getColomns();j++)
        {
            QString b;
            b.setNum(A.getValue(i,j));
            M.append(b).append("&");
        }
        M.append("\\\\");
    }
    M.append("\\end{pmatrix}\n\\]");
    return M;
}

void writer::delete_files(){//пока эта штука для окончания работы с файлом

    file_L<<"\\end{document}\n";
    file_L.close();
    file_T.close();

}


