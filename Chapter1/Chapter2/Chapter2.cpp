// Chapter2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "list.h"
#include <string>
#include <iostream>


void deleteDupes(Linklist * list)
{
	ListNode * current = list->getHead();
	
	if (current == nullptr)
		return;

	ListNode * runner = current;
	while (current)
	{
		runner = current;
		while (runner->next != nullptr)
		{
			if (!strcmp(current->data, runner->next->data))
			{
				runner->next = runner->next->next; // have to free it up as well ; memory leak here...
			}
			else
			{
				runner = runner->next;
			}
		}
		current = current->next;
	}

}

int main()
{
	Linklist baselist;

	//add an item..
	baselist.appendNode("This is a test");
	baselist.appendNode("This is another test");
	baselist.appendNode("This is a test");
	baselist.appendNode("test1");
	baselist.appendNode("test1");

	baselist.printList();
	deleteDupes(&baselist);
	baselist.printList();


    return 0;
}



