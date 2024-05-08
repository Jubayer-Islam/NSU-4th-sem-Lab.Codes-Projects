#include <iostream>
#include "binarysearchtree.cpp"

using namespace std;

class Nodenew
{
    public:
    int data;
    Nodenew* left;
    Nodenew* right;
};

Nodenew* newNode(int data)
{

    Nodenew* node = new Nodenew();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;

}

//sorting the sequence, middle element is the root, recursively building left and then right subtree
Nodenew* bestorder(int arr[],int start, int end)
{

    if (start > end)
    return NULL;


    int mid = (start + end)/2;
    Nodenew *root = newNode(arr[mid]);

    root->left = bestorder(arr, start,mid - 1);

    root->right = bestorder(arr, mid + 1, end);

    return root;
}
//prints given tree
void printOrder(Nodenew* node)
{
    if (node == NULL)
        return;
    cout << node->data <<" ";
    printOrder(node->left);
    printOrder(node->right);
}

int main()
{
    TreeType<int> obj;

    if(obj.IsEmpty())
    {
        cout<<"Tree is empty"<<endl;
    }
    else
    {
        cout<<"Tree is not empty"<<endl;
    }


    obj.InsertItem(4);
    obj.InsertItem(9);
    obj.InsertItem(2);
    obj.InsertItem(7);
    obj.InsertItem(3);
    obj.InsertItem(11);
    obj.InsertItem(17);
    obj.InsertItem(0);
    obj.InsertItem(5);
    obj.InsertItem(1);

    if(obj.IsEmpty())
    {
        cout<<"Tree is empty"<<endl;
    }
    else
    {
        cout<<"Tree is not empty"<<endl;
    }
    cout<<"length :"<<obj.LengthIs()<<endl;

    bool x;
    int ret=9;
    obj.RetrieveItem(ret,x);
     if(x)
     {
         cout<<"item is found"<<endl;
     }
     else
     {
         cout<<"item is not found"<<endl;
     }

     ret=13;
   obj.RetrieveItem(ret,x);
     if(x==true)
     {
         cout<<"item is found"<<endl;
     }
     else
     {
         cout<<"item is not found"<<endl;
     }


     obj.ResetTree(IN_ORDER);
    int item=100;
    bool finishedinorder=false;

       while(finishedinorder==false)
       {
            obj.GetNextItem(item,IN_ORDER,finishedinorder);
            cout<<item<<" ";
       }
        cout<<endl;

       bool finishedpre=false;
        obj.ResetTree(PRE_ORDER);
        while(finishedpre==false)
       {
            obj.GetNextItem(item,PRE_ORDER,finishedpre);
            cout<<item<<" ";
       }
       cout<<endl;

        bool finishedpost=false;
        obj.ResetTree(POST_ORDER);
        while(finishedpost==false)
       {
            obj.GetNextItem(item,POST_ORDER,finishedpost);
            cout<<item<<" ";
       }
       cout<<endl;
    obj.MakeEmpty();
    cout<<"current length after making tree empty :"<<obj.LengthIs()<<endl<<endl;

       /**assignment*/
    TreeType <int> obj2;
     obj2.InsertItem(11);
     obj2.InsertItem(9);
     obj2.InsertItem(4);
     obj2.InsertItem(2);
     obj2.InsertItem(7);
     obj2.InsertItem(3);
     obj2.InsertItem(17);
     obj2.InsertItem(0);
     obj2.InsertItem(5);
     obj2.InsertItem(1);

     //creating an array

     int arr[100];
        int i=0,in,item2=100;
        bool finishedinorder2=false;
        obj2.ResetTree(IN_ORDER);


        while(!finishedinorder2)
        {
           obj2.GetNextItem(item2,IN_ORDER,finishedinorder2);
           cout<<item2<<" ";
           arr[i]=item2;
           i++;

        }

        cout<<endl<<"size of array"<<endl;
        int siz =i-1;
        cout<<siz<<endl;



   Nodenew *root = bestorder(arr, 0, siz);
    cout <<"expected output in best order:"<<endl;
    printOrder(root);



}
