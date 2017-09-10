#pragma once

#include "BasicLinkedList.h"

//Describe how you could use a single array to implement three stacks.

void push(int StackNum, int value);

bool StackFull(int StackNum);

int GetBufferIndex(int _StackNum);

int peekValue(int _StackNum);

int pop(int StackNum);

bool isEmpty(int StackNum);