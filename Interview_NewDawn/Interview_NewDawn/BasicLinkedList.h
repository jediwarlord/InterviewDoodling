#pragma once

#include <Windows.h>


typedef struct _ListNode {
	void * _data;
	_ListNode* _next;
 } ListNode;

typedef struct LinkedList {
	ListNode * _Head;
	ListNode * _Tail;
	ListNode * _Current;
} LinkedList;

BOOL AddToList(LinkedList *_LinkedList, void * _data);