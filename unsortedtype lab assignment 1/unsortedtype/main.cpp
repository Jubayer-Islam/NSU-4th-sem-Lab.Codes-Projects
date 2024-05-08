#include <iostream>
#include "unsortedtype.cpp"
//#include "unsortedtype.h"
#include "studentinfo.cpp"


using namespace std;

int main()
{
   unsortedtype<int> obj;

    //inserting elements

    obj.insertItem(5);
    obj.insertItem(7);
    obj.insertItem(6);
    obj.insertItem(9);

    int item;
    bool x;

    //printing the list
    cout<<"list=";
    for(int i=0; i<obj.lengthIs(); i++)
    {
        obj.getNextItem(item);
        cout<<" "<<item;
    }

    //length of the list
    cout<<endl<<"Length ="<<obj.lengthIs()<<endl;

     //one item inserted
    obj.insertItem(1);


    //printing the list
     obj.resetList();
    cout<<"list=";
    for(int i=0;i<obj.lengthIs();i++)
    {
        obj.getNextItem(item);
        cout<<" "<<item;
    }
    cout<<endl;

    //retrieving the items
    cout<<endl<<"Retrieve item 4"<<endl;
    item=4;

    obj.retrieveItem(item,x);
    if(x)cout<<endl<<"item found."<<endl;
    else cout<< endl<<"item not found."<<endl;

    //retrieving the items
    cout<<endl<<"Retrieve item 5"<<endl;
    item=5;

    obj.retrieveItem(item,x);
    if(x)cout<<endl<<"item found."<<endl;
    else cout<< endl<<"item not found."<<endl;

    //retrieving the items
    cout<<endl<<"Retrieve item 9"<<endl;
    item=9;

    obj.retrieveItem(item,x);
    if(x)cout<<endl<<"item found."<<endl;
    else cout<<endl<< "item not found."<<endl;

    //retrieving the items
    cout<<endl<<"Retrieve item 10"<<endl;
    item=10;

    obj.retrieveItem(item,x);
    if(x)cout<<endl<<"item found."<<endl;
    else cout<<endl<< "item not found."<<endl;

    cout<<endl;

    //list full or not check
     if(obj.isFull())
    {
        cout << "List is full" << endl;
    }
    else
    {
        cout << "List is not full" << endl;
    }
    cout<<endl;

    obj.deleteItem(5);
     cout<<"5 is deleted."<<endl;

     //list full or not check
    if(obj.isFull())
    {
        cout << "List is full" << endl;
    }
    else
    {
        cout << "List is not full" << endl;
    }
    cout<<endl;

    obj.deleteItem(1);
    cout<<"1 is deleted."<<endl;



    cout<<"list=";
    obj.resetList();
    for(int i=0;i<obj.lengthIs();i++)
    {
        obj.getNextItem(item);
        cout<<item<<" ";
    }
    cout<<endl;

    obj.deleteItem(6);
    cout<<"6 is deleted."<<endl;



    cout<<"list=";
    obj.resetList();
    for(int i=0;i<obj.lengthIs();i++)
    {
        obj.getNextItem(item);
        cout<<" "<<item;
    }



    cout<<endl;

    cout<<"Student info: enter 5 student's informations respectively."<<endl;

     bool found;
    unsortedtype <studentinfo> si;
    studentinfo tmp;
    int tmpId;
    string tmpName;
    float tmpCgpa;

    for( int i = 0; i < 5 ; i++)
    {
        cin >> tmpId >> tmpName >> tmpCgpa;
        tmp.setid(tmpId);
        tmp.setname(tmpName);
        tmp.setcgpa(tmpCgpa);
        si.insertItem(tmp);
    }
    si.resetList();

    //delete the record id 15467
    int dlt;
    cout<<"enter the person's id whose data must be removed:";
    cin>>dlt;
    tmpId = dlt;

    for(int i=0 ; i < si.lengthIs() ; i++)
    {
        si.getNextItem(tmp);
        if(tmp.getid() == tmpId)
        {
            si.deleteItem(tmp);
        }
    }
    si.resetList();

    //retrieve item 13569 and print record
    int ret;
    cout<<"enter the person's id whose data must be retrieved:";
    cin>>ret;
    tmpId = ret;
    found = false;

    for( int i=0 ; i < si.lengthIs() ; i++)
    {

        si.getNextItem(tmp);
        if(tmp.getid() == tmpId)
        {
            cout << "Item is found" <<endl;
            tmp.print();
            found = true;
            break;
        }
    }
     if(!found)
    {
        cout << "Item is not found"<<endl;
    }
    si.resetList();
    cout<<endl;

    //print the list
    cout<<"the full list:"<<endl;
    for(int i=0 ; i < si.lengthIs() ; i++)
    {
        si.getNextItem(tmp);
        tmp.print();
    }
    si.resetList();


    return 0;
}
