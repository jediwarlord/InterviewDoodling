//
// Created by ommalik on 6/26/2016.
//

#include "LinkedList.h"


LinkedList::LinkedList()
{
    Head = new Item;
    Head->next = NULL;
    length = 0;
}

Item * LinkedList::getItem(char *Key)
{

}

bool LinkedList::removeItem(char *Key)
{
    //traverse list and remove node if found...
    Item * _node = Head;
    _node = Head->next;
    while(_node)
    {
        if (Compare(Key,_node))
        {
            //match found ?
        }
        else
        {
            // key not found so return nothing...
        }
    }


    return false;
}

bool LinkedList::Compare(char *Key, Item *Node)
{
    char * currenttest = Node->Key; // first character..
    char * testKey = Key;
    while (*currenttest != '\0')
    {
        if (*currenttest != *testKey)
        {
            //can't find key..
            return false;
        }
        currenttest++;
        testKey++;
    } // if you have gotten to \0...
    if (*testKey == '\0')
    {
        //this is a match.. return true
        return true;
    }
    //not equal
    return false;

}



void LinkedList::insertItem(Item *newItem)
{
    if (!Head->next) //if this is empty... then add new nodes..
    {
        newItem->next = NULL;
        Head->next = newItem;
        length++;
        return;
    }
    // already items in here so lets add another to the end of this..
    Item * p = Head;
    Item * q = Head;
    while (q)
    {
        if (!(q->next))
        {
            q->next = newItem;
            newItem->next = NULL;
            length++;
            return;
        }
        q = q->next;
    }
}







