#ifndef BP_H_INCLUDED
#define BP_H_INCLUDED

class BinaryPair
{
    private:
    bool x, y;
public:
    BinaryPair(){x=y=0;}
    BinaryPair(bool a, bool b){x = a; y = b;}
    friend BinaryPair operator!(BinaryPair a);
    friend BinaryPair operator*(BinaryPair a, BinaryPair b);
    //if we implement operator * as a member function, then declare:
    //BinaryPair operator*(BinaryPair a);
    friend BinaryPair operator*(bool b, BinaryPair a);
    bool operator<(BinaryPair a);
};


BinaryPair operator*(BinaryPair a, BinaryPair b);
BinaryPair operator!(BinaryPair a);
BinaryPair operator*(bool b, BinaryPair a);

#endif //BP_H_INCLUDED
