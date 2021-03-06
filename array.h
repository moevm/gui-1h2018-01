#ifndef ARRAY_H
#define ARRAY_H


class Array
{
public:
    Array();//constructor
    Array(int n, int m);//constructor
    ~Array();
    int getRows() const;
    int getColomns() const;
    void setSize (int n, int m);
    float getValue (int n, int m) const;
    void setValue (int n, int m, float a);

    //Matrix function
    Array add_up(Array &B) const;
    Array subtruct (Array &B) const;
    Array multiply(Array &B) const;//**
    Array transpose() const;//**
    Array multiply(float c) const;//**
    Array minor( int i, int j) const;
    float det() const;//**
    Array inverse() const;//to do!**
    Array elevate(int n) const;//to do! A^n**
    Array inv_1() const;

private:
    int rows;
    int colomns;
    float Ar[6][6];
};

#endif // ARRAY_H
