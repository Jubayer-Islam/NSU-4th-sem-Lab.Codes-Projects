#include <iostream>
#include <string>
#include "list.cpp"
#include "stack.cpp"
#include "queue.cpp"
using namespace std;

int main()
{

        //task 1: check palindrome or not

    StackLL <char> sl;
    QueueLL <char> ql;

    string temp;
    cout << "Palindrome check: ";
    cin >> temp;

    for (int i = 0 ; i < temp.size() ; i++)
    {
        sl.push(temp[i]);
        ql.enqueue(temp[i]);
    }

    bool flag = true;
    while(!sl.isEmpty())
    {
        if(sl.pop()!= ql.Dequeue())
        {
            flag = false;
            break;
        }
    }

    cout<< "###Result_check: ";
    if(flag)
    {
        cout << "Palindrome\n";
    }

    else
    {
        cout << "Not Palindrome\n";
    }

    cout<< endl;

        //task 2: check two strings are reverse of each-other or not

    StackLL <char> s2;
    QueueLL <char> q2;

    string str1,str2;
    cout << "Reverse check input two string: ";
    cin >> str1;
    cin >> str2;

    for ( int i = 0 ; i < str1.size() ; i++)
    {
        s2.push(str1[i]);
    }
    for ( int i = 0 ; i < str2.size() ; i++)
    {
        q2.enqueue(str2[i]);
    }


    if(str1.size() != str2.size())
    {
        flag = false ;
    }
    else
    {
        flag = true;
        while(s2.isEmpty()!=true)
        {
            if(s2.pop() != q2.Dequeue())
            {
                flag = false;
                break;
            }
        }
    }

    cout<< "###Result_check: ";
    if(flag==true)
    {
        cout << "Reverse\n";
    }

    else
    {

        cout << " Not Reverse\n";

    }
    cout<< endl;

    return 0;
}
