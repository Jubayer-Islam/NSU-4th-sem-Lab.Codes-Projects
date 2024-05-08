#include "BP.h"

Coord operator--(Coord &ob)
{
    Coord t;
    t.x=--ob.x;
    t.y=--ob.y;
    return t;
}

//* operator function as friend function
Coord operator-(Coord a, Coord b)
{
    Coord t;
    t.x = a.x - b.x;
    t.y = a.y - b.y;
    return t;
}

/*
//* alt. operator function as member function
Coord Coord::operator-(Coord a)
{
    Coord t;
    t.x = x - a.x;
    t.y = y - a.y;
    return t;
}
*/

Coord operator-(Coord a, int b)
{
    Coord t;
    t.x = b - a.x;
    t.y = b - a.y;
    return t;
}

Coord operator-(int b, Coord a)
{
    Coord t;
    t.x = b - a.x;
    t.y = b - a.y;
    return t;
}
