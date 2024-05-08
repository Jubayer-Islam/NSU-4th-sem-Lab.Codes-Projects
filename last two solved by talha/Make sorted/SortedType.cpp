
#include "SortedType.h"

template <class ItemType>
sortedtype<ItemType>::sortedtype()
{
    length = 0;
    currentPos = -1;
}


template <class ItemType>
void sortedtype<ItemType>::MakeEmpty()
{
    length = 0;
}


template <class ItemType>
bool sortedtype<ItemType>::isFull()
{
    if(length != 0){
        if(length == MAX_ITEMS){
            return true;
        }
        else return false;
    }
}


template <class ItemType>
int sortedtype<ItemType>::LengthIs()
{
    return length;
}


template <class ItemType>
void sortedtype<ItemType>::ResetList()
{
    currentPos = -1;
}


template <class ItemType>
void sortedtype<ItemType>::GetNextItem(ItemType& item)
{
    currentPos++;
    item = info[currentPos];
}


template <class ItemType>
void sortedtype<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
    int first=0,last=length-1,mid=0;

    while(first<=last){
        mid=(first+last)/2;

    if(info[mid]==item){
        found = true;
        break;
        }
    else if(info[mid]<item){
         first=mid+1;
        }
        else if(info[mid]>item){
         last=mid-1;
        }

    }

}


template <class ItemType>
void sortedtype<ItemType>::InsertItem(ItemType item)
{   int location=0;
    while(location<length){

        if(item>info[location]){
            location++;
        }
        else
            break;
        }
    for(int index=length-1;index>=location;index--){
        info[index+1] = info[index];
    }
    info[location]=item;
    length++;
}


template <class ItemType>
void sortedtype<ItemType>::DeleteItem(ItemType item)
{
    int location = 0;
    while(item != info[location])
        location++;
    for(int index=location+1; index<length;index++)
        info[index-1] = info[index];
        length--;
}









