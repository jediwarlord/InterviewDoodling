// Chapter4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"

int main()
{
	TreeNode * Head = NewNode(3);

	Insert(Head, 4);
	Insert(Head, 1);
	Insert(Head, 5);
	Insert(Head, 3);
	Insert(Head, 2);
	Insert(Head, 6);
	Insert(Head, 7);

	int size_Head = size(Head);
	int depthsize = depth(Head);

	printTree_byLevel(Head);

	printf("test\n");

    return 0;
}

