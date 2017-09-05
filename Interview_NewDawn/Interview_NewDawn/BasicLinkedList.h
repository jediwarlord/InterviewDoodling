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