#include <iostream>

using namespace std;
#include "dynarr.cpp"
#include <iostream>
using namespace std;

int main()
{
    dynArr<int> di(10);
    dynArr<double> dd(10);
    int i;

    for(i=0;i<10;i++)
    {
        di.setValue(i,3*i+1); ///(index,value);
        dd.setValue(i,7.29*i/1.45);
    }
    for(i=0;i<10;i++)
        cout << di.getValue(i) << " " << dd.getValue(i) << endl;

    return 0;
}

