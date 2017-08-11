// Interview_NewDawn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BasicLinkedList.h"


int main()
{
	
	//initialize test list...
	LinkedList TestList;
	TestList._Current = NULL;
	TestList._Head = NULL;
	TestList._Tail = NULL;

	AddToList(&TestList, 7);
	AddToList(&TestList, 8);
	AddToList(&TestList, 14);
	AddToList(&TestList, 14);
	AddToList(&TestList, 14);
	AddToList(&TestList, 14);

	PrintList(&TestList);


	//we want to remove duplicates from a linked list...

	RemoveDup(&TestList);

	PrintList(&TestList);

	

    return 0;
}

