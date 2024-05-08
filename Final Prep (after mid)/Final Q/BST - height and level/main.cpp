#include <iostream>
#include "binarysearchtree.cpp"
using namespace std;




int main()
{
    TreeType<int>obj;
    obj.InsertItem(15);
    obj.InsertItem(10);
    obj.InsertItem(25);
    obj.InsertItem(8);
    obj.InsertItem(12);
    obj.InsertItem(20);
    obj.InsertItem(30);
    obj.InsertItem(6);
    obj.InsertItem(9);
    obj.InsertItem(18);
    obj.InsertItem(22);



    cout<<"total nodes: "<<obj.LengthIs()<<endl;

    int hgt=obj.HeightofBST();
       cout<<"height: "<<hgt<<endl;

     bool flag=false;
    obj.complete(flag);

    if(flag)
    {
        cout<<"complete bst"<<endl;
    }
    else{cout<<"not complete"<<endl;}




}
