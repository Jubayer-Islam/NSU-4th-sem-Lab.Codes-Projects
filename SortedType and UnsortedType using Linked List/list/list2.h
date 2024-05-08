#include "list.h"
template <class T>
class UnsortedList:protected SinglyLinkedList<T>
{
public:
    UnsortedList ()
    {

    }

    ~UnsortedList()
    {

    }

    using SinglyLinkedList<T>::isEmpty;
    using SinglyLinkedList<T>::searchItem;
    using SinglyLinkedList<T>::reset;
    using SinglyLinkedList<T>::nextItem;
    using SinglyLinkedList<T>::hasNext;

    virtual void insertItem(T value);
    virtual void deleteItem(T value);


};

template <class T>
class SortedList: public UnsortedList<T>
{
public:
    SortedList() {}
    ~SortedList() {}

    virtual void insertItem(T value);
};


