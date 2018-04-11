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
    QString l = QString::number(tk->tm_hour).append("_").append(QString::number(tk->tm_min)).append("_")
            .append(QString::number(tk->tm_mday)).append(".")
            .append(QString::number(tk->tm_mon+1))
            .append(".").append(QString::number(1900+tk->tm_year));
    l.push_front("D:\\result\\");
    p=l;
    L_filename=l.append(".tex");
    T_filename=p.append(".txt");
    file_L.open(L_filename.toStdString(),std::ofstream::out | std::ofstream::app);//открываем поток для латеха
    file_L<<"\\documentclass{article}\n";
    file_L<<"\\usepackage{amsmath}\n";
    file_L<<"\\begin{document}\n";
    file_T.open(T_filename.toStdString(),std::ofstream::out | std::ofstream::app);//для текстового
}

inline void writer:: write_action(QString name, Array A, Array B, Array result){//вывод для действий с 2 матрицасм
    file_L << "$\n"<<write_matr_to_lat(A).toStdString();
    file_L << name.toStdString()<<"\n";
    file_L << write_matr_to_lat(B).toStdString();
    file_L << "=\n";
    file_L << write_matr_to_lat(result).toStdString()<<"$\n\\\\\n";
    file_T << "A =     " << write_matr_to_txt(A).toStdString() << "\n";
    file_T << "B =     " << write_matr_to_txt(B).toStdString() << "\n";
    file_T << "result = " << write_matr_to_txt(result).toStdString()<<"\n";
}


inline void writer:: writeAction(QString name, Array A, Array result){//вывод длядействий с одной матрицы
    file_L << "$\n"<<write_matr_to_lat(A).toStdString();
    file_L << "^" << name.toStdString() << "\n";
    file_L << "=\n";
    file_L << write_matr_to_lat(result).toStdString()<<"$\n\\\\\n";
    file_T << "M =     " << write_matr_to_txt(A).toStdString() << "\n";
    file_T << "result = " << write_matr_to_txt(result).toStdString() << "\n";
}


void writer:: writePow(int n, Array A, Array result){
    QString p = QString::number(n);
    file_L << "$\n" << write_matr_to_lat(A).toStdString();
    file_L << "^" << p.toStdString() << "\n";
    file_L << "=\n";
    file_L << write_matr_to_lat(result).toStdString()<<"$\n\\\\\n";
    file_T << "Возведение матрицы в степень " << p.toStdString() << "\n";
    file_T << "M =     " << write_matr_to_txt(A).toStdString() << "\n";
    file_T << "result = " << write_matr_to_txt(result).toStdString() << "\n";
}


void writer::write_result(QString name, Array A, Array B,  Array result)//пока для 2 матриц и результата
{
//операция на 2 матрицы в латех
    if (name == "{-1}"){
        file_T << "Поиск обратной матрицы: \n";
        writeAction(name, A, result);
    }
    if (name == "T"){
        file_T << "Поиск транспонированой матрицы: \n";
        writeAction(name, A, result);
    }
    if (name == "+"){
        file_T << "Сложение двух матриц: \n";
        write_action(name, A, B, result);
    }
    if (name == "*"){
        file_T << "Умножение двух матриц: \n";
        write_action(name, A, B,  result);
    }
    if (name == "-"){
        file_T << "Вычитание двух матриц: \n";
        write_action(name, A, B, result);
    }
    if (name == "det"){
        file_L << "$\n" << "det" << write_matr_to_lat(A).toStdString();
        file_L << "=\n";
        file_L << write_Det(result).toStdString()<<"$\n\\\\\n";
        file_T << "Определитель матрицы:\n";
        file_T << "M =     " << write_matr_to_txt(A).toStdString() << "\n";
        file_T << "result = " << write_matr_to_txt(result).toStdString() << "\n";
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

QString writer::write_matr_to_txt(Array A){//запись матриц в латехе
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

QString writer::write_Det(Array A){//запись матриц в латехе
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

void writer::delete_files(){//пока эта штука для окончания работы с файлом

    file_L<<"\\end{document}\n";
    file_L.close();
    file_T.close();

}
