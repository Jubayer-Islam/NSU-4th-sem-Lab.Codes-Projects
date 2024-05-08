#include "quetype.h"


#include <iostream>
using namespace std;

template <class ItemType>
QueType<ItemType>::QueType()
{
    maxQue=501;
    front=maxQue-1;
    rear=maxQue-1;
    items=new ItemType[maxQue];
}

template <class ItemType>
QueType<ItemType>::QueType(int max)
{
    maxQue=max+1;
    front=maxQue-1;
    rear=maxQue-1;
    items=new ItemType[maxQue];
}

template <class ItemType>
QueType<ItemType>::~QueType()
{
    delete [] items;
}

template <class ItemType>
void QueType<ItemType>::makeEmpty()
{
    front=maxQue-1;
    rear=maxQue-1;
}

template <class ItemType>
bool QueType<ItemType>::isFull()
{
    return(front==(rear+1)%maxQue);
}

template <class ItemType>
bool QueType<ItemType>::isEmpty()
{
    return (rear==front);
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{
    try
    {
        if(isFull())
            throw FullQueue();

        else
        {
            rear=(rear+1)%maxQue;
            items[rear]=newItem;
        }
    }
    catch(FullQueue f)
    {
        cout<<"Queue overflow"<<endl;
    }
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
{
    try
    {
        if(isEmpty())
            throw EmptyQueue();

        else
        {
            front=(front+1)%maxQue;
            item=items[front];
        }
    }
    catch(EmptyQueue e)
    {
        cout<<"Queue underflow"<<endl;
    }
}
