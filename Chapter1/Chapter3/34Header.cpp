#include "stdafx.h"
#include "34Header.h"

QueueStack::QueueStack(void)
{
	_stackQueue = NULL;
}

void QueueStack::Push(int _value)
{
	//check Queustack is uninitialized
	if (!_stackQueue)
		//null
	{
		_stackQueue = new QueueofStacks;
		_stackQueue->_currentcount = 0;
		_stackQueue->_Previous = NULL;
		PushValue(_stackQueue, _value);
	}
	else
	{
		PushValue(_stackQueue, _value);
	}
}

void QueueStack::PushValue(QueueofStacks * _Queue, int _value)
{
	//check if stack is uninitalized..
	if (_Queue->_CurrentStack == NULL)
	{
		//if current stack is un-initalized then create another 
		_Queue->_CurrentStack = new Stack;
		_Queue->_CurrentStack->Value = _value;
		_Queue->_CurrentStack->Previous = NULL;
		//check current count if less than 
		_Queue->_currentcount += 1;
		return;
	}
	//means stack has already been initalized. 
	
	//Queue found..
	//now lets add value into stack queue of 
	//check current count of stack...
	if (_stackQueue->_currentcount < _sizeofStack)
	{ 
		Stack * previousnode = _stackQueue->_CurrentStack;
		Stack * newStackNode = new Stack;
		newStackNode->Value = _value;
		newStackNode->Previous = previousnode;
		_stackQueue->_CurrentStack = newStackNode;
		_stackQueue->_currentcount += 1;
	}
	else
	{
		//this stack is full.. we need to create a new satack..
		QueueofStacks * previousnode = _stackQueue;
		QueueofStacks * newQueue = new QueueofStacks;
		newQueue->_currentcount = 0;
		newQueue->_CurrentStack = new Stack;
		newQueue->_Previous = previousnode;
		_stackQueue = newQueue; //StackQueue is the top of the new stack.

		//now lets add a value onto the stack..
		Stack * previousStacknode = _stackQueue->_CurrentStack;
		Stack * newStackNode = new Stack;
		newStackNode->Value = _value;
		newStackNode->Previous = previousStacknode;
		_stackQueue->_CurrentStack = newStackNode;
		_stackQueue->_currentcount += 1;
	}
}


