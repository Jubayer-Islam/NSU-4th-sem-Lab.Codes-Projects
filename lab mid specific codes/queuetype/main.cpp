#include <iostream>
#include "quetype.cpp"
#include "string.h"
using namespace std;


void print( QueType <int> val)
{
    QueType <int> faux;
    int i,ii,itemin,itemout;

    while(!val.IsEmpty())
    {
        val.Dequeue(itemout);
        i=itemout;
        faux.Enqueue(i);

    }
        val.MakeEmpty();

    while(!faux.IsEmpty())
    {
        faux.Dequeue(ii);
        cout<<ii<<"  ";
       itemin=ii;
        val.Enqueue(itemin);

    }
    faux.MakeEmpty();
    cout<<endl;


}

void PrintBin (int num)
{
    QueType<string> queue_string;
    string s_local;
    string str1,str2;

    queue_string.Enqueue("1");
    queue_string.Dequeue(s_local);

    while (num--)
    {
        str1 = s_local;
        cout << str1 << endl;
        str2 = str1;
        queue_string.Enqueue(str1.append("0"));
        queue_string.Dequeue(s_local);
        queue_string.Enqueue(str2.append("1"));


    }
}


/*
 //alternative
void PrintBinary(int n)
{   cout<<endl<<"The Binary number from 0 to "<<n<<" : "<<endl;
    string temp;

    QueType<string> q;

    q.Enqueue("1");

    while (n!=0)
    {
        q.Dequeue(temp);
        string s1 = temp;
        cout << temp << "\n";

        string s2 = s1;

        q.Enqueue(s1.append("0"));
        q.Enqueue(s2.append("1"));
        n--;
    }
}
*/

int main()
{
       QueType <int> q1(5);
       int num;

    cout<<"check queue empty or not:"<<endl;
    if(q1.IsEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    cout<<"Insert 4 items:"<<endl;
    for(int j=0; j<4; j++)
    {
        cin>>num;
        q1.Enqueue(num);
    }

    cout<<"check queue empty or not:"<<endl;
    if(q1.IsEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    cout<<"check queue full or not:"<<endl;
    if(q1.IsFull())
    {
        cout<<"FULL"<<endl;
    }
    else {cout<<"NOT FULL"<<endl;}

     cout<<"printing after enqueueing another item:"<<endl;
    q1.Enqueue(6);
    print(q1);

    cout<<"check queue full or not:"<<endl;
    if(q1.IsFull())
    {
        cout<<"FULL"<<endl;
    }
    else {cout<<"NOT FULL"<<endl;}

    cout<<"enqueue 1 item(if possible):"<<endl;
    q1.Enqueue(8);

    cout<<"dequeue 2 items and print:"<<endl;
    int d=0;
    q1.Dequeue(d); // d has the last dequeued value
    q1.Dequeue(d);
     print(q1);

    cout<<"dequeue 3 items:"<<endl;
    q1.Dequeue(d);
    q1.Dequeue(d);
    q1.Dequeue(d);


        cout<<"check queue empty or not:"<<endl;
    if(q1.IsEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    cout<<"dequeue another item(if remains):"<<endl;
    q1.Dequeue(d);

    cout<<endl<<"Printing binary numbers:"<<endl;

    PrintBin(10);
    cout<<endl<<" *Done* "<<endl;




    return 0;
}
