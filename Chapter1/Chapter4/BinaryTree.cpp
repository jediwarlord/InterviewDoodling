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

	printIndents(_intdepth, _Node->data);
	printf("\n");

	//check to see if 
	//print left node...
	printTree(_Node->Left);

	//print the right tree as well with 
	//print right node...
	printTree(_Node->Right);
	
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

