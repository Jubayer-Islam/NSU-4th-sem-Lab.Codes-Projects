#include"studentinfo.h"
#include<string>
using namespace std;

studentinfo::studentinfo()
{
    id=0;
    name="";
    cgpa=0;
}

studentinfo::studentinfo(int i, string n, float c)
{
    id=i;
    name=n;
    cgpa=c;
}

void studentinfo::setid(int i)
{
    id=i;
}

void studentinfo::setname(string n )
{
    name=n;
}

void studentinfo::setcgpa(float c)
{
    cgpa=c;
}

int studentinfo::getid()
{
    return id;
}

string studentinfo::getname()
{
    return name;
}

float studentinfo::getcgpa()
{
    return cgpa;
}
void studentinfo:: print()
{
    cout << id << " " << name << " " << cgpa << endl;

}
bool operator==(studentinfo  a, studentinfo  b)
{
    if(a.getid()== b.getid())
    {
        return true;
    }
    else {return false;}
}
bool operator!=(studentinfo  a, studentinfo  b)
{
    if(a.getid()!= b.getid())
    {
        return true;
    }
    else {return false;}
}

