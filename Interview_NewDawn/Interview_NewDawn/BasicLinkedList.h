#pragma once

#include <Windows.h>
#include <stdio.h>


typedef struct _ListNode {
	int _data;
	_ListNode* _next;
 } ListNode;

typedef struct LinkedList {
	ListNode * _Head;
	ListNode * _Tail;
	ListNode * _Current;
} LinkedList;

BOOL AddToList(LinkedList *_LinkedList, int _data);

void PrintList(LinkedList *_LinkedList);

BOOL RemoveDup(LinkedList *_LinkedList);

BOOL RemoveKth(LinkedList * _LinkedList, int Kth);

void RemoveNodeAccesss(LinkedList * _LinkedList, ListNode * _Node);

ListNode * GetNodeKth(LinkedList * _LinkedList, int _kth);

//2.4 Write code to partition a linked list around a value x, such that all nodes less than
// x come before all nodes greater than or equal to x.

ListNode * PartitionList(LinkedList * _LinkedList, int _Value);

/* 
You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the Ts digit is at the
head of the list. Write a function that adds the two numbers and returns the sum
as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
Output: 2 -> 1 -> 9.That is, 912.
*/

LinkedList * AddLinkedlist(LinkedList * _List1, LinkedList * _List2);