#include "cmpNum.h"
#include <iostream>
using  namespace std;

cmpNum::cmpNum()
{
    real=0;
    imaginary =0;
}
cmpNum::cmpNum(double r,double i)
{
    real=r;
    imaginary =i;
}

cmpNum cmpNum :: operator +(cmpNum a)
{
cmpNum t;
    t.real= real+a.real;
    t.imaginary=imaginary+a.imaginary;

return t;
}
 cmpNum cmpNum::operator++()
    {
        real++;
        imaginary++;
        return *this;
    }
cmpNum cmpNum :: operator *(cmpNum a)
{
cmpNum t;
    t.real= real*a.real-imaginary*a.imaginary;
    t.imaginary=real*a.imaginary+a.real*imaginary;

return t;
}
cmpNum cmpNum::operator /(cmpNum c)
{
cmpNum tmp;
	double div=(c.real*c.real) + (c.imaginary*c.imaginary);
    tmp.real=(real*c.real)+(imaginary*c.imaginary);
    tmp.real/=div;
    tmp.imaginary=(imaginary*c.real)-(real*c.imaginary);
    tmp.imaginary/=div;
return tmp;
}
cmpNum cmpNum :: operator !=(cmpNum a)
{
    cmpNum jury;
    if(real==a.real && imaginary==a.imaginary)
    {
     jury.real=jury.imaginary=1;
    }
    else
    {jury.real=jury.imaginary=0;}
    return jury;
}

 void cmpNum::print(){

 cout<<real <<"+" <<imaginary<<"i "<<endl;


}


