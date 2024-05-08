#include<iostream>
using namespace std;

int main()
{
    int a = 5, b = 9;
    int *p;
    p = &a;

    cout << a << ", " << *p << ", " << b << "\n";
    *p = 100;
    cout << a << ", " << *p << ", " << b << endl;
    p = &b;
    cout << a << ", " << *p << ", " << b << endl;
    *p = a+10;
    cout << a << ", " << *p << ", " << b << endl;
    int aa[10]={10,20,30,40,50,60,70,80};
    int *ptr;

    ptr=&aa[2];
    ptr=ptr+2;
    ptr=ptr+1;
    cout<<">>>>"<<*ptr;

    return 0;
}
