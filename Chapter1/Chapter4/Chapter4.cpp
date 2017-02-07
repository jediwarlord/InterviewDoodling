// Chapter4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"

int main()
{
	TreeNode * Head = NewNode(3);

	Insert(Head, 4);
	Insert(Head, 1);

	int size_Head = size(Head);

    return 0;
}

