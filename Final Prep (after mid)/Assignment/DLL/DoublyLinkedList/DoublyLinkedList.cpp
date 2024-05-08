#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head=tail=curptr=NULL;
    length=0;
}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
     while(!IsEmpty())
        deleteStart();
}
template <class T>
bool DoublyLinkedList<T>::IsEmpty()
{
    return length==0;
}
template <class T>
int DoublyLinkedList<T>::listSize (){
    return  length;
}
template<class T>
void DoublyLinkedList<T>::Print()
{
    Dnode <T>*cur=head;


    while(cur!=NULL){
        cout<<" "<<cur->data;
        cur=cur->next;
    }
}
template<class T>
void DoublyLinkedList<T>::PrintReverse (){
    Dnode <T> *temp=new Dnode <T>;
    temp=tail;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}
template <class T>
int DoublyLinkedList<T>::searchFirst (T key){
    resetAtHead();
    for(int i=1;hasNext();i++)
    {
        if(nextItem()==key)
            return i;
    }
    return 0;
}
template <class T>
int DoublyLinkedList<T>::searchLast (T key){
    resetAtTail();
    for(int i=1;hasPrev();i++)
    {
        if(prevItem()==key)
            return i;
    }
    return 0;
}

template <class T>
void DoublyLinkedList<T>::insertAtStart (T value){
    Dnode <T> *newItem=new Dnode <T>;
    Dnode <T> *cur=head;


    if(head==NULL)
    {
        head=newItem;
        newItem->prev=NULL;
        newItem->data=value;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
        cur->prev=newItem;
        newItem->data=value;
        newItem->prev=NULL;
        newItem->next=cur;
        head=newItem;
    }
    length++;
    resetAtHead();
}



template<class T>
void DoublyLinkedList<T>::insertAtEnd(T val){
     Dnode<T> *newItem=new Dnode <T>;
     Dnode<T> *cur=tail;

    if(head == NULL){
       insertAtStart (val);
    }
    else
    {
        cur->next=newItem;
        newItem->data=val;
        newItem->prev=cur;
        tail=newItem;
        newItem->next=NULL;


    }
    length++;
    resetAtTail();
}
template<class T>
void DoublyLinkedList<T>::deleteStart()
{
    if (IsEmpty())
    {
        throw ListEmpty();
    }
    Dnode <T> *temp = head;
    head = head->next;
    delete temp;
    length--;
    curptr = head;

}

template<class T>
void DoublyLinkedList<T>::deleteEnd()
{

    if (IsEmpty())
    {
        throw ListEmpty();
    }
    Dnode <T> *temp = tail;
    tail = tail->prev;
    delete temp;
    length--;


}

template <class T>
void DoublyLinkedList <T> :: deleteValue(T value) {

    Dnode <T> *cur = head;
    Dnode <T> *pre = NULL;

    if (value == head->data) {
        deleteStart();
        curptr = head;
    }

    else if (value == tail ->data) {
        deleteEnd();
        curptr = tail;
    }
    else {
            while (hasNext()) {
            if (cur->data = value) {
                pre ->next = cur ->next;
                curptr = pre->next;
                delete cur;
                return;
            }
            else {
                cur = cur ->next;
            }
        }
    }

    length--;
}


template<class T>
T DoublyLinkedList<T>::getValue(int pos)
{
    if(pos>length || pos<=0)
        throw PositionOutOfBound();

    Dnode<T> *cur=head;
    for(int i=1;i<pos;i++)
        cur=cur->next;
    return cur->data;

}


template<class T>
void DoublyLinkedList<T>::setValue(int pos, T val)
{
    if(pos>length || pos<=0)
        throw PositionOutOfBound();

    Dnode<T> *cur = head;
    for(int i=1;i<pos;i++)
        cur=cur->next;

    cur->data=val;
}

template<class T>
bool DoublyLinkedList<T>::hasNext()
{
   return (curptr!=NULL);
}

template<class T>
bool DoublyLinkedList<T>::hasPrev()
{
    return (curptr!=NULL);
}

template <class T>
T DoublyLinkedList<T>::nextItem()
{
    curptr=curptr->next;
    return curptr->data;

}

template <class T>
T DoublyLinkedList<T>::prevItem()
{

    curptr=curptr->prev;
    return curptr->data;
}

template <class T>
void DoublyLinkedList<T>::resetAtHead()
{
    curptr=head;
}

template <class T>
void DoublyLinkedList<T>::resetAtTail()
{
    curptr=tail;
}

