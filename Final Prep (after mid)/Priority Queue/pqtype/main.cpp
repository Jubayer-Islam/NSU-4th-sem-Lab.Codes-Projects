#include <iostream>
#include "pqtype.cpp"

using namespace std;

void magicbag(int min)
{
        PQType<int>bags(10);
        bags.Enqueue(2);
        bags.Enqueue(1);
        bags.Enqueue(7);
        bags.Enqueue(4);
        bags.Enqueue(2);
        int chocolates,eaten=0;

  while(min>0)
  {
        bags.Dequeue(chocolates);
        eaten=eaten+chocolates;
        bags.Enqueue(chocolates/2); //reenquing half of eaten chocos
        min--;
  }
  cout<<"total eaten:"<<eaten<<endl;
}


int main()
{
    PQType <int> obj(15);

    if(obj.IsEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue is not empty"<<endl;
    }


    cout<<endl<<"Inserting 10 items"<<endl;

    obj.Enqueue(4);
    obj.Enqueue(9);
    obj.Enqueue(2);
    obj.Enqueue(7);
    obj.Enqueue(3);
    obj.Enqueue(11);
    obj.Enqueue(17);
    obj.Enqueue(0);
    obj.Enqueue(5);
    obj.Enqueue(1);
    cout<<endl;

     if(obj.IsEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue is not empty"<<endl<<endl;
    }

    cout<<"Dequeue: ";
    int item;
    obj.Dequeue(item);
    cout<<item<<endl;

     cout<<"Dequeue: ";
    obj.Dequeue(item);
    cout<<item<<endl;

    cout<<"entering 3 minutes left for monks and chocolates problem:"<<endl;
    magicbag(3);


}
