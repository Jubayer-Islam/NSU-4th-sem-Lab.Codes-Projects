
// C++ program to illustrate concept of dynamic binding
#include <iostream>
using namespace std;

class base{
public:
virtual void funct(){       // Virtual function.
cout<<"This is a base class's function\n";
}
};

class derived1 : public base{
public:
void funct(){     //overridden virtual function.
cout<<"This is a derived1 class's function\n";
}
};

class derived2 : public base{
public:
void funct(){   //overridden virtual function.
cout<<"This is a derived2 class's function\n";
}
};

int main()
{
base *p, b;
derived1 d1;
derived2 d2;
p=&b;

d1.funct();
p->funct(); /**The above statement decides which class's function is to be invoked.
                    but accessing own function is simple */
p=&d1;    // Vlaue of the pointer changes.
p->funct();  /**The above statement decides which class's function is to be invoked.
                    here we can access a function from another class,pretty useful right?*/
p=&d2;     // Again vlaue of the pointer changes.
p->funct();  //The above statement decides which class's function is to be invoked.
 return 0;
}
