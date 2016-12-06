#include "stdafx.h"
#include "33Header.h"

StackO1::StackO1(void)
{
	_stackCurrent = NULL;
	_MinCurrent = NULL;
}

void StackO1::Push(int _value)
{
	//put value on top of stack..
	stackNode * tempstack = new stackNode;

	//first item in stack..
	if (_stackCurrent == NULL)
	{
		_stackCurrent = new stackNode;
		_stackCurrent->value = _value;
		_stackCurrent->Previous = NULL;

		_MinCurrent = new MinNode;
		_MinCurrent->MinValue = _value;
		_MinCurrent->Previous = NULL;
	}
	else // there are already nodes in there...
	{
		stackNode * _NewNode = new stackNode;

		_NewNode->value = _value;
		_NewNode->Previous = _stackCurrent;
		_stackCurrent = _NewNode;

		//check if new value is lesss than last min and if so append on it..
		if (_value < _MinCurrent->MinValue)
		{
			MinNode * _NewMinNode = new MinNode;

			_NewMinNode->MinValue = _value;
			_NewMinNode->Previous = _MinCurrent;
			_MinCurrent = _NewMinNode;
		}
	}

}

int StackO1::Pop()
{
	int valuetoreturn = NULL;
	stackNode * temp = NULL;
	MinNode * Mintemp = NULL;

	if (_stackCurrent == NULL)
	{
		//empty stack.. return NULL
		return NULL;
	}

	//not empty... return value and move pointers.remember to also check for min value
	valuetoreturn = _stackCurrent->value;
	temp = _stackCurrent;
	_stackCurrent = _stackCurrent->Previous;
	free(temp);

	//now check for the min value
	if (valuetoreturn == _MinCurrent->MinValue)
	{
		//this was the last min ..pop it.
		Mintemp = _MinCurrent;
		_MinCurrent = _MinCurrent->Previous;
		free(Mintemp);
	}

	return valuetoreturn;
}

int StackO1::Min()
{
	return _MinCurrent->MinValue;
}


