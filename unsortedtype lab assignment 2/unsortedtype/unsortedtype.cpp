
#include "UnsortedType.h"
#include <iostream>
using  namespace std;

template <class ItemType>
UnsortedType<ItemType>::UnsortedType(){
length=0;
currentPos=-1;
}

template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty(){
length=0;
}

template <class ItemType>
bool UnsortedType<ItemType>::IsFull(){

          if(length == MAX_ITEMS){
            return true;
        }
        else return false;
}

template <class ItemType>
int UnsortedType<ItemType>::LengthIs(){

    return length;
}
template <class ItemType>
void UnsortedType<ItemType>::ResetList(){

currentPos= -1;
}
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item){
currentPos++;
item=info[currentPos];

}




template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item){

    info [length] = item;
    length++;


}


template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item){

 int location=0;

     while(item!=info[location])
        {location++;}
    info[location]=info[length-1];
    length--;

    }

    /*for(location=0;location<=(*this).LengthIs();location++){

        if(info[location]==item||){
           info[location]=info[length-1];
           length--;
        }
    }*/




template<class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item,bool &found)
{
    for(int i = 0 ; i<LengthIs();i++)
    {
        if(info[i] == item)
        {
            found = true;
            break;
        }
        else{
            found = false;
        }
    }
}





