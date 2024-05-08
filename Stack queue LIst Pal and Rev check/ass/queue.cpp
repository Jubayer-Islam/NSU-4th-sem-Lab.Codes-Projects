#include "queue.h"


template<class T>
QueueLL<T>::QueueLL()
{

}
template<class T>
QueueLL<T>::~QueueLL()
{

}
template<class T>
void QueueLL<T>::enqueue(T value)
{
    Is.insertAtEnd(value);
}

template<class T>
T QueueLL<T>::Dequeue()
{
    T val=Is.getValue(1);
    Is.deleteAtStart();
    return val;
}

template<class T>
T QueueLL<T>::frontItem()
{
    T val=Is.getValue(1);

    return val;
}

template<class T>
bool QueueLL<T>::isEmpty()
{
    return Is.isEmpty();
}

