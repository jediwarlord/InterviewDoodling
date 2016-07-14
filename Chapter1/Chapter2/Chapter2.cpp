// Chapter2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "list.h"
#include <string>
#include <iostream>


ListNode * getNthNode(Linklist * _list, int _nTH)
{
	ListNode * current = _list->getHead();
	ListNode * runner = current;
	int currentcount = 0;

	if (current == nullptr)
		return nullptr;

	//traverse the runner K steps ahead... if K ends up going past the last node return null..
	while (runner)
	{
		if (currentcount == _nTH)
		{
			break;
		}
		else
		{
			//advance the runner...
			runner = runner->next;
			currentcount++;
		}
	}

	if ((runner == nullptr))
	{
		return nullptr; //because _nth too big an index..
	}

	//no advance runner and current till runner hits last node..
	while (runner->next)
	{
		current = current->next;
		runner = runner->next;
	}

	return current;
}

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
	ListNode * _nthNode;


	//add an item..
	baselist.appendNode("This is a test");
	baselist.appendNode("This is another test");
	baselist.appendNode("This is a test");
	baselist.appendNode("test1");
	baselist.appendNode("test1");

	baselist.printList();
	//deleteDupes(&baselist);
	baselist.printList();

	//find kth node..
	_nthNode = getNthNode(&baselist, 5);


    return 0;
}



