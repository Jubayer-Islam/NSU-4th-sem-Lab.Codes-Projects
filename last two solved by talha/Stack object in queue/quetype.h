#ifndef QUETYPE_H_INCLUDED
#define QUETYPE_H_INCLUDED
#include "stacktype.h"
class FullQueue
{};
class EmptyQueue
{};

template<class ItemType>
class QueType {

protected:
    stacktype<ItemType>ob;
public:
QueType();
QueType(int max);
~QueType();
virtual void MakeEmpty();

virtual bool IsEmpty();
virtual bool IsFull();

virtual void Enqueue(ItemType);
virtual void Dequeue(ItemType&);

private:

int front;
int rear;
ItemType* items;
int maxQue;
};

#endif // QUETYPE_H_INCLUDED

