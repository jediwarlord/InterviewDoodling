//
// Created by ommalik on 6/26/2016.
//

#ifndef HASHTABLE_LINKEDLIST_H
#define HASHTABLE_LINKEDLIST_H

#include <iostream>
#include <string>

struct Item
{
    char * Key;
    Item * next;
};

class LinkedList
{
public:
    LinkedList();
    void insertItem(Item * newItem);
    bool removeItem(char * Key);
    Item * getItem(char * Key);
	int getLength();
private:
    Item * Head;
    int length = 0;
    bool Compare(char *Key, Item *Node);
};


#endif //HASHTABLE_LINKEDLIST_H
