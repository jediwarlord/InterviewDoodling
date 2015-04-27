// StringManipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	DoubleList * head = NULL;
	for (int i = 0; i < 6; i++)
	{
		InsertData(&head, (void *)i);
	}

	PrintList(head);


	return 0;
}

