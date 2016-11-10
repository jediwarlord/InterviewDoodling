
#ifndef HASHTABLE_LINKEDLIST_H
#define HASHTABLE_LINKEDLIST_H

#include <iostream>
#include <string>

struct Item
{
	int Value;
	Item * next;
};

class LinkedList
{
public:
	LinkedList(int _stacksize);
	void insertItem(int _value);
	bool removeItem(int _index);
	int getItem(int _index);
private:
	Item * Head = NULL;
	int length = 0;
};


#endif //HASHTABLE_LINKEDLIST_H