#include "array.h"

Array::Array(){
}

Array::Array(int n, int m)
{
    rows = n;
    colomns = m;
}

Array::~Array(){
}

int Array:: getRows() const{
    return rows;
}

int Array:: getColomns() const{
    return colomns;
}

void Array:: setSize(int n, int m){
    rows = n;
    colomns = m;
}

float Array:: getValue(int n, int m) const {
    return Ar[n][m];
}

void Array:: setValue(int n, int m, float a){
    Ar[n][m] = a;
}

Array Array::add_up(Array &B) const{
    Array A(rows, colomns);
    if (rows == B.getRows() && colomns == B.getColomns()){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < colomns; j++){
                A.setValue(i, j, getValue(i, j) + B.getValue(i, j));
            }
        }
    }
    return A;
}

Array Array::subtruct(Array &B) const
{
    Array A(rows, colomns);
    if (rows == B.getRows() && colomns == B.getColomns()){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < colomns; j++){
                A.setValue(i, j, getValue(i, j) - B.getValue(i, j));
            }
        }
    }
    return A;
}

Array Array:: transpose() const{
    Array Ans(colomns, rows);
    for (int i = 0; i < colomns; i++){
        for (int j = 0; j < rows; j++){
            Ans.setValue(i, j, getValue(j, i));
        }
    }
    return Ans;
}

Array Array::multiply(Array &B) const
{
    float sum;
    Array Ans;
    if (colomns == B.getRows()){
        Ans.setSize(rows, B.getColomns());
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < B.getColomns(); j++){
                sum = 0;
                for (int k = 0; k < B.getColomns() ; k++){
                    sum += getValue(i, k)*B.getValue(k, j);
                    Ans.setValue( i, j, sum);
                }
            }
        }
    }
    return Ans;
}
