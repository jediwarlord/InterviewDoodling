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


BOOL RemoveKth(LinkedList * _LinkedList, int Kth)
{
	//we need 2 runners one to find the end of the linked list the other to trail behind by kth or < than.
	ListNode * _Runner = _LinkedList->_Head;
	ListNode * _Kth = _LinkedList->_Head;
	ListNode * _PrevTemnp = NULL;
	int count = 0;


	//we start them both off at the head.
	//first check would be to see if there is enough space for the function to remove the Kth node.
	while (_Runner->_next && count < Kth)
	{
		_Runner = _Runner->_next;
		count++;
	}

	//if (!(count == Kth - 1))
	//{
	//	return false; // list was smaller than what was possible to remove.
	//}

	//if we made it here.. the runner is Kth spaces ahead of the node to delete which should be sitting on the
	// head at the moment.
	while (_Runner->_next)
	{
		//check if kth 
		_Runner = _Runner->_next;
		_PrevTemnp = _Kth;
		_Kth = _Kth->_next;
	}

	//at this point we have arrived at our Kth to last node. we do the removal here.
	//check if head node is being deleted
	if (_Kth == _LinkedList->_Head)
	{
		_PrevTemnp = _LinkedList->_Head;
		_LinkedList->_Head = _LinkedList->_Head->_next;
		free(_PrevTemnp);
		return true;
	}
	else //regular removal
	{
		_PrevTemnp->_next = _Kth->_next;
		free(_Kth);
		return true;	
	}

	return true;
}

void RemoveNodeAccesss(LinkedList * _LinkedList, ListNode * _Node)
{
	//need to shift up all nodes after _node up one to delete the node.
	ListNode * _NodeRunner = _Node->_next;

	_Node->_data = _NodeRunner->_data;
	_Node->_next = _NodeRunner->_next;
	return;

}

ListNode * GetNodeKth(LinkedList * _LinkedList, int _kth)
{
	ListNode * _Node = _LinkedList->_Head;
	int count = 1;
	
	while (_Node->_next != NULL && count < _kth)
	{
		_Node = _Node->_next;
		count++;
	}

	//if there is less than Kth nodes in the list reutrn nullptr
	if (count < _kth)
	{
		return nullptr;
	}
	else
	{
		return _Node;
	}
}

ListNode * PartitionList(LinkedList * _LinkedList, int _Value)
{
	ListNode * BeforeStart = NULL;
	ListNode * BeforeEnd = NULL;
	ListNode * AfterSTart = NULL;
	ListNode * AfterEnd = NULL;

	ListNode * CurrentNode = _LinkedList->_Head;

	while (CurrentNode)
	{
		ListNode * Next = CurrentNode->_next;
		CurrentNode->_next = NULL;

		if (CurrentNode->_data < _Value)
		{
			if (BeforeStart == NULL)
			{
				BeforeStart = CurrentNode;
				BeforeEnd = CurrentNode;
			}
			else
			{
				BeforeEnd->_next = CurrentNode;
				BeforeEnd = CurrentNode;
			}
		}
		else
		{
			if (AfterSTart == NULL)
			{
				AfterSTart = CurrentNode;
				AfterEnd = CurrentNode;
			}
			else
			{
				AfterEnd->_next = CurrentNode;
				AfterEnd = CurrentNode;
			}

		}

		CurrentNode = Next;

	}

	if (BeforeStart == NULL)
	{
		return AfterSTart;
	}

	//Merge the lists.

	BeforeEnd->_next = AfterSTart;
	return BeforeStart;
}

BOOL IsPalindrome(LinkedList * _LinkedList)
{

	return 0;
}


	void RemoveLoop(LinkedList * _List)
{

	//first we detect if there is a loop within the list or not.
	ListNode * Slow_Runner = _List->_Head;
	ListNode * Fast_Runner = _List->_Head;
	ListNode * LoopNode = NULL;

	while (Slow_Runner != NULL && Fast_Runner != NULL && Fast_Runner->_next != NULL)
	{
		Slow_Runner = Slow_Runner->_next;
		Fast_Runner = Fast_Runner->_next->_next;

		if (Slow_Runner == Fast_Runner) // Loop found
		{
			LoopNode = Slow_Runner;
			continue;
		}
	}

	if (LoopNode == NULL) // no loop found.
	{
		return;
	}

	//reset the runners and count the number of nodes in the loop.
	unsigned int k = 1;
	ListNode * ptr1 = LoopNode->_next;

	while (ptr1->_next != LoopNode)
	{
		k++;
		ptr1 = ptr1->_next;
	}

	//there are K nodes in the loop
	//now lets progress both nodes one step at a time and they will meet at the beginning point..
	ListNode * ptr2 = _List->_Head;
	ptr1 = ptr2;

	//move ptr2 forward k steps

	for (int i = 0; i < k; i++)
	{
		ptr2 = ptr2->_next;
	}

	//now move both one step at a time until they meet. at that point they are at the beginning of the loop.
	while (ptr2 != ptr1)
	{
		ptr2 = ptr2->_next;
		ptr1 = ptr1->_next;
	}

	//they are at the beginning... move one pointer around to point to the first pointer and that's where we break the loop.
	while (ptr2->_next != ptr1)
	{
		ptr2 = ptr2->_next;
	}

	//BREAK IT FINALLY!
	ptr2->_next = NULL;

}



LinkedList * AddLinkedlist(LinkedList * _List1, LinkedList * _List2)
{
	if (_List1 == nullptr && _List2 == nullptr)
		return nullptr;

	ListNode * Node1 = _List1->_Head;
	ListNode * Node2 = _List2->_Head;
	LinkedList * ReturnValue = (LinkedList *) malloc(sizeof(LinkedList));
	ReturnValue->_Current = NULL;
	ReturnValue->_Head = NULL;
	ReturnValue->_Tail = NULL;
	int carry = 0;

	while (Node1 != NULL && Node2 != NULL)
	{
		int _sum = Node1->_data + Node2->_data + carry;
		carry = _sum / 10;
		_sum = _sum % 10;

		//insert into new linkedlist
		AddToList(ReturnValue, _sum);

		//progress the traversal nodes...
		Node1 = Node1->_next;
		Node2 = Node2->_next;

	}

	//now we check to see if there are remaining nodes left.

	if (Node1 != NULL)
	{// remaining nodes ListNode1 need to be added
		while (Node1 != NULL)
		{
			int _sum = 0;
			_sum = Node1->_data + carry;

			carry = _sum / 10;
			_sum = _sum % 10;

			AddToList(ReturnValue, _sum);
			
			Node1 = Node1->_next;
		}
	}
	else if (Node2 != NULL)
	{
		while (Node2 != NULL)
		{
			int _sum = 0;
			_sum = Node2->_data + carry;

			carry = _sum / 10;
			_sum = _sum % 10;

			AddToList(ReturnValue, _sum);

			Node2 = Node2->_next;
		}
	} 
	else if (carry != 0)
	{
		AddToList(ReturnValue, carry);
	}

	return ReturnValue;

}


