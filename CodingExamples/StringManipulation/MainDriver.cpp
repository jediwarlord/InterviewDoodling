// StringManipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	DoubleList * head = NULL;
	DoubleList * Stack = NULL;
	HashTable * HashTable = NULL;

	if (!(initHashTable(&HashTable, 15)))
	{
		printf("Couldn't initialize table...\n");
		return -1;

	}

	//table initalized ... now lets insert data in it..


	for (int i = 0; i < 6; i++)
	{
		InsertData(&head, (void *)i);
	}

	PrintList(head);

	InitList(&Stack); //initalize Stack;

	//Add info to the stack...
	for (int i = 0; i < 6; i++)
	{
		stackPush(Stack, (void *)i);
	}

	//Pop Data while printing it...
	int counter = (int)Stack->size;
	for (int i = 0; i < counter; i++)
	{
		DoublyLinked * temp = NULL;
		stackPop(Stack, &temp);
		printf("Popping the following data...%d \n", (int *) temp->data);
		free(temp);

	}


	return 0;
}

