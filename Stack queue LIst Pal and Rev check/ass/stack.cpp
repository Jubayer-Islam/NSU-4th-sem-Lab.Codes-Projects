#include "stack.h"
template<class T>
StackLL<T>::StackLL()
{

}
template<class T>
StackLL<T>::~StackLL()
{

}

template<class T>
void StackLL<T>::push(T value)
{
    Is.insertAtStart(value);
}

template<class T>
T StackLL<T>::pop()
{
    //maybe only deletes, pop does not return
    T val=Is.getValue(1);
    Is.deleteAtStart();
    return val;
}

template<class T>
T StackLL<T>::top()
{
    T val = Is.getValue(1);
    return val;
}

template<class T>
bool StackLL<T>::isEmpty()
{
    return Is.isEmpty();
}
