#include "unsortedtype.h"
#include <iostream>
using  namespace std;

template <class itemType>
unsortedtype<itemType>::unsortedtype(){
length=0;
currentPos=-1;
}

template <class itemType>
void unsortedtype<itemType>::makeEmpty(){
length=0;
}
template <class itemType>
bool unsortedtype<itemType>::isFull(){


          if(length == MAX_ITEMS){
            return true;
        }
        else return false;


}

template <class itemType>
int unsortedtype<itemType>::lengthIs(){

    return length;
}
template <class itemType>
void unsortedtype<itemType>::resetList(){

currentPos= -1;
}
template <class itemType>
void unsortedtype<itemType>::getNextItem(itemType& item){
currentPos++;
item=info[currentPos];

}




template <class itemType>
void unsortedtype<itemType>::insertItem(itemType item){
    if(length>=MAX_ITEMS)
    {
        cout<<"LIST IS ALREADY FULL!!"<<" \n";
    }
     else {
    info [length] = item;
    length++;
     }

}


template <class itemType>
void unsortedtype<itemType>::deleteItem(itemType item){

 int location=0;



     while(item!=info[location])
        {location++;}
    info[location]=info[length-1];
    length--;

    }

    /*for(location=0;location<=(*this).lengthIs();location++){

        if(info[location]==item||){
           info[location]=info[length-1];
           length--;
        }
    }*/




template<class itemType>
void unsortedtype<itemType>::retrieveItem(itemType& item,bool &found)
{
    for(int i = 0 ; i<lengthIs();i++)
    {
        if(info[i] == item)
        {
            found = true;
            break;
        }
        else
        {
            found = false;
        }
    }
}





