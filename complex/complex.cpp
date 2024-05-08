#include "Complex.h"
#include <iostream>
using  namespace std;


Complex::Complex()
{

    real=0;
    imaginary =0;
}
Complex::Complex(double r,double i)
{

    real=r;
    imaginary =i;
}
/*
Complex Complex :: operator +(Complex a)
{
Complex t;
    t.real= real+a.real;
    t.imaginary=imaginary+a.imaginary;

    return t;
}
 Complex Complex::operator++()
    {
        real++;
        imaginary++;
       // t++;
        return *this;
    }*/
Complex Complex :: operator *(Complex a)
{
Complex tt;
    tt.real= real*a.real-imaginary*a.imaginary;
    tt.imaginary=real*a.imaginary+a.real*imaginary;

    return tt;
}


 void Complex::print(){

 cout<<real <<"+" <<imaginary<<"i "<<endl;


}

