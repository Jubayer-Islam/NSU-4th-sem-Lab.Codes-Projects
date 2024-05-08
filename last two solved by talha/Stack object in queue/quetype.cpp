#include "quetype.h"
#include "stacktype.cpp"
#include <iostream>
using namespace std;



template<class ItemType>
QueType<ItemType>::QueType(int max){
    stacktype<ItemType>ob(max);

}

template<class ItemType>
QueType<ItemType>::QueType(){
    stacktype<ItemType>ob;

}

template<class ItemType>
QueType<ItemType>::~QueType(){
    //ob.~stacktype();

}

template<class ItemType>
void QueType<ItemType>::MakeEmpty(){
    ob.MakeEmpty();
}


template<class ItemType>
bool QueType<ItemType>::IsEmpty(){
    return ob.IsEmpty();
}

template<class ItemType>
bool QueType<ItemType>::IsFull(){
    return ob.IsFull();
}

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem){
    try{
        if(ob.IsFull())
            throw FullQueue();
        else{
            ob.Push(newItem);
        }
    }
    catch(FullQueue f){
        cout<<endl<<"Queue Overflow "<<endl;
    }
}

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item){
    stacktype<ItemType>aux;
    try{
        if(ob.IsEmpty())
            throw EmptyQueue();
        else{
           while(ob.IsEmpty()!=true){
            aux.Push(ob.Top());
            ob.Pop();
           }
           item=aux.Top();
           aux.Pop();
           while(aux.IsEmpty()!=true){
            ob.Push(aux.Top());
            aux.Pop();
           }
        }
    }
    catch(EmptyQueue e){
        cout<<endl<<"Queue Underflow "<<endl;
    }
}








