
#ifndef STUDENTINFO_H_INCLUDED
#define STUDENTINFO_H_INCLUDED

#include<iostream>
using namespace std;
class studentinfo{


public:
     studentinfo();
     studentinfo(int,string,float);
     void setid(int);
     void setname(string);
     void setcgpa(float);
     int getid();
     string getname();
     float getcgpa();
     void print();
     friend bool operator==(studentinfo ,studentinfo);
     friend bool operator!=(studentinfo ,studentinfo);
private:
     int id;
     string name;
     float cgpa;

};

#endif // STUDENTINFO_H
