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
    return (length==0);
}
template <class T>
int DoublyLinkedList<T>::listSize (){
    return  length;
}
template<class T>
void DoublyLinkedList<T>::Print(){
    cout<<"Printing elements first to last: ";
    Dnode <T>*cur=head;


    while(cur!=NULL){

        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
}
template<class T>
void DoublyLinkedList<T>::PrintReverse (){
    cout<<"Printing elements last to first: ";
    Dnode <T> *temp=tail;

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

   int j=1;
   while (hasNext()==true)
   {
     if(nextItem()==key)
     {
         return j;
     }
     else{j++;}
   }
   return 0;
}
template <class T>
int DoublyLinkedList<T>::searchLast (T key){
    resetAtTail();
    int i=1;
    while (hasPrev()) {
        if (prevItem()==key) {
            return i;
        }
        else {
            i++;
        }
    }
    return 0;
}
template <class T>
void DoublyLinkedList<T>::insertAtStart (T value){
    Dnode <T> *newItem=new Dnode <T>;
    if(head==NULL){
        head=newItem;
        newItem->prev=NULL;
        newItem->data=value;
        newItem->next=NULL;
        tail=newItem;
    }
    else{
        newItem->next=head;
        newItem->data=value;
        newItem->prev=NULL;
        head->prev=newItem;
        head=newItem;
    }
    length++;
    resetAtHead();
}
template <class T>
void DoublyLinkedList<T>::insertAtEnd (T value){
    Dnode <T> *newItem=new Dnode <T>;
    newItem->data=value;
    if(head==NULL){
        head=newItem;
        newItem->prev=NULL;
        newItem->next=NULL;
        tail=newItem;
    }
    else{
        newItem->prev=tail;
        tail->next=newItem;
        newItem->next=NULL;
        tail=newItem;
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
    else{
        if(head==tail)
        {
            Dnode<T>* cur;
            cur=head;
            head=NULL;
            tail=NULL;
            delete cur;
            return;
        }
        else{
            Dnode<T>* cur;
            cur=head;
            head=head->next;
            head->prev=NULL;
            delete cur;
        }
    }
    length--;
    curptr = head;

}

template<class T>
void DoublyLinkedList<T>::deleteEnd()
{
    if (IsEmpty()){
        throw ListEmpty();
    }
    else{
        if(head==tail){

            delete head;
            return;
        }
        else{
            Dnode<T>* cur;
            cur=tail;
            tail=tail->prev;
            tail->next=NULL;
            delete cur;
        }
    }
    length--;
    curptr = tail;
}

template <class T>
void DoublyLinkedList <T> :: deleteValue(T value) {

    Dnode <T> *cur = head;
    Dnode <T> *pre = NULL;

    if (value == head->data) {
        deleteStart();
        curptr = head;
    }

    else if (value == tail->data) {
        deleteEnd();
        curptr = tail;
    }

    while (cur->data != value) {
        pre=cur;
        cur=cur->next;
        if(cur==NULL)
            {
            cout<<"Element could not be found"<<endl;
            return;
            }
    }
    cur->next->prev = cur ->prev;
    cur->prev->next= cur ->next;
    delete cur;

    length--;
}


template<class T>
T DoublyLinkedList<T>::getValue(int pos)
{
    if(pos>length || pos<=0)
        throw PositionOutOfBound();

    Dnode<T> *cur=head;
    for(int i=1;i<pos;i++)
        {cur=cur->next;}
    return cur->data;

}


template<class T>
void DoublyLinkedList<T>::setValue(int pos, T val)
{
    if(pos<=0 ||pos>length)
    throw PositionOutOfBound();

    else{
    Dnode<T>*cur=head;
    for(int i=1;i<pos;i++){
        cur=cur->next;
    }
    cur->data=val;
    }
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

     T k=curptr->data;
    curptr=curptr->next;
    return k;


}

template <class T>
T DoublyLinkedList<T>::prevItem()
{

    T k=curptr->data;
    curptr=curptr->prev;
    return k;

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
