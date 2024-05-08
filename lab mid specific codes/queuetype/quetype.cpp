
#include "quetype.h"

template<class ItemType>
QueType<ItemType>::QueType(int max)
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}

template<class ItemType>
QueType<ItemType>::QueType()
{
  maxQue = 501 + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}

template<class ItemType>
QueType<ItemType>::~QueType()
{
  delete [] items;
}

template<class ItemType>
void QueType<ItemType>::MakeEmpty()
{
  front = maxQue - 1;
  rear = maxQue - 1;
}

template<class ItemType>
bool QueType<ItemType>::IsEmpty()
{
  return (rear == front);
}

template<class ItemType>
bool QueType<ItemType>::IsFull()
{
  return ((rear+1)%maxQue == front);
}

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{

     try{
          if (IsFull())
          {
              throw FullQueue();
          }

    rear = (rear +1) % maxQue;
    items[rear] = newItem;
     }
   catch(FullQueue f1)
  {
      cout<<"queue overflow"<<endl;
  }


}

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
{
  try
  {
      if (IsEmpty())
   {
       throw EmptyQueue();

   }
    front = (front + 1) % maxQue;
    item = items[front];

  }
  catch(EmptyQueue f)
  {
      cout<<"queue underflow"<<endl;

  }
}


/**

void print( QueType <int> val)
{
    QueType <int> faux;
    int i,ii,itemin,itemout;

    while(!val.IsEmpty())
    {
        val.Dequeue(itemout);
        i=itemout;
        faux.Enqueue(i);

    }
        val.MakeEmpty();

    while(!faux.IsEmpty())
    {
        faux.Dequeue(ii);
        cout<<ii<<"  ";
       itemin=ii;
        val.Enqueue(itemin);

    }
    faux.MakeEmpty();
    cout<<endl;


}

void PrintBin (int num)
{
    QueType<string> queue_string;
    string s_local;
    string str1,str2;

    queue_string.Enqueue("1");
    queue_string.Dequeue(s_local);

    while (num--)
    {
        str1 = s_local;
        cout << str1 << endl;
        str2 = str1;
        queue_string.Enqueue(str1.append("0"));
        queue_string.Dequeue(s_local);
        queue_string.Enqueue(str2.append("1"));


    }
}


*/
