#ifndef BP_H_INCLUDED
#define BP_H_INCLUDED

class Coord
{
    private:
    int x, y;
public:
    Coord(){x=y=0;}
    Coord(int a, int b){x = a; y = b;}
    friend Coord operator-(Coord a, Coord b);
    //alt function:
    //Coord operator-(Coord a);
    friend Coord operator-(Coord a, int i);
    friend Coord operator-(int i, Coord b);
    friend Coord operator--(Coord &a);
    friend Coord swap(Coord a);
    void print();
};


Coord operator-(Coord a, Coord b);
Coord operator-(Coord a, int i);
Coord operator-(int i, Coord b);
Coord operator--(Coord &a);
Coord swap(Coord a);
#endif //BP_H_INCLUDED
