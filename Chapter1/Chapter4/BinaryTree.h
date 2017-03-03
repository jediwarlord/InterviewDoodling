#pragma once



struct TreeNode {
	int data;
	TreeNode * Left;
	TreeNode * Right;
};

TreeNode * NewNode(int _data);
BOOL Insert(TreeNode* _Head, int _data);

int size(TreeNode * _Node);

int depth(TreeNode * _Node);

void printTree(TreeNode * _Node);