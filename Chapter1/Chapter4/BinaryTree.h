#pragma once



struct TreeNode {
	int data;
	TreeNode * Left;
	TreeNode * Right;
};


struct QueueofNodes
{
	TreeNode * StackofNodes = NULL;
	int _currentcount;
	TreeNode * _Previous;
};

struct StackofNodes
{
	StackofNodes* PreviousNode = NULL;
	TreeNode * _Node;
};


class QueueNodes
{
public:
	QueueNodes(void);
	void Push(TreeNode * _Node);
	int Pop();
	int Min();
private:
	void PushValue(QueueofNodes * _Queue, int _value);
	int _sizeofStack = 5;
	int _numberofStacks = 0;
	QueueofNodes * _stackQueue = NULL;
};

struct 

TreeNode * NewNode(int _data);
BOOL Insert(TreeNode* _Head, int _data);

int size(TreeNode * _Node);

int depth(TreeNode * _Node);

void printTree(TreeNode * _Node);

void printTree_byLevel(TreeNode * _Node);

