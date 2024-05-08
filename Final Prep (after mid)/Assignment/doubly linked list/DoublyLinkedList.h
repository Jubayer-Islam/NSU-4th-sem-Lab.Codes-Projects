#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

class ListEmpty {};
class PositionOutOfBound {};

template <class T>
struct Dnode {
    T data;
    Dnode <T> *prev, *next;
};

template <class T>
class DoublyLinkedList {
    protected:
        Dnode <T> *head, *tail, *curptr;
        int length;
    public:
        DoublyLinkedList ();
        ~DoublyLinkedList();

        bool IsEmpty ();
        int listSize ();

        void Print ();
        void PrintReverse ();

        int searchFirst (T key);
        int searchLast(T key);

        void insertAtStart (T value);
        void insertAtEnd (T value);

        void deleteStart ();
        void deleteEnd ();

        void deleteValue (T value);
        T getValue (int pos);
        void setValue (int pos, T val);

        bool hasNext ();
        bool hasPrev ();
        T nextItem ();
        T prevItem ();
        void resetAtHead ();
        void resetAtTail();
};

#endif // DOUBLYLINKEDLIST_H
