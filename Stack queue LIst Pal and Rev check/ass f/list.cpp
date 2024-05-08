#include "list.h"
#include <iostream>
using namespace std;

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    cout<<"In SinglyLinkedList Constructor"<<endl;
    head=curptr=NULL;
    length=0;
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    cout<<"In SinglyLinkedList Destructor"<<endl;
    while(!isEmpty())
        deleteAtStart();
}

template <class T>
bool SinglyLinkedList<T>::isEmpty()
{
    return (head==NULL);
}

template <class T>
int SinglyLinkedList<T>::listSize()
{
    return length;
}

template <class T>
bool SinglyLinkedList<T>::hasNext()
{
    return (curptr!=NULL);
}

template <class T>
T SinglyLinkedList<T>::nextItem()
{
    if(isEmpty())
        throw ListEmpty();

    T val = curptr->data;
    curptr=curptr->next;
    return val;
}

template <class T>
void SinglyLinkedList<T>::reset()
{
    curptr=head;
}

template <class T>
void SinglyLinkedList<T>::display()
{
    reset();
    while(hasNext())
        cout<<nextItem()<<" ";
    cout<<endl;
}

template <class T>
void SinglyLinkedList<T>::insertAtStart(T value)
{
    NodeType<T> *temp=new NodeType<T>;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        temp=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    curptr=head;
    length++;
}

template <class T>
void SinglyLinkedList<T>::insertAtEnd(T value)
{
    insertAtPosition(value,length+1);
}

template <class T>
void SinglyLinkedList<T>::insertAtPosition(T value, int pos)
{
    try
    {
        if(pos>length+1 || pos<=0)
            throw PositionOutOfBound();
        if(pos==1)
        {
            insertAtStart(value);
            return;
        }
        else
        {
            NodeType<T> *temp =new NodeType<T>;
            NodeType<T> *cur=head, *pre=NULL;
            for(int i=1;i<pos;i++)
            {
                pre=cur;
                cur=cur->next;
            }
            temp->data=value;
            temp->next=cur;
            pre->next=temp;
            length++;
        }
    }
    catch(PositionOutOfBound p)
    {
        cout<<"Invalid Position"<<endl;
    }
}

template <class T>
int SinglyLinkedList<T>::searchItem(T key)
{
    reset();
    for(int i=1;hasNext();i++)
    {
        if(nextItem()==key)
            return i;
    }
    return 0;
}

template <class T>
void SinglyLinkedList<T>::deleteAtStart()
{
    if(isEmpty())
        throw ListEmpty();
    NodeType<T> *temp=head;
    head=head->next;
    delete temp;
    length--;
    curptr=head;
}

template <class T>
void SinglyLinkedList<T>::deleteAtEnd()
{
    deleteAtPosition(length);
}

template <class T>
void SinglyLinkedList<T>::deleteAtPosition(int pos)
{
    if(isEmpty())
        throw ListEmpty();

    if(pos>length || pos<=0)
        throw PositionOutOfBound();

    if(pos==1)
    {
        deleteAtStart();
        return;
    }

    NodeType<T> *pre,*cur=head;
    for(int i=1;i<pos;i++)
    {
        pre=cur;
        cur=cur->next;
    }

    pre->next=cur->next;
    delete cur;
    length--;
}

template <class T>
T SinglyLinkedList<T>::getValue(int pos)
{
    if(pos>length || pos<=0)
        throw PositionOutOfBound();

    NodeType<T> *cur=head;
    for(int i=1;i<pos;i++)
        cur=cur->next;
    return cur->data;
}

template <class T>
void SinglyLinkedList<T>::setValue(T value,int pos)
{
    if(pos>length || pos<=0)
        throw PositionOutOfBound();

    NodeType<T> *cur = head;
    for(int i=1;i<pos;i++)
        cur=cur->next;

    cur->data=value;
}

template <class T>
SinglyLinkedListWithTail<T>::SinglyLinkedListWithTail()
{
    cout<<"In SinglyLinkedListWithTail constructor"<<endl;
    tail=NULL;
}

template <class T>
SinglyLinkedListWithTail<T>::~SinglyLinkedListWithTail()
{
    cout<<"In SinglyLinkedListWithTail destructor"<<endl;
    tail=NULL;
}

template <class T>
void SinglyLinkedListWithTail<T>::insertAtEnd(T value)
{
    NodeType<T> *temp = new NodeType<T>;
    temp->data=value;
    temp->next=NULL;

    if(this->head==NULL)
    {
        this->curptr=this->head=tail=temp;
        temp=NULL;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
    (this->length)++;
}

template <class T>
void SinglyLinkedListWithTail<T>::insertAtStart(T value)
{
    NodeType<T> *temp = new NodeType<T>;
    temp->data=value;
    temp->next=NULL;
    if(this->head==NULL)
    {
        this->head=tail=temp;
        temp=NULL;
    }
    else
    {
        temp->next=this->head;
        this->head=temp;
    }
    (this->length)++;
    this->curptr=this->head;
}

template <class T>
void SinglyLinkedListWithTail<T>::deleteAtEnd()
{
    if(this->isEmpty())
        throw ListEmpty();
    if(this->length==1)
    {
        this->deleteAtStart();
        return;
    }

    NodeType<T> *pre, *cur=this->head;
    while(cur->next!=NULL)
    {
        pre=cur;
        cur=cur->next;
    }
    tail=pre;
    pre->next=NULL;
    delete cur;
    (this->length)--;
}
