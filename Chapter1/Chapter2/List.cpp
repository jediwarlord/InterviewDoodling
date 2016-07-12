#include "stdafx.h"
#include "List.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

Linklist::Linklist()
{
	Head = nullptr;
	length = 0;
	
}

ListNode * Linklist::getHead()
{
	return Head;
}

void Linklist::printList()
{
	ListNode * traverseNode = Head;

	if (!traverseNode)
	{
		std::cout << "Nothing here...\n";
		return;
	}

	while (traverseNode)
	{
		std::cout << traverseNode->data << "---->";
		traverseNode = traverseNode->next;
	}

	std::cout << " NULL \n";
	return;

}

void Linklist::appendNode(char * _data)
{
	ListNode * Node = new ListNode;
	ListNode * traverseNode;
	Node->data = _data;
	Node->next = nullptr;

	if (!Head)
	{//nullptr..
		Head = Node;
		length++;
		return;
	}

	traverseNode = Head; // start traversing..

	while (traverseNode->next)
	{
		traverseNode = traverseNode->next;
	}

	traverseNode->next = Node;
	length++;

	return;
}

int Linklist::getlength()
{
	return length;
}

void Linklist::deleteNode(char * _data)
{
	ListNode * traverseNode = Head;
	ListNode * previous = Head;
	ListNode * temp;

	if (!traverseNode)
	{
		return;
	}

	while (traverseNode)
	{
		if (strcmp(_data, traverseNode->data))
		{
			//found match..delete..
			if (traverseNode == Head)
			{
				temp = Head;
				Head = Head->next;
				length--;
				free(temp);
				return;
			}
			else
			{
				previous->next = traverseNode->next;
				free(traverseNode);
				length--;
			}
		}
		previous = traverseNode;
		traverseNode = traverseNode->next;
		
	}

	return;
}