#pragma once

#include <iostream>
#include <string>

struct MinNode 
{
	MinNode* Previous;
	int MinValue;
};

struct stackNode
{
	int value;
	stackNode* Previous;
};

class StackO1
{
public:
	StackO1(void);
	void Push(int _value);
	int Pop();
	int Min();
private:
	stackNode * _stackCurrent = NULL;
	MinNode * _MinCurrent = NULL;
	int _sizeMin = 0;
	int _sizeStack = 0;
};