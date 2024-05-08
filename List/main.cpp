#include <iostream>
#include "list.cpp"
using namespace std;

int main()
{
     SinglyLinkedList <int> sl;
    int val,pos;
    cin >> val >> pos;

    while (pos != 0)
    {
        sl.insertAtPosition(val,pos);
       cout<<"Current values:"<<endl;
        sl.display();
        cin >> val >> pos;
    }

    sl.reset();
    while (sl.hasNext())
    {
        cout<< sl.nextItem() << " " ;
    }
    cout << endl;



    cout << "Input the value which will be deleted: ";
    cin >> val ;
    pos = sl.searchItem(val);
    sl.deleteAtPosition(pos);
   cout<<"current values are:"<<endl;
    sl.display();
    cout <<"Input value which will replace the deleted value: ";
    cin >> val ;
    sl.setValue(pos,val); //it will replace the recently deleted value

   cout<<"current values are:"<<endl;
    sl.display();
    return 0;
}
