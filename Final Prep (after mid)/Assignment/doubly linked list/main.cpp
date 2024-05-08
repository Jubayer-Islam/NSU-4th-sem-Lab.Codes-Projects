#include <iostream>
#include "DoublyLinkedList.cpp"
using namespace std;

int main()
{
    DoublyLinkedList<int>obj;
    cout<<endl<< "insert 6 elements: "<<endl;
    obj.insertAtStart(14);
    obj.insertAtStart(50);
    obj.insertAtStart(30);
    obj.insertAtStart(47);
    obj.insertAtStart(4700);
    obj.insertAtStart(100);
    obj.resetAtHead();

   cout<<endl<< "print: "<<endl;
    obj.Print();
    obj.PrintReverse();

    cout<<endl<<"After inserting more 4 elements: "<<endl;
    obj.insertAtEnd(77);
    obj.insertAtEnd(99);
    obj.insertAtEnd(47);
    obj.insertAtEnd(10);
    obj.resetAtTail();

    cout<<endl<< "print: "<<endl;
    obj.Print();
    obj.PrintReverse();

    cout<<endl<<"After deleting first and last element: "<<endl;
    obj.deleteStart();
    obj.deleteEnd();

    cout<<endl<<"After deleting value 14: "<<endl;
    obj.deleteValue(14);
    obj.Print();
    obj.PrintReverse();


    cout<<endl<<"value of 3rd position is: "<<obj.getValue(3)<<endl;

    cout<<endl<< "setting value 500 at 3rd position: "<<endl;
    obj.setValue(3,500);

    cout<<endl<< "getting value from 6th position: "<<endl;
        cout<<obj.getValue(6)<<endl;

   cout<<endl<< "print: "<<endl;
    obj.Print();
    obj.PrintReverse();

    cout<<endl<<"trying to delete value 14: "<<endl;
    obj.deleteValue(14);

    cout<<endl<<"searching first and last occurrence of certain values:"<<endl;
    cout<<"searching 47 from first:"<<obj.searchFirst(47)<<endl;
    cout<<"searching 47 from last:"<<obj.searchLast(47);



}
