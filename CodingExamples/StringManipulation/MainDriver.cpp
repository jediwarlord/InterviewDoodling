// StringManipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int _tmain(int argc, _TCHAR* argv[])
{

	//hashtable_t *hashtable = ht_create(65536);

	//ht_set(hashtable, "key1", "inky");
	//ht_set(hashtable, "key1", "Omer");
	//ht_set(hashtable, "key2", "pinky");
	//ht_set(hashtable, "key3", "blinky");
	//ht_set(hashtable, "key4", "floyd");
	//

	//printf("%s\n", ht_get(hashtable, "key1"));
	//printf("%s\n", ht_get(hashtable, "key2"));
	//printf("%s\n", ht_get(hashtable, "key3"));
	//printf("%s\n", ht_get(hashtable, "key4"));

	//return 0;
	//DoubleList * head = NULL;
	//DoubleList * Stack = NULL;
	//HashTable * HashTable = NULL;

	//if (!(initHashTable(&HashTable, 15)))
	//{
	//	printf("Couldn't initialize table...\n");
	//	return -1;

	//}

	////table initalized ... now lets insert data in it..


	//for (int i = 0; i < 6; i++)
	//{
	//	InsertData(&head, (void *)i);
	//}

	//PrintList(head);

	//InitList(&Stack); //initalize Stack;

	////Add info to the stack...
	//for (int i = 0; i < 6; i++)
	//{
	//	stackPush(Stack, (void *)i);
	//}

	////Pop Data while printing it...
	//int counter = (int)Stack->size;
	//for (int i = 0; i < counter; i++)
	//{
	//	DoublyLinked * temp = NULL;
	//	stackPop(Stack, &temp);
	//	printf("Popping the following data...%d \n", (int *) temp->data);
	//	free(temp);

	//}

	//saw we get a number in a linked list that we want to add.
	//each linked list is initialized with a number.

	//DoubleList* FirstNumber = NULL;
	//DoubleList* SecondNumber = NULL;
	//DoublyLinked* Result = NULL;

	//UINT32 ui32_digit = 0;
	//UINT32 ui32_carry = 0;

	////we want to initialize the linked list so as to contain the individual numbers. 
	////lets start with 3 digit numbers and move from there. We can use the carry digit 
	//// as a UINT referenced variable to use in fucntio n calls.

	////first number.... 519
	//ui32_digit = 9;
	//InsertData(&FirstNumber,  ((&ui32_digit)));
	//ui32_digit = 1;
	//InsertData(&FirstNumber, ((&ui32_digit)));
	//ui32_digit = 5;
	//InsertData(&FirstNumber, ((&ui32_digit)));

	////second number...567

	//ui32_digit = 7;
	//InsertData(&SecondNumber, ((&ui32_digit)));
	//ui32_digit = 6;
	//InsertData(&SecondNumber, ((&ui32_digit)));
	//ui32_digit = 5;
	//InsertData(&SecondNumber, ((&ui32_digit)));

	////print the numbers just to be sure..
	//PrintList(FirstNumber);
	//PrintList(SecondNumber);

	////now we want to add these linked list and carry over any carrys
	////return a list that contains the addition of the list.
	//AddLists(FirstNumber->Head, SecondNumber->Head, &Result, ui32_carry);


	//We will do the circular linked list question here...

	//Binary tree operations..
	Tree* HeadNode = NULL;
	int size = 0;

	insertBinaryNode(3, &HeadNode);
	insertBinaryNode(4, &HeadNode);
	insertBinaryNode(2, &HeadNode);
	insertBinaryNode(10, &HeadNode);
	insertBinaryNode(15, &HeadNode);
	insertBinaryNode(7, &HeadNode);

	print_ascii_tree(HeadNode);
	PreOrderTree(HeadNode, &size);

	printf("\n Size of binary tree is....%u ", size);
	return 0;
}

