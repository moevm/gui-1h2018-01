#include "array.h"
#include <QDebug>

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
                for (int k = 0; k < colomns; k++){
                    sum += getValue(i, k)*B.getValue(k, j);
                    Ans.setValue(i, j, sum);
                 }
            }
        }
    }
    return Ans;
}

//умножение на константу
Array Array::multiply(float c) const
{
    Array Ans;
    Ans.setSize(rows, colomns);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colomns; j++){
            Ans.setValue(i, j, c*getValue(i, j));
        }
    }
    return Ans;
}

Array Array::minor(int i,int j) const
{
    Array Ans(rows-1,colomns-1);
    for(int n = 0; n < Ans.getRows();n++)
    {
        for(int m = 0; m < Ans.getColomns(); m++)
        {
            if(m >= j && n >= i)
                Ans.setValue(n,m, getValue(n+1,m+1));
            if (m >= j && n < i)
                    Ans.setValue(n,m, getValue(n, m+1));
            if(m < j && n >= i)
                Ans.setValue(n,m, getValue(n+1,m));
            if(n < i && m < j)
                Ans.setValue(n,m, getValue(n, m));
        }
    }
    return Ans;
}
//определитель
float Array::det() const
{
    if(colomns == rows){
        float sum = 0;
        if(rows > 2)
        {
            for(int j = 0; j < colomns; j++)
            {
                Array Ar = minor(0,j);
                if(j%2 == 0)
                {
                    sum = sum + (getValue(0,j) * Ar.det());
                }
                else
                {
                    sum = sum - (getValue(0,j) * Ar.det());
                }
            }
        }
        else
        {
            sum = sum + ((getValue(0,0) * getValue(1,1)) - (getValue(1,0) * getValue(0,1)));
        }
        if(rows == 1){
            sum = getValue(0, 0);
        }
        return sum;
    }
}

Array Array::inverse() const
{
    if(rows == 1){
        Array Ans(rows, colomns);
        Ans.setValue(0, 0,  1/getValue(0, 0));
        return Ans;
    }
    else{
        if(rows > 2)
        {
            Array inv = inv_1();
            Array Ans = inv.transpose();
            return Ans.multiply(1/det());
        }
        else
        {
            Array Ans(rows,colomns);
            Ans.setValue(0,0, getValue(1,1) );
            Ans.setValue(0,1, -getValue(0,1));
            Ans.setValue(1,0, -getValue(1,0));
            Ans.setValue(1,1, getValue(0,0));
            return Ans.multiply(1/det());
        }
    }
}
Array Array::inv_1() const
{
    Array A(rows, colomns);
    for( int i = 0; i < A.rows; i++)
    {
        for(int j = 0; j < A.colomns; j++)
        {
            Array B = minor(i,j);

            if(((i%2) == 0 && (j%2 ==0) )|| (i==j))
            {
                A.setValue(i,j, B.det());
            }
            else
            {
                A.setValue(i,j, -(B.det()));
            }
        }
    }
    return A;
}


Array Array:: elevate( int n) const
{
    if(rows == colomns){
        float sum;
        Array Ans;
        Array tmp;
        tmp.setSize(rows, colomns);
        Ans.setSize(rows, colomns);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < colomns; j++){
                 Ans.setValue(i, j, getValue(i, j));
            }
        }
        for( int l = 0; l < (n-1); l++){
            tmp = Ans;
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < colomns; j++){
                    sum = 0;
                    for (int k = 0; k < colomns ; k++){
                        sum += tmp.getValue(i, k)*getValue(k, j);
                        Ans.setValue( i, j, sum);
                    }
                }
            }

        }
     return Ans;
    }
}
