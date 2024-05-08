#ifndef QUEUE_H
#define QUEUE_H


#include"list.h"

template<class T>
class QueueLL: public SinglyLinkedListWithTail<T>
{
    public:
        QueueLL();
        ~QueueLL();
        virtual void enqueue(T value);
        virtual T Dequeue();
        virtual T frontItem();
        virtual bool isEmpty();


    private:
        SinglyLinkedListWithTail<T> Is;

};


#endif // QUEUE_H
