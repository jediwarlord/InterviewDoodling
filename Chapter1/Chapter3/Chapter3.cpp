// Chapter3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include "33Header.h"
#include <iostream>
#include <stdio.h>

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


    return 0;
}

