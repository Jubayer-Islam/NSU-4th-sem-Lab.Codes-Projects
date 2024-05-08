#ifndef STACK_H
#define STACK_H
#include"list.h"

template<class T>
class StackLL
{
    public:
        StackLL();
        ~StackLL();
        virtual void push(T value);
        virtual T pop();
        virtual T top();
        virtual bool isEmpty();


    private:
        SinglyLinkedList<T> Is;

};

#endif // STACK_H
