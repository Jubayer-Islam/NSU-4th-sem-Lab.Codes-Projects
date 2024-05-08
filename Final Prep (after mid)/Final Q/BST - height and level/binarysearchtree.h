#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include "quetype.h"

template <class ItemType>
struct TreeNode
{
    ItemType info;
    TreeNode *left;
    TreeNode *right;
};

enum OrderType {PRE_ORDER, POST_ORDER, IN_ORDER};

template <class ItemType>
class TreeType
{
public:
    TreeType();
    ~TreeType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    int LengthIs();
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetTree(OrderType order);
    void GetNextItem(ItemType& item, OrderType order, bool& finished);
    void Print();
    int HeightofBST();
    void GetLevel(ItemType item);
    void complete(bool&);
private:
    TreeNode<ItemType> *root;
    QueType<ItemType> preQue;
    QueType<ItemType> postQue;
    QueType<ItemType> inQue;
};

#endif // BINARYSEARCHTREE_H_INCLUDED
