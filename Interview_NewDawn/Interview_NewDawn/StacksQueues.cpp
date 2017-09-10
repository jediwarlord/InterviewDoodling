#include "StacksQueues.h"

const int BufferSize = 100;
int Buffer[BufferSize * 3] = { 0 };
int Stackpointer[] = { -1, -1, -1 };



void push(int StackNum, int value)
{
	//first we want to check if stack number is full or not..
	if (StackFull(StackNum))
	{
		return;
	} // not full so let's push the value onto the stackbuffer

	Stackpointer[StackNum]++; //increment top of stack.
	Buffer[GetBufferIndex(StackNum)] = value;
}

int peekValue(int _StackNum)
{
	return Buffer[GetBufferIndex(_StackNum)];
}

int pop(int StackNum)
{
	if (isEmpty(StackNum))
	{
		return 0;
	}

	int value = Buffer[GetBufferIndex(StackNum)];
	Buffer[GetBufferIndex(StackNum)] = 0;
	Stackpointer[StackNum]--;
	return value;
}

bool isEmpty(int StackNum)
{
	if (Stackpointer[StackNum] == -1)
	{
		return true;
	}
	return false;
}


bool StackFull(int _StackNum)
{
	if (Stackpointer[_StackNum] >= BufferSize - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int GetBufferIndex(int _StackNum)
{
	return ((_StackNum) * BufferSize) + Stackpointer[_StackNum];
}
