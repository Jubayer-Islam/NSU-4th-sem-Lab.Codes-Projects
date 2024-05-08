#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

class FullStack{};
class EmptyStack{};



template <class ItemType>
class stacktype
{
    public:
        stacktype(int max);
        stacktype();
        ~stacktype();
        virtual bool IsFull();
        virtual bool IsEmpty();
        virtual void MakeEmpty();
        virtual void Push(ItemType);
        virtual void Pop();
        virtual ItemType Top();

    private:
        int top;
        int maxStack;
        ItemType *items;
};
#endif // STACKTYPE_H_INCLUDED
