#pragma once
#pragma once

#include <iostream>
#include <string>

struct Stack
{
	Stack* Previous = NULL;
	int Value;
};

struct QueueofStacks
{
	Stack *_CurrentStack = NULL;
    int _currentcount;
	QueueofStacks * _Previous;
};


class QueueStack
{
public:
	QueueStack(void);
	void Push(int _value);
	int Pop();
	int Min();
private:
	void PushValue(QueueofStacks * _Queue, int _value);
	int _sizeofStack = 5;
	int _numberofStacks = 0;
	QueueofStacks * _stackQueue = NULL;
};