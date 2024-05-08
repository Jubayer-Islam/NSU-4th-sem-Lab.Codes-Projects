
/** Using pointers*/
#include<iostream>
using namespace std;
void swap(int*addr1, int*addr2); //void swap(int*, int*);
int main()
{
int a=10,b=15;
cout << a << "," << b << endl;
swap(&a,&b);
cout<<a<<","<<b<< "\n";
return 0;
}
 void swap(int *addr1,int *addr2)
{
    int temp;
    temp=*addr1;
    *addr1=*addr2;
    *addr2=temp;
}


/** Without pointers, using reference */
/*
#include <iostream>
using namespace std;

// Function prototype
void swap(int&, int&);

int main()
{
    int a = 1, b = 2;
    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap(a, b);

    cout << "\nAfter swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

void swap(int& n1, int& n2) {
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}
*/

