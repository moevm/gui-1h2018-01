#ifndef WRITER_H
#define WRITER_H
#include <fstream>
#include <iostream>
#include "array.h"
#include <QString>
#include <QQueue>


class writer
{
private:
    int count;
    QString L_filename;
    QString T_filename;
    QQueue <QString> buf_lat;
    QQueue <QString> buf_txt;
    QString user_path;
    //QString str_L;
    //QString str_T;



public:
    writer();
    void setPath(QString path);
    void write_result(QString name, Array A, Array B, Array result);
    QString write_matr_to_lat(Array A);
    QString write_matr_to_txt(Array A);
    QString writeDet(Array A);
    QString write_Det(Array A);
    void writePow(int name, Array A, Array result);
    inline void write_action(QString name, Array A, Array B, Array result);
    inline void writeAction(QString name, Array A, Array result);
    void save_files();

};


#endif // WRITER_H
