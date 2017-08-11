#include "BasicLinkedList.h"

//add to tail...

BOOL AddToList(LinkedList * _LinkedList, int _data)
{
	if (_data == NULL || _LinkedList == NULL)
	{
		return false;
	}

	ListNode* node = (ListNode *) malloc(sizeof(ListNode));
	node->_data = _data;
	node->_next = NULL;

	//empty list.

	if (_LinkedList->_Head == NULL)
	{
		_LinkedList->_Head = node;
		_LinkedList->_Tail = node;
		_LinkedList->_Current = node;
		return true;
	}

	//set the current runner to the head...
	_LinkedList->_Current = _LinkedList->_Head;

	//there is something in list..iterate and add at end..
	while (_LinkedList->_Current->_next)
	{
		_LinkedList->_Current = _LinkedList->_Current->_next;
	}

	_LinkedList->_Current->_next = node;
	_LinkedList->_Tail = node;

	return true;
}

void PrintList(LinkedList * _LinkedList)
{
	if (!_LinkedList->_Head)
	{
		printf("List is NULL");
	}

	_LinkedList->_Current = _LinkedList->_Head;

	while (_LinkedList->_Current)
	{
		printf("\t %d ->", _LinkedList->_Current->_data);
		_LinkedList->_Current = _LinkedList->_Current->_next;
	}

	printf(" NULL \n");

}

BOOL RemoveDup(LinkedList * _LinkedList)
{
	if (_LinkedList->_Head == NULL || _LinkedList->_Head == _LinkedList->_Tail)
		return false;

	//we'll iterate through the list and check with each node until we find a match and delete that node.
	ListNode* prev = _LinkedList->_Head;
	_LinkedList->_Current = _LinkedList->_Head;

	while (_LinkedList->_Current != NULL)
	{
		ListNode *runner = _LinkedList->_Current;
		prev = _LinkedList->_Current;
		int data = _LinkedList->_Current->_data;

		while (runner->_next)
		{
			if (data == runner->_next->_data)
			{ //dup found... delete the next node found and keep the current...
				ListNode* Temp = runner->_next;
				runner->_next = runner->_next->_next;
				free(Temp);
			}
			else 
			{
				runner = runner->_next;
			}
			
		}

		//advance the current node..
		_LinkedList->_Current = _LinkedList->_Current->_next;
		
	}

	
	


	return true;
}
