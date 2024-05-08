#include <iostream>
#include "BP.h"
#include "pair.cpp"
using namespace std;

int main()
{
    BinaryPair a(0,1), b(1,0), c;
    c = a*b;//c = a.operator*(b);
    BinaryPair d = !c;
    bool w; cin>>w;
    BinaryPair q = w*d;//q = operator*(w,d)
    if(q<a) cout << "Less";

    Pair<int> p(2,3), r(3,4), t = p+r;
    Pair<int> u(1.2,3.5), v(3.4,4.8), tt = u+v;
    return 0;
}
