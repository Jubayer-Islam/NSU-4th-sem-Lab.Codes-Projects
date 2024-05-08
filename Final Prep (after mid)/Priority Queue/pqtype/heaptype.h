#ifndef HEAPTYPE_H_INCLUDED
#define HEAPTYPE_H_INCLUDED
#include <iostream>
using namespace std;

template<class ItemType>
struct HeapType
{
  void ReheapDown(int root, int bottom);
  void ReheapUp(int root, int bottom);
  ItemType* elements;
  int numElements;
};

#endif // HEAPTYPE_H_INCLUDED

