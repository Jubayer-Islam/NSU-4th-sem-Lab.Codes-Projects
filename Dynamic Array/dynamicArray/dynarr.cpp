

#include "dynarr.h"
#include <iostream>
using namespace std;

template <class T>
dynArr<T>::dynArr()
{
    data = NULL;
    size = 0;
}

template <class T>
dynArr<T>::dynArr(int s)
{
    size = s;
     data = new T[s];
}

template <class T>
dynArr<T>::~dynArr()
{
    delete [] data;
}
template <class T>
void dynArr<T>::allocate(int s)
{
    if(data!=NULL) {delete [] data;}
    data = new T[s];
    size = s;
}

template <class T>
T dynArr<T>::getValue(int index)
{
    return data[index];
}

template <class T>
void dynArr<T>::setValue(int index, T value)
{
    data[index] = value;
}
