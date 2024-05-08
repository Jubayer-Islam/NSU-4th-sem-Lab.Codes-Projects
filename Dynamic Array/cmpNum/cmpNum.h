#ifndef cmpNum_H_INCLUDED
#define CO0MPLEX_H_INCLUDED
//friend operator-(cmpNum,cmpNum);
//friend operator-(real,cmpNum);
//friend operator-(cmpNum,real);
class cmpNum{

private:
    double real,imaginary;

public:
cmpNum();
cmpNum(double , double);
cmpNum operator+(cmpNum);
cmpNum operator++();
cmpNum operator*(cmpNum);
cmpNum operator/(cmpNum);
cmpNum operator!=(cmpNum);
void print ();

};

#endif // cmpNum_H_INCLUDED
