#include <iostream>
#include "BP.h"
//#include "pair.cpp"
using namespace std;

int main()
{
    Coord a(5,21), b;
    b = swap(a);//c = operator*(a,b);
    a.print();//prints (5,21)
    b.print();//prints (21,5)
    Coord c = a-b, d = --a;
    //c = operator-(a,b);
    //alt: c = a.opertaor-(b)
    //d = operator--(a);//ob = a;
    c.print();
    d.print();
    a = a-2;//operator-(a,2);
    b = 10-b;//operator-(10,a);
    a.print();
    b.print();
    return 0;
}
