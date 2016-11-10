#include "stdafx.h"
#include "LinkedList.h"

LinkedList::LinkedList(int _stacksize)
{
	Head = new Item;

	Head->next = NULL;
	length = 0;
}
