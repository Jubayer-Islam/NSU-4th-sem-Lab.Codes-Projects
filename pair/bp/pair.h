#ifndef PAIR_H_INCLUDED
#define PAIR_H_INCLUDED

template<class T>
class Pair
{
    T x, y;
public:
    Pair(){x=y=0;}
    Pair(T a, T b){x = a; y = b;}
    Pair<T> operator+(Pair<T> a);
//    bool operator<(Pair<T> a);
};

#endif //PAIR_H_INCLUDED

