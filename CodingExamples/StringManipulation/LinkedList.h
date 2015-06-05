#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <string.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct _doublylinked
{
	void* data;
	_doublylinked* Previous;
	_doublylinked* Next;
	UINT32 number;

} DoublyLinked;

typedef struct _DoubleList
{
	_doublylinked* Head;
	_doublylinked* Tail;
	ULONG          size;
} DoubleList;

bool InsertData(DoubleList** List, void* data);
void PrintList(DoubleList* List);
void DestroyList(DoubleList** List);
DoublyLinked* ReturnElement(int index);
BOOL InitList(DoubleList** List);
BOOL InitDoubleList(DoubleList* List);
BOOL stackPush(DoubleList* stack, void* data);
BOOL stackPop(DoubleList* stack, DoublyLinked** data);
BOOL AddLists(DoublyLinked * FirstNumber, DoublyLinked * SecondNumber, DoublyLinked ** Result, UINT32 Carry);

#endif