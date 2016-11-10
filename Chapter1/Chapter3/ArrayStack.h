#pragma once

class ArrayStack
{
private:
	int numberofstacks = 3;
	int Sizes[];
	int[] Values;
public:
	ArrayStack(int _stacksize);
};