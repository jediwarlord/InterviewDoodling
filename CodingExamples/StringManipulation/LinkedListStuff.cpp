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

void DestroyList(DoubleList** List)
{
	//iterate through the list and release allocated memory

	DoublyLinked* node = (*List)->Head;
	if (node == NULL){
		return;
	}

	while (node != NULL)
	{
		DoublyLinked* temp = node->Next;
		free(node);
		node = temp;
	}

	return;
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

BOOL stackPop(DoubleList* stack, DoublyLinked** data)

{
	if (stack->Head == NULL)
	{
		return FALSE;
	}

	*data = (stack->Head);
	stack->Head = stack->Head->Next;
	(stack->size)--;

	return TRUE;
}

BOOL stackPush(DoubleList* stack, void* data)
{
	DoublyLinked * node = NULL;
	
	//create a node from data and push it on the stack...
	//check first case scenario where list is null
	if (stack->Head == NULL)
	{
		if ((node = (DoublyLinked *)(malloc(sizeof(DoublyLinked)))) == NULL)
			return FALSE;
		node->data = (data);
		node->Next = NULL;
		node->Previous = NULL;

		stack->Head = node;
		(stack->size)++;
		return FALSE;
	}
	//we want to insert at the head so that the last thing on the stake is the last node to retrieve.
	if ((node = (DoublyLinked *)(malloc(sizeof(DoublyLinked)))) == NULL)
		return FALSE;

	node->Next = stack->Head;
	node->data = data;
	stack->Head = node;
	(stack->size)++;
	return TRUE;
}

BOOL InitList(DoubleList** List)
{
	//initialize list
	if ((*List) == NULL)
	{
		if (((*List) = (DoubleList *)malloc(sizeof(DoubleList))) == NULL)
			return FALSE;
		
	}

	(*List)->Head = NULL;
	(*List)->Tail = NULL;
	(*List)->size = 0;



}

BOOL InitDoubleList(DoubleList* List)
{
	//initialize list


	List->Head = NULL;
	List->Tail = NULL;
	List->size = 0;

	return 0;


}