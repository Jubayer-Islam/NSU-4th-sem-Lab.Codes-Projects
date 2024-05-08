

#ifndef UNSORTEDTYPE_H_INCLUDED
#define  UNSORTEDTYPE_H_INCLUDED

const int MAX_ITEMS=5;
template <class itemType>
class unsortedtype{

public :
    unsortedtype();
    void makeEmpty();
    bool isFull();
    int lengthIs();
    void insertItem(itemType);
    void deleteItem(itemType);
    void retrieveItem(itemType&, bool&);
    void resetList();
    void getNextItem(itemType&);
private:
    int length;
    itemType info[MAX_ITEMS];
    int currentPos;
   // itemType item;
};

#endif // UNSORTEDTYPE_H_INCLUDED


