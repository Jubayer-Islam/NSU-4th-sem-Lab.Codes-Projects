#include <iostream>
#include "DoublyLinkedList.cpp"
using namespace std;

int main()
{
   DoublyLinkedList<int> obj;

   if(obj.IsEmpty())
   {
       cout<<"empty"<<endl;
   }
   else{ cout<<" not empty"<<endl;}

   cout<<obj.listSize()<<endl;


   //insert

   cout<<"insert 5 items at start:"<<endl;
   int in;
   for(int i=0;i<5;i++)
   {
       cin>>in;
       obj.insertAtStart(in);

   }
   cout<<endl;

    obj.resetAtHead();
    if(obj.IsEmpty())
   {
       cout<<"empty"<<endl;
   }
   else{ cout<<" not empty"<<endl;}


   cout<<"current size="<<obj.listSize()<<endl;
    cout<<"printing First to last"<<endl;
   obj.Print();
   cout<<endl<<"printing last to fast"<<endl;
   obj.PrintReverse();
   cout<<endl;

   //insert again
    cout<<"insert 5 items at end:"<<endl;

   for(int i=0;i<5;i++)
   {
       cin>>in;
       obj.insertAtEnd(in);

   }
   cout<<endl;
    if(obj.IsEmpty())
   {
       cout<<"empty"<<endl;
   }
   else{ cout<<" not empty"<<endl;}

  cout<<"current size="<<obj.listSize()<<endl;
    cout<<"printing First to last"<<endl;
   obj.Print();
   cout<<endl<<"printing last to fast"<<endl;
   obj.PrintReverse();
   cout<<endl;

   cout<<"deleting start,end and user input from list:"<<endl;
   obj.deleteStart();
   obj.deleteEnd();
   obj.Print();
   cout<<endl;

   int dlt;
   cout<<"enter the value user wishes to delete: "<<endl;
   obj.deleteValue(dlt);

   cout<<"Get value from position:"<<endl;
   int pos,val;
   cin>>pos;
   cout<<obj.getValue(pos)<<endl;

    cout<<"enter a position and value to set:"<<endl;
   cin>>pos;
   cin>>val;
   obj.setValue(pos,val);

   cout<<endl<<"search first occurrence:"<<endl;
   int oc;
   cin>>oc;
   obj.searchFirst(oc);
   cout<<"search last occurrence:"<<endl;
    cin>>oc;
   obj.searchLast(oc);



}
