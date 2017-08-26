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