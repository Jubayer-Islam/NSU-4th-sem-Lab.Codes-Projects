#include "dynarr.h"
#include <iostream>
using namespace std;

dynarr::dynarr()
{
    data = NULL;
    size = 0;
}

dynarr::dynarr(int s)
{
    data = new int[s];
    size = s;
}

dynarr::~dynarr()
{
    delete [] data;
}

void dynarr::allocate(int s)
{
    if(data!=NULL) delete [] data;
    data = new int[s];
    size = s;
}

int dynarr::getValue(int index)
{
    return data[index];
}

void dynarr::setValue(int index, int value)
{
    data[index] = value;
}
