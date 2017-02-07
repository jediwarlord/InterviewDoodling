#include "stdafx.h"
#include "BinaryTree.h"


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


