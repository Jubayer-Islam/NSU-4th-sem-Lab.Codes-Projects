#include "stacktype.h"
using namespace std;
#include <iostream>

template <class ItemType>

stacktype<ItemType>::stacktype()
{
    top = -1;
}
template <class ItemType>
bool stacktype<ItemType>::IsEmpty()
{
    return ((top == -1)==true);     //returns true(1) if empty
}

template <class ItemType>
bool stacktype<ItemType>::IsFull()
{
    return (top ==  MAX_ITEMS-1);       //returns true if full
}
template <class ItemType>
void stacktype<ItemType>::Push(ItemType newItem)
{

    try{
    if( IsFull() )
            throw FullStack();
        top++;
        items[top] = newItem;
        }
       catch(FullStack)
        {
            cout<<endl<<"can not insert any more items"<<endl;
        }


}
template <class ItemType>
void stacktype<ItemType>::Pop()
{
    if( IsEmpty() )
        throw EmptyStack();
    top--;
}
template <class ItemType>
ItemType stacktype<ItemType>::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    return items[top];
}

/**
 int calculate (string s)
    {

        int nm1,nm2;
        stacktype<char> cal;

        for (int i=0;i<s.length();i++)
        {


            if(s[i]>=48 && s[i]<=57)
            {
                cal.Push(s[i]-'0');
            }
            else if(s[i]>=42 && s[i]<=47)
            {
                nm2=cal.Top();
                cal.Pop();
                nm1=cal.Top();
                cal.Pop();

            switch (s[i]) {

            case '+': cal.Push(nm1+nm2);
            break;
            case '-': cal.Push(nm1-nm2);
            break;
            case '*': cal.Push(nm1*nm2);
            break;
            case '/': cal.Push(nm1/nm2);
            break;

                }
            }

        }

        return cal.Top();


    }
*/
