#include <iostream>
#include "cmpNum.cpp"
using namespace std;

int main()
{
    cmpNum A(32,4);
    cmpNum B(8,6);
    cmpNum C;
   C=A+B;
   A.print();
    B.print();
    cout<<"added total :";
    C.print();

    cout<<"after Increment: ";
    ++C;
    C.print();
   //cmpNum d(3,2),e(1,7),f;
   cmpNum d(1,2),e(3,4),f,g;
    f=d*e;
    d.print();
    e.print();
    cout<<"Multiplying two complex numbers: ";
    f.print();
    cout<<"Dividing two complex numbers: ";
    g=d/e;
    g.print();
    cmpNum num1(1,2),num2(1,2),num3;
    num1.print();
    num2.print();
    num3=(num1!=num2);
    cout<<"Note:If equal then returns (1+1i), If not then (0+0i): ";
    num3.print();


}
