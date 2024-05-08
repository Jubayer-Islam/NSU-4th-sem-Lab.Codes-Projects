#include <iostream>
#include "UnsortedType.cpp"

using namespace std;

int main()
{
    int n1,n2;
    UnsortedType<int> obj,obj2;

    //take input of two objects, 5 elements each

     cout<<" enter 1st array elements :"<<endl;
    for(int i=0;i<5;i++)
    {
       cin>>n1;
        obj.InsertItem(n1);
    }
        obj.ResetList();

        cout<<"enter 2nd array elements:"<<endl;

    for(int i=0;i<5;i++)
    {
       cin>>n2;
        obj2.InsertItem(n2);
    }
        obj2.ResetList();


            //printing arrays before any changes are made

    int item;
    bool x;
        cout<<" 1st array list without changes =";
    for(int i=0;i<obj.LengthIs();i++)
    {
    obj.GetNextItem(item);
        cout<<" "<<item;
    }
    cout<<endl;
    obj.ResetList();


        cout<<" 2nd array list without changes =";
    for(int i=0;i<obj.LengthIs();i++)
    {
    obj2.GetNextItem(item);
        cout<<" "<<item;
    }
    cout<<endl;
    obj2.ResetList();


    /** YESTERDAY'S LAB WORK- MAXIMUM & AVERAGE OF 1ST ARRAY ELEMENTS */

    int temp,maximum;
    obj.GetNextItem(maximum); //now 1st element is considered maximum

    // now we'll run loop 4 times, as the ResetList was not used;
     //get next item is considering from the 1th element to 4th ,not 0th to 4th because it was already called once

    for(int i=1; i<obj.LengthIs(); i++)
    {
        obj.GetNextItem(temp);

        if(temp>  maximum)
        {
            maximum=temp;
        }
    }
    obj.ResetList();
        cout<<"max of 1st array:"<<maximum<<endl;

    double total=0.0,avg=0.0;
    for(int i=0; i<obj.LengthIs(); i++)
    {
        obj.GetNextItem(temp);
        total=total+temp;
    }
    avg=total/obj.LengthIs();
    obj.ResetList();
        cout<<"average of 1st array:"<<avg<<endl;



    /** NEW ASSIGNMENT- REMOVING DUPLICATE VALUES FROM BOTH ARRAYS AND PRINTING THEM */


    int temp1,temp2,temp3,temp4;
    cout << "Duplicate items in 1st array are : ";

    START1:

    for(int i = 1 ; i <= obj.LengthIs(); i++)
    {
        for(int k = 1; k <=i ; k++)
        {
            obj.GetNextItem(temp1);
        }
        for(int j = 0; j < obj.LengthIs()-i; j++)
        {
            obj.GetNextItem(temp2);
            if(temp1 == temp2)
            {
                obj.DeleteItem(temp1);
                cout << temp1 << " " ;
                obj.ResetList();
                goto START1;
            }
        }
        obj.ResetList();
    }
    obj.ResetList();
    cout << endl;

    cout << "Duplicate items in 2nd array are : ";

    START2:

    for(int i = 1 ; i <= obj2.LengthIs(); i++)
    {
        for(int k = 1; k <=i ; k++)
        {
            obj2.GetNextItem(temp3);
        }
        for(int j = 0; j < obj2.LengthIs()-i; j++)
        {
            obj2.GetNextItem(temp4);
            if(temp3 == temp4)
            {
                obj2.DeleteItem(temp3);
                cout << temp3 << " " ;
                obj2.ResetList();
                goto START2;
            }
        }
        obj2.ResetList();
    }
    obj2.ResetList();
    cout << endl;

    //PRINTING TWO ARRAYS AFTER REMOVING DUPLICATE ELEMENTS

    cout<<" 1st array list without any duplicate elements =";
    obj.ResetList();

    for(int i=0;i<obj.LengthIs();i++)
    {
    obj.GetNextItem(item);
        cout<<" "<<item;
    }
    cout<<endl;
    obj.ResetList();

    cout<<" 2nd array list without any duplicate elements =";
    obj2.ResetList();

    for(int i=0;i<obj2.LengthIs();i++)
    {
    obj2.GetNextItem(item);
        cout<<" "<<item;
    }
    cout<<endl;
    obj2.ResetList();



     /** NEW ASSIGNMENT- PRINTING COMMON VALUES FROM BOTH ARRAYS */

        int e1,e2;
        cout<<"common elements are: ";
     for(int i=0;i<obj.LengthIs();i++)
     {

         obj.GetNextItem(e1);

        for(int j=0; j<obj2.LengthIs(); j++)
        {
            obj2.GetNextItem(e2);
            if(e1==e2)
            {
                cout<<" "<<e1;
            }
        }
            obj2.ResetList();

     }

     cout<<endl;

    return 0;
}

