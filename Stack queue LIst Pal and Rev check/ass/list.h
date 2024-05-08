#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

class ListEmpty
{

};
class PositionOutOfBound
{

};

template <class T>
struct NodeType
{
    T data;
    NodeType *next;
};

template <class T>
class SinglyLinkedList
{
protected:
    NodeType<T> *head, *curptr;
    int length;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    virtual bool isEmpty();
    virtual int listSize();
    virtual void display();
    virtual int searchItem(T);//return position from 1 of key if found, otherwise 0.
    virtual bool hasNext();
    virtual T nextItem();
    virtual void reset();
    virtual void insertAtStart(T value);
    virtual void insertAtEnd(T value);
    virtual void insertAtPosition(T value, int pos);
    virtual void deleteAtStart();
    virtual void deleteAtEnd();
    virtual void deleteAtPosition(int pos);
    virtual T getValue(int pos);
    virtual void setValue(T value,int pos);
};

template<class T>
class SinglyLinkedListWithTail : public SinglyLinkedList<T>
{
protected:
    NodeType<T> *tail;
public:
    SinglyLinkedListWithTail();
    ~SinglyLinkedListWithTail();

    virtual void insertAtStart(T value);
    virtual void insertAtEnd(T value);
    virtual void deleteAtEnd();
};
#endif // LIST_H_INCLUDED
