#pragma once
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define NEXT(x) 

struct ListNode
{
	char * data;
	ListNode * next;
};

class Linklist
{
private:
	ListNode * Head;
	int length;
public:
	Linklist();
	ListNode * getHead();
	void printList();
	void appendNode(char * _data);
	int getlength();
	void deleteNode(char * _data);
};
