#include "SinglyLinkedList.h"
//#include "list.h"

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    cout<<"In SinglyLinkedList Constructor"<<endl;
    head=curptr=NULL;length=0;
}
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
     cout<<"In SinglyLinkedList Destructor"<<endl;
    while(!isEmpty())
    {
        deleteStart();
    }
}
template <class T>
bool SinglyLinkedList<T>::isEmpty()
{
  {return head==NULL;}
}
template <class T>
int SinglyLinkedList<T>::listSize()
{
  {return length;}
}
/*template <class T>
int SinglyLinkedList<T>::display()
{



}*/

template <class T>
void SinglyLinkedList<T>::insertAtStart(T value)
{
  node <T> *temp=new node<T>;
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
  length++;
  curptr=head;

}

template <class T>
void SinglyLinkedList<T>::insertAtPosition(T value,int pos)
{

  if(pos>(length+1) || pos<=0)
  {
      throw PositionOutOfBound();
  }
  if(pos==length+1)
  {
      insertAtEnd(value);
  }
   if(pos==1)
  {
      insertAtStart(value);
  }
  node <T> *pre,*cur;
  node <T> *temp=new node<T>;
    cur=head;
    for(int i=0;i<pos;i++)
    {
        pre=cur;
        cur=cur->next;
    }
    temp->data=value;
    temp->next=cur;
    pre->next=temp;
    length++;



}
template <class T>
void SinglyLinkedList<T>::insertAtEnd(T value)
{
    if(isEmpty())
    {
        insertAtStart(value);
    }
    else
    {

        node <T> *temp=new node<T>;
        temp->data=value;
        temp->next=NULL;

        node <T> *p=head;

        while (p->next!=NULL)
        {
            p=p->next;
            p->next=temp;
        }

    }
}
template <class T>
int SinglyLinkedList<T>::searchItem(T key)
{
      node  <T> *cur=head;
    node <T> *pre=NULL;
    node  <T> *cur=head;
    while(cur->!=NULL)
    {
        pre=cur;
        cur=cur->next;
        if(key==cur->data)
        {
            return pre->next;

        }
    }


}

template <class T>
void SinglyLinkedList<T>::deleteStart()
{
    if(isEmpty())
    {
        throw ListEmpty();
    }
    node <T> *temp=head;
    head=head->next;
    delete temp;
    length--;
    curptr=head;



}
/*template <class T>
void SinglyLinkedList<T>::deleteAtPosition(int pos)
*/
template <class T>
void SinglyLinkedList<T>::deleteEnd()
{
    node  <T> *cur=head;
    node <T> *pre=NULL;
    while(cur->next!=NULL)
    {
        pre=cur;
        cur=cur->next;
    }
    delete cur;
    if(pre!=NULL)
    {
        pre->next=NULL;
    }
    length--;
}
template <class T>
T SinglyLinkedList<T>::getValue(int pos)
{




}
void SinglyLinkedList<T>::setValue(int pos,T value)
{





}

