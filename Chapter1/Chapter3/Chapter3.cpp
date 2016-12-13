// Chapter3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include "33Header.h"
#include <iostream>
#include <stdio.h>
#include "34Header.h"

using namespace std;



int main()
{
	StackO1 Stack;

	Stack.Push(1);
	Stack.Push(6);
	Stack.Push(3);
	Stack.Push(10);

	cout << Stack.Pop() << "\n";
	cout << Stack.Pop() << "\n";

	QueueStack SetofStacks;

	SetofStacks.Push(3);
	SetofStacks.Push(2);
	SetofStacks.Push(4);
	SetofStacks.Push(6);
	SetofStacks.Push(5);
	SetofStacks.Push(1);

    return 0;
}

