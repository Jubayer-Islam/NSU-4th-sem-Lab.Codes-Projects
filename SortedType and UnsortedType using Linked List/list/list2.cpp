
#include "list2.h"
#include <iostream>
using namespace std;


template <class T>
void UnsortedList<T>::insertItem(T value)
{
   this->insertAtStart(value);
}

template <class T>
void UnsortedList<T>::deleteItem(T value)
{


    if(isEmpty())
    {
        throw ListEmpty();
    }

    if(this->head->data==value)
    {
        this->deleteAtStart();
        return;
    }

     NodeType<T> *pre2=NULL,*cur2=(this->head);
    while ((cur2!=NULL) && (cur2->data!=value))
    {
        pre2=cur2;
        cur2=cur2->next;
    }
    if(cur2!=NULL)
    {
        pre2->next = cur2->next;
        delete cur2;
        (this->length)--;
    }

}

template <class T>
void SortedList<T>::insertItem(T value)
{
        if(this->isEmpty() || value < (this->head)->data)
        {
            this->insertAtStart(value);
        }
        else
        {
            NodeType <T> *temp= new NodeType<T>;
            NodeType <T> *pre=NULL, *cur=(this->head);

            while(cur!=NULL && (cur->data)<value)
            {
                pre=cur;
                cur=cur->next;
            }

            temp->data=value;
            temp->next=cur;
            pre->next=temp;
            (this->length)++;

        }


}
