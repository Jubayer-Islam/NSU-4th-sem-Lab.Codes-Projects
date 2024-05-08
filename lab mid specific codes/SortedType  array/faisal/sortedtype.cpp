#include <iostream>
#include "sortedtype.h"

template  <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    currentPos = -1;
}

template  <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
    length = 0;
}

template  <class ItemType>
bool SortedType<ItemType>::IsFull()
{
    return (MAX_ITEMS == length);
}

template  <class ItemType>
int SortedType<ItemType>::LengthIs()
{
    return length;
}

template  <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
    int location = 0;

    while (location < length)
    {
        if(item > info [location])
        {
            location++;
        }
        else
        {
            break;
        }
    }
    for (int index = length -1 ; index >= location ; index--)
    {
        info [index+1] = info [index];
    }
    info[location] = item;
    length++;
}

template  <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
    int location = 0;
    while (item != info [location])
    {
        location++;
    }
    for (int index = location + 1 ; index < length ; index++ )
    {
        info [index - 1] = info [index];
    }
    length--;

}

template  <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
    int first = 0 , mid , last = length - 1;

    while (first <= last)
    {
        mid = (first + last ) / 2 ;
        if (info[mid] == item)
        {
            found = true;
            return;
        }
        if(info [mid] < item)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    found = false;
}

template  <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = -1;
}

template  <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
{
    currentPos++;
    item = info [currentPos];
}
