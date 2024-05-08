#ifndef COMPLEX_H_INCLUDED
#define CO0MPLEX_H_INCLUDED
//friend operator-(Complex,Complex);
//friend operator-(real,Complex);
//friend operator-(Complex,real);
class Complex{

private:
    double real,imaginary;
public:
Complex();
Complex(double , double);
//Complex operator+(Complex);
//Complex operator++();
void print ();
Complex operator*();

};



#endif // COMPLEX_H_INCLUDED
