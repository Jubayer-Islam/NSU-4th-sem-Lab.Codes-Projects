#include <iostream>
#include <string>
#include "list.cpp"
#include "list2.cpp"

using namespace std;

int main()
{
    UnsortedList <string> ls;

    string str1,del;
    int num;

    cin>>num;

    for(int i=0;i<num;i++)
    {
        cout<<"insert a string: ";
        cin>>str1;
        ls.insertItem(str1);

    }
    cout<<endl<<"displaying inserted strings: "<<endl;
    while(ls.hasNext())
    {
        cout<<ls.nextItem()<<" ";
    }

    cout<<endl<<"enter another string that shall be deleted: ";
    cin>>del;

     ls.reset();
      ls.deleteItem(del);
     ls.reset();
     cout<<endl<<"displaying current strings: "<<endl;
    while(ls.hasNext())
    {
        cout<<ls.nextItem()<<" ";
    }
    cout<<endl;
    ls.reset();

    SortedList<string>lt;

    while(ls.hasNext())
    {
        lt.insertItem(ls.nextItem());
    }
    lt.reset();

     cout<<endl<<"displaying current strings: "<<endl;
    while(lt.hasNext())
    {
        cout<<lt.nextItem()<<" ";
    }
    cout<<endl;



}
