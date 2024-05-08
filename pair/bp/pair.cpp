#include "pair.h"

template<class T>
Pair<T> Pair<T>::operator+(Pair<T> a)
{
    Pair<T> t;
    t.x = x+a.x;
    t.y = y+a.y;
    return t;
}
