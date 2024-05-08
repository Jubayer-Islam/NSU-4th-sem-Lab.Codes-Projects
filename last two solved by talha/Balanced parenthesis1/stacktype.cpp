#include "stacktype.h"
#include <iostream>
using namespace std;

template <class ItemType>
stacktype<ItemType>::stacktype(int max)
{
    maxStack = max;
    top=-1;
    items = new ItemType[maxStack];
}

template <class ItemType>
stacktype<ItemType>::stacktype()
{
    maxStack = 500;
    top=-1;
    items = new ItemType[maxStack];
}

template <class ItemType>
stacktype<ItemType>::~stacktype()
{
    delete [] items;
}

template <class ItemType>
bool stacktype<ItemType>::IsFull()
{
    return (top==maxStack-1);
}

template <class ItemType>
bool stacktype<ItemType>::IsEmpty(){
    return (top==-1);

}

template <class ItemType>
void stacktype<ItemType>::MakeEmpty()
{
    top=-1;
}

template <class ItemType>
void stacktype<ItemType>::Push(ItemType newitem)
{
    try{
        if(IsFull()){
        throw FullStack();

        }
    else{
        top++;
        items[top] = newitem;
        }
    }
    catch(FullStack f){
        cout<<"Stack is full"<<endl;
    }
}

template <class ItemType>
void stacktype<ItemType>::Pop()
{   try{
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
ItemType stacktype<ItemType>::Top(){

    return items[top];
}

