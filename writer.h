#ifndef WRITER_H
#define WRITER_H
#include <fstream>
#include <iostream>
#include "array.h"
#include <QString>


class writer
{
private:
    int count;
    QString L_filename;
    QString T_filename;
    std::ofstream file_L;
    std::ofstream file_T;

public:
    void write_result(QString name, Array A, Array B, Array result);
    QString write_matr_to_lat(Array A);
    QString write_matr_to_txt(Array A);
    QString writeDet(Array A);
    QString write_Det(Array A);
    void writePow(int name, Array A, Array result);
    writer();
    inline void write_action(QString name, Array A, Array B, Array result);
    inline void writeAction(QString name, Array A, Array result);
    void delete_files();

};


#endif // WRITER_H
