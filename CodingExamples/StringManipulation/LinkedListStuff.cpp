//#include "LinkedList.h"
#include "stdafx.h"

bool InsertData(DoubleList** List, void* data)
{
	DoublyLinked* node = (DoublyLinked *)malloc(sizeof(DoublyLinked));
	node->data = data;
	DoublyLinked* TempNode;


	//check to see if list initalized. 
	if ((*List) == NULL)
	{
		//list is first time.. 
		//point node to itself forward and back because it is the only on in list. 
		node->Next = NULL;
		node->Previous = NULL;

		*(List) = (DoubleList *) malloc(sizeof(DoubleList));
		(*List)->Head = node;
		(*List)->Tail = node;
		((*List)->size)++;

		return TRUE;

	}

	//this is not the first node..
	TempNode = (*List)->Head;
	
	//find the place to insert it in.. will insert at the end. 
	while (TempNode != NULL)
	{
		if (TempNode->Next == NULL)
		{
			TempNode->Next = node;
			node->Next = NULL;
			node->Previous = TempNode;
			((*List)->size)++;
			return TRUE;
			//break;
		}
		else
		{
			TempNode = TempNode->Next;
		}
	}

	return FALSE; //should never get here
}

void PrintList(DoubleList* List)
{
	int i = 0;

	if (List == NULL)
	{
		printf("There are no elements in the list...\n");

		}

	DoublyLinked * node;
	
	node = List->Head;

	while (node != NULL)
	{
		printf("%d element has %d value \n", (i + 1), (int *)node->data);

		i++;
		node = node->Next;
	}
	
}