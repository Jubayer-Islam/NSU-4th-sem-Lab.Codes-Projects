#include <iostream>
#include <iterator>
#include "SortedType.cpp"

using namespace std;


int* makeSorted(sortedtype<int>S1,sortedtype<int>S2){
    static int arr[8];
    int temp=0;
    int count=0;
    for(int i=0; i<S1.LengthIs();i++){

        S1.GetNextItem(temp);
        arr[i]=temp;
        count++;
    }

    for(int i=0;i<S2.LengthIs();i++){

    S2.GetNextItem(temp);
    int location=0;
    while(location<count){
        if(temp>arr[location]){
            location++;
        }
        else
            break;
        }

    for(int index=count-1;index>=location;index--){
        arr[index+1] = arr[index];
    }

    arr[location]=temp;
    count++;
    }

    S1.ResetList();
    S2.ResetList();

    return arr;
}

int main()
{
    sortedtype<int>S1;
    sortedtype<int>S2;

    S1.InsertItem(1);
    S1.InsertItem(3);
    S1.InsertItem(5);
    S1.InsertItem(7);
    S2.InsertItem(2);
    S2.InsertItem(4);
    S2.InsertItem(6);
    S2.InsertItem(8);

    int i=0;
    int *ptr=makeSorted(S1,S2);
    while(ptr[i]!=NULL){
        cout<<ptr[i]<<" ";
        i++;
    }


   return 0;
}
