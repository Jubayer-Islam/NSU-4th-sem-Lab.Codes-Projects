#ifndef QUETYPE_H_INCLUDED
#define QUETYPE_H_INCLUDED

class FullQueue
{

};

class EmptyQueue
{

};

template <class ItemType>
class QueType
{
public:
    QueType();
    QueType(int max);
    ~QueType();
    void makeEmpty();
    bool isFull();
    bool isEmpty();
    void Enqueue(ItemType);
    void Dequeue(ItemType&);

private:
    ItemType* items;
    int front;
    int rear;
    int maxQue;

};
#endif // QUETYPE_H_INCLUDED
