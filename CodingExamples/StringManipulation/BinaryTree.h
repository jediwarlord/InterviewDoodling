#include "LinkedList.h"


typedef struct _BinaryNode
{
	int data;
	_BinaryNode * Left;
	_BinaryNode * Right;
} BinaryNode;

typedef struct Tree Tree;

struct Tree
{
	Tree * left, *right;
	int element;
};


bool insertBinaryNode(int _data, Tree** _RootNode);
void print_ascii_tree(Tree * t);
void PreOrderTree(Tree* Node, int* size);