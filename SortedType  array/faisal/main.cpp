#include <iostream>
#include "sortedtype.cpp"
#include "timeStamp.cpp"
using namespace std;

int main()
{
    int temp;
    bool found;
    SortedType <int> sl;
    cout <<"length=" << sl.LengthIs() <<endl;

    for(int i = 0 ; i < 5  ; i++)
    {
        cin >> temp ;
        sl.InsertItem(temp);
    }

    //print the list
    for(int i = 0 ; i < sl.LengthIs()  ; i++)
    {
        sl.GetNextItem(temp);
        cout << temp << " ";
    }
    sl.ResetList();
    cout << endl;

    //retrieve 6 and print
    temp = 6;
    sl.RetrieveItem(temp,found);
    if(found)
    {
        cout << "Item is found" <<endl;
    }
    else
    {
        cout << "Item is not found" <<endl;
    }

    //retrieve 5 and print
    temp = 5;
    sl.RetrieveItem(temp,found);
    if(found)
    {
        cout << "Item is found" <<endl;
    }
    else
    {
        cout << "Item is not found" <<endl;
    }

    //print list full or not
    if(sl.IsFull())
    {
        cout << "List is full" << endl;
    }
    else
    {
        cout << "List is not full" << endl;
    }

    //delete 1
    sl.DeleteItem(1);

    //print the list
    for(int i = 0 ; i < sl.LengthIs()  ; i++)
    {
        sl.GetNextItem(temp);
        cout << temp << " ";
    }
    sl.ResetList();
    cout << endl;

    //print list full or not
    if(sl.IsFull())
    {
        cout << "List is full" << endl;
    }
    else
    {
        cout << "List is not full" << endl;
    }

     cout<<"this timeStamp(25,36,17) must be present and deleted:"<<endl;
   //create list for timeStamp
    TimeStamp tmp;
    int h,m,s;
    SortedType <TimeStamp> ts ;

    for(int i = 0 ; i < 5  ; i++)
    {
        cin >> h >> m >> s ;
        tmp.setHour(h);
        tmp.setMinute(m);
        tmp.setSecond(s);
        ts.InsertItem(tmp);
    }

    //delete timeStamp

    tmp.setHour(25);
    tmp.setMinute(36);
    tmp.setSecond(17);
    ts.DeleteItem(tmp);

    //print list
    for(int i = 0 ; i < ts.LengthIs() ; i++)
    {
        ts.GetNextItem(tmp);
        tmp.Print();
    }
    ts.ResetList();

//overload operations - check equal or not
cout<<endl<<"checking the two timeStamps equal or not:"<<endl;
   TimeStamp tmp1,tmp2;
    tmp1.setHour(15);
    tmp1.setMinute(34);
    tmp1.setSecond(23);
     tmp1.Print();
    tmp2.setHour(52);
    tmp2.setMinute(02);
    tmp2.setSecond(20);
     tmp2.Print();
     cout<<"answer= ";

   if(tmp1!=tmp2)
   {
       cout<<"not same"<<endl;
   }
   else
   {
       cout<<"same"<<endl;
   }
   //overload operations - check greater or not
    cout<<endl<<"greater or not: "<<endl;

     tmp1.Print();
     tmp2.Print();
     cout<<"answer= ";
     if(tmp1>tmp2)
     {
         cout<<"1st time stamp is greater"<<endl;
     }
     else{
        cout<<"1st time stamp is not greater"<<endl;
     }

    return 0;
}
