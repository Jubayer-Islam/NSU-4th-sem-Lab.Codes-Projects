#include "BP.h"

BinaryPair operator!(BinaryPair a)
{
    BinaryPair t;
    t.x = !a.x;
    t.y = !a.y;
    return t;
}

bool BinaryPair::operator<(BinaryPair a)
{
    if(x < a.x || (x == a.x && y < a.y))
       return true;
    else return false;
}

//* operator function as friend function
BinaryPair operator*(BinaryPair a,
                                 BinaryPair b)
{
    BinaryPair t;
    t.x = a.x * b.x;
    t.y = a.y * b.y;
    return t;
}

/*
//* operator function as member function
BinaryPair BinaryPair::operator*(BinaryPair a)
{
    BinaryPair t;
    t.x = x * a.x;
    t.y = y * a.y;
    return t;
}
*/

BinaryPair operator*(bool b, BinaryPair a)
{
    BinaryPair t;
    t.x = b * a.x;
    t.y = b * a.y;
    return t;
}
