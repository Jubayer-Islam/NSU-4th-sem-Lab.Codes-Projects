#include "list.h"

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    cout << "In SinglyLinkedList constructor:  " << endl;
    head = NULL;
    curptr = NULL;
    length = 0;
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    cout << "In SinglyLinkedList destructor:  " << endl;
    while(!isEmpty())
    {
        deleteStart();
    }
}

template <class T>
bool SinglyLinkedList<T>::isEmpty()
{
    return (head == NULL);
}

template <class T>
int SinglyLinkedList<T>::listSize()
{
    return length;
}

template <class T>
void SinglyLinkedList<T>::display()
{
    reset();
    while(hasNext())
    {
        cout << nextItem() << " ";
    }
    cout << endl;
}

template <class T>
void SinglyLinkedList<T>::insertAtStart(T value)
{
    node <T> *temp = new node <T>;
    temp -> data = value;
    temp -> next = NULL;
    if(head == NULL)
    {
        head = temp;
        temp = NULL;
    }
    else
    {
        temp -> next = head;
        head = temp;
    }
    length++;
    curptr = head;
}

template <class T>
void SinglyLinkedList<T>::insertAtPosition(T value, int pos)
{
    if(pos > length+1 || pos <=0)
    {
        throw PositionOutOfBound();
    }
    if (pos ==1)
    {
        insertAtStart(value);
        return;
    }
    node <T> *pre = NULL, *cur = head;
    node <T> *temp = new node <T> ;
    for(int i = 1 ; i < pos ; i++)
    {
        pre = cur ;
        cur = cur -> next;
    }
    temp -> data = value;
    temp -> next = cur;
    pre -> next = temp;
    length++;
}

template <class T>
void SinglyLinkedList<T>::insertAtEnd(T value)
{
    if(isEmpty())
    {
        insertAtStart(value);
        return;
    }
    node <T> *temp = new node <T> ;
    temp -> data = value;
    temp -> next = NULL;
    node <T> *p = head;
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    p->next = temp;
    length++;
}

template <class T>
int SinglyLinkedList<T>::searchItem(T key)
{
    reset();
    for(int i =1 ; i <= length ; i ++)
    {
        if(nextItem() == key)
        {
            return i;
        }
    }
    return 0;
}

template <class T>
void SinglyLinkedList<T>::deleteStart()
{
    if (isEmpty())
    {
        throw ListEmpty();
    }
    node <T> *temp = head;
    head = head->next;
    delete temp;
    length--;
    curptr = head;
}

template <class T>
void SinglyLinkedList<T>::deleteAtPosition(int pos)
{
    if(pos == 1 )
    {
        deleteStart();
        return ;
    }
    if(pos == length)
    {
        deleteEnd();
        return;
    }
    if (pos > length)
    {
        throw PositionOutOfBound();
    }

    node <T> *cur = head,*pre;
    for  (int i = 1; i <pos ; i++)
    {
        pre = cur ;
        cur = cur -> next;
    }
    pre->next = cur -> next;
    delete cur;
    length--;
}

template <class T>
void SinglyLinkedList<T>::deleteEnd()
{
    if(isEmpty())
    {
        throw ListEmpty();
    }
    node <T> *pre = NULL, *cur = head;
    while (cur->next != NULL)
    {
        pre = cur;
        cur = cur->next;
    }
    delete cur;
    if(pre != NULL)
    {
        pre -> next = NULL;
    }
    length--;
}

template <class T>
T SinglyLinkedList<T>::getValue(int pos)
{
    if(pos <=0 || pos > length)
    {
        throw PositionOutOfBound();
    }
    node <T> *cur = head;
    for  (int i = 1; i < pos ; i++)
    {
        cur = cur -> next ;
    }
    return cur -> data;
}

template <class T>
void SinglyLinkedList<T>::setValue(int pos, T val)
{
    insertAtPosition(val,pos);
}

template <class T>
bool SinglyLinkedList<T>::hasNext()
{
    return (curptr != NULL) ;
}

template <class T>
T SinglyLinkedList<T>::nextItem()
{
    T tmp = curptr -> data;
    curptr = curptr -> next;
    return tmp;
}

template <class T>
void SinglyLinkedList<T>::reset()
{
    curptr = head;
}

template <class T>
SinglyLinkedListWithTail<T>::SinglyLinkedListWithTail()
{

}

template <class T>
SinglyLinkedListWithTail<T>::~SinglyLinkedListWithTail()
{

}

template <class T>
void SinglyLinkedListWithTail<T>::insertAtStart(T value)
{

}

template <class T>
void SinglyLinkedListWithTail<T>::insertAtEnd(T value)
{

}

template <class T>
void SinglyLinkedListWithTail<T>::deleteStart()
{

}

template <class T>
void SinglyLinkedListWithTail<T>::deleteEnd()
{

}


