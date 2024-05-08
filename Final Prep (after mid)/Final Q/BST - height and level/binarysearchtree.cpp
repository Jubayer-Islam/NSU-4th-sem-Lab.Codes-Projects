#include "binarysearchtree.h"
#include "quetype.cpp"
#include <iostream>
using namespace std;

template <class ItemType>
TreeType<ItemType>::TreeType()
{
    root=NULL;
}

template <class ItemType>
void Destroy(TreeNode<ItemType>*& tree)
{
    if(tree!=NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
        tree=NULL;
    }
}

template <class ItemType>
TreeType<ItemType>::~TreeType()
{
    Destroy(root);
}

template <class ItemType>
void TreeType<ItemType>::MakeEmpty()
{
    Destroy(root);
}

template <class ItemType>
bool TreeType<ItemType>::IsEmpty()
{
    return (root==NULL);
}

template <class ItemType>
bool TreeType<ItemType>::IsFull()
{
    TreeNode<ItemType> *location;
    try
    {
        location=new TreeNode<ItemType>;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}

template <class ItemType>
int CountNodes(TreeNode<ItemType> *tree)
{
    if(tree==NULL)
        return 0;
    else
        return (CountNodes(tree->left)+CountNodes(tree->right)+1);
}

template <class ItemType>
int TreeType<ItemType>::LengthIs()
{
    return CountNodes(root);
}

template <class ItemType>
void Retrieve(TreeNode<ItemType> *tree, ItemType& item, bool& found)
{
    if(tree==NULL)
        found=false;
    else if(item<tree->info)
        Retrieve(tree->left,item,found);
    else if(item>tree->info)
        Retrieve(tree->right,item,found);
    else
    {
        item=tree->info;
        found=true;
    }
}

template <class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
    Retrieve(root,item,found);
}

template <class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
{
    if(tree==NULL)
    {
        tree = new TreeNode<ItemType>;
        tree->left=NULL;
        tree->right=NULL;
        tree->info=item;
    }
    else if(item<tree->info)
        Insert(tree->left,item);
    else
        Insert(tree->right,item);
}

template <class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
{
    Insert(root,item);
}

template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
{
    if(item<tree->info)
        Delete(tree->left,item);
    else if(item>tree->info)
        Delete(tree->right,item);
    else
        DeleteNode(tree);
}

template <class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
{
    ItemType data;
    TreeNode<ItemType> *tempPtr;
    tempPtr=tree;
    if(tree->left==NULL)
    {
        tree=tree->right;
        delete tempPtr;
    }
    else if(tree->right==NULL)
    {
        tree=tree->left;
        delete tempPtr;
    }
    else
    {
        GetPredecessor(tree->left,data);
        tree->info=data;
        Delete(tree->left,data);
    }
}

template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
{
    while(tree->right!=NULL)
        tree=tree->right;

    data=tree->info;
}

template <class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
{
    Delete(root,item);
}

template <class ItemType>
void PreOrder(TreeNode<ItemType>* tree, QueType<ItemType>& Que)
{
    if(tree!=NULL)
    {
        Que.Enqueue(tree->info);
        PreOrder(tree->left,Que);
        PreOrder(tree->right,Que);
    }
}

template <class ItemType>
void InOrder(TreeNode<ItemType>* tree, QueType<ItemType>& Que)
{
    if(tree!=NULL)
    {
        InOrder(tree->left,Que);
        Que.Enqueue(tree->info);
        InOrder(tree->right,Que);
    }
}

template <class ItemType>
void PostOrder(TreeNode<ItemType>* tree, QueType<ItemType>& Que)
{
    if(tree!=NULL)
    {
        PostOrder(tree->left,Que);
        PostOrder(tree->right,Que);
        Que.Enqueue(tree->info);
    }
}

template <class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order)
{
    switch(order)
    {
        case PRE_ORDER:
            PreOrder(root,preQue);
            break;
        case IN_ORDER:
            InOrder(root,inQue);
            break;
        case POST_ORDER:
            PostOrder(root,postQue);
            break;
    }
}

template <class ItemType>
void TreeType<ItemType>::GetNextItem(ItemType& item, OrderType order, bool& finished)
{
    finished=false;
    switch(order)
    {
        case PRE_ORDER:
            preQue.Dequeue(item);
            if(preQue.isEmpty())
                finished=true;
            break;
        case IN_ORDER:
            inQue.Dequeue(item);
            if(inQue.isEmpty())
                finished=true;
            break;
        case POST_ORDER:
            postQue.Dequeue(item);
            if(postQue.isEmpty())
                finished=true;
            break;
    }
}

template <class ItemType>
void PrintTree(TreeNode<ItemType>* tree)
{
    if(tree!=NULL)
    {
        PrintTree(tree->left);
        cout<<tree->info<<" ";
        PrintTree(tree->right);
    }
}

template <class ItemType>
void TreeType<ItemType>::Print()
{
    PrintTree(root);
}

template <class ItemType>
int Height(TreeNode<ItemType> *tree){

    if(tree==NULL)
        return 0;
    else{
        int leftDepth=Height(tree->left);
        int rightDepth=Height(tree->right);

        if(leftDepth>rightDepth)
            return(leftDepth+1);
        else
            return(rightDepth+1);
    }

}

template <class ItemType>
int TreeType<ItemType>::HeightofBST(){
    return Height(root);
}

template <class ItemType>
int getLevelUtil(TreeNode<ItemType> *tree,int item, int level){

    if(tree==NULL)
        return 0;
    if(tree->info==item)
        return level;

    int downlevel=getLevelUtil(tree->left,item,level+1);

    if(downlevel!=0)
        return downlevel;

    downlevel=getLevelUtil(tree->right,item,level+1);

    return downlevel;

}

template <class ItemType>
void TreeType<ItemType>::GetLevel(ItemType item){
    int level=getLevelUtil(root,item,1);

    if(level){
        cout<<"Level of "<<item<<" is: "<<level-1<<endl;
    }
    else{
        cout<<item<<" is not present in tree"<<endl;
    }
}

template <class ItemType>
void TreeType<ItemType>::complete(bool &flag)
{
  if(cmp(root))
    flag=true;

  else
  flag=false;

}

template <class ItemType>
bool  cmp(TreeNode<ItemType>* tree){

  if(tree->left==NULL&&tree->right==NULL)
     return true;
  else if(tree->left==NULL&&tree->right!=NULL)
       return false;

 else if(tree->left!=NULL&&tree->right==NULL)
       return true;

 else
    (cmp(tree->left)&&cmp(tree->right));


}




