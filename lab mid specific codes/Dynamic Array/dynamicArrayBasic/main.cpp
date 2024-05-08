#include "dynarr.cpp"
#include <iostream>
using namespace std;

int main()
{
    dynarr array1(6);
    int i,num;

    for
    (i=0; i<5; i++)
    {

        cin>>num;
        array1.setValue(i,num);
    }
    for(i=0; i<5; i++)
    {
        cout << array1.getValue(i)<<endl;
    }
    return 0;
}
