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

    try {
        if( IsFull() )
            {throw FullStack();}
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
    try{
        if(IsEmpty()){
        throw EmptyStack();
        }
        else
        {
        top--;
        }
    }
    catch(EmptyStack e){
        cout<<"Stack is empty"<<endl;
    }
}
template <class ItemType>
ItemType stacktype<ItemType>::Top()
{
    if (IsEmpty())
        {throw EmptyStack();}
    return items[top];
}

/**
    useful functions


void print(stacktype<int>st)

{
    for(int i=0; i<MAX_ITEMS; i++)
    {

        if(st.IsEmpty()==true)
        {

            break;
        }
        else
        {
            faux.Push(st.Top());

            st.Pop();
        }
    }

     cout<< "stack values:"<<endl;
    for(int i=0; i<MAX_ITEMS; i++)
    {


        if(faux.IsEmpty()==true)
        {
            break;

        }

        else
        {
            cout<<faux.Top()<<" ";
            st.Push(faux.Top());

            faux.Pop();
        }
    }
    cout<<endl;

}
bool isBalanced(string s)

{
    stacktype<char>st2;
    for (int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            st2.Push('(');
        }

        else if(s[i]==')')
        {
            if(st2.IsEmpty())
            {
                return false;
            }
            else
            {
               st2.Pop();
            }
        }
    }
    if(st2.IsEmpty())
    {
        return true;
    }
    else {return false;}

}

*/
