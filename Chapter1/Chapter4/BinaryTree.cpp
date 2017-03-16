#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>


TreeNode * NewNode(int _data)
{
	TreeNode * Node = (TreeNode *) malloc(sizeof(TreeNode));
	Node->Left = nullptr;
	Node->Right = NULL;
	Node->data = _data;
	return Node;
}

BOOL Insert(TreeNode * _Head, int _data)
{
	//check head value with value being inserted..
	if (_Head->data == _data)
	{
		//already there..
		return TRUE;
	}
	else if (_data < _Head->data)
	{
		//if left node is null insert value there otherwise call insert again..
		if (_Head->Left == NULL)
		{
			//insert here...
			_Head->Left = NewNode(_data);
		}
		else
		{
			Insert(_Head->Left, _data);
		}
	}
	else if (_data > _Head->data)
	{
		//if left node is null insert value there otherwise call insert again..
		if (_Head->Right == NULL)
		{
			//insert here...
			_Head->Right = NewNode(_data);
		}
		else
		{
			Insert(_Head->Right, _data);
		}
	}
	return TRUE;
}

int size(TreeNode * _Node)
{
	int _size = 0;

	if (_Node == NULL)
	{
		return 0;
	}

	//go down the left side..
	//root node is valid value..
	_size++;

	//now go down the left side..
	_size = _size + size(_Node->Left);
	_size = _size + size(_Node->Right);

	return _size;
}

int depth(TreeNode * _Node)
{
	//check how deep the binary tree is...
	int _intdepth = 0;
	int depth_left = 0;
	int depth_right = 0;

	if (_Node != NULL)
	{
		_intdepth += 1;
	}
	else
	{
		return 0;
	}

	depth_left = depth(_Node->Left);
	depth_right = depth(_Node->Right);

	if (depth_left >= depth_right)
	{
		return  depth_left + _intdepth;
	}
	else
	{
		return  depth_right + _intdepth;
	}

}

QueueNodes::QueueNodes(void)
{
	_stackQueue = NULL;
}

void QueueNodes::Push(TreeNode * _Node)
{
	//check Queustack is uninitialized
	if (!_stackQueue)
		//null
	{
		_stackQueue = new StackofNodes;
		_stackQueue->PreviousNode = NULL;
		_stackQueue->_Node = _Node;
		this->size++;
	}
	else //already initalized queue..
	{
		StackofNodes * NewValue = new StackofNodes;
		NewValue->PreviousNode = _stackQueue;
		NewValue->_Node = _Node;
		_stackQueue = NewValue;
		this->size++;
	}
}

bool QueueNodes::Empty()
{
	if (this->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

TreeNode * QueueNodes::front()
{
	if (this->_stackQueue == NULL) return NULL;
	return _stackQueue->_Node;
}

void QueueNodes::Pop()
{
	//check Queustack is uninitialized
	if (!_stackQueue)
		//null
	{
		return;
	}
	else //already initalized queue..so let's start popping.
	{
		StackofNodes * TempNode = _stackQueue->PreviousNode;
		free(_stackQueue);
		_stackQueue = TempNode;
		this->size--;
	}
}

void QueueNodes::Print()
{
	//check Queustack is uninitialized
	if (!_stackQueue)
		//null
	{
		printf("There is nothing here...\n");
		return;
	}
	else //already initalized queue..so let's start popping.
	{
		StackofNodes * PrintNode = _stackQueue;
		while (PrintNode)
		{
			printf("%d->", PrintNode->_Node->data);
			PrintNode = PrintNode->PreviousNode;
		}
	}
}




void printTree(TreeNode * _Node)
{
	//first lets get the depth of the tree..
	int _intdepth = depth(_Node);
	bool done = false;

	//check to see if head is null
	if (_Node == NULL)
	{
		return;
	}

	
	printf("\n");

	//check to see if 
	//print left node...
	printTree(_Node->Left);

	//print the right tree as well with 
	//print right node...
	printTree(_Node->Right);
	
}

void printTree_byLevel(TreeNode * _Node)
{
	//check to see if head is null
	if (_Node == NULL)
	{
		return;
	}

	QueueNodes currentLevel, nextLevel;

	currentLevel.Push(_Node); // pushing first level here...
	while (!currentLevel.Empty())
	{
		TreeNode * currNode = currentLevel.front();
		currentLevel.Pop();
		if (currNode)
		{
			printf("%d ", currNode->data);
			nextLevel.Push(currNode->Left);
			nextLevel.Push(currNode->Right);
		}
		if (currentLevel.Empty())
		{
			printf("\n");
			//swap out variables..
			QueueNodes Temp;
			Temp = currentLevel;
			currentLevel = nextLevel;
			nextLevel = Temp;
		}
	}



}

//this function is used to print indents for the tree.

void printIndents(int _intdepth, int value)
{
	for (; _intdepth > 0; --_intdepth)
	{
		printf("\t");
	}
	printf("%d",value);
}

