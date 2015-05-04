#include "stdafx.h"

BOOL initHashTable(HashTable ** table, int Bucketsize)
{
	if ((*table = (HashTable *) malloc(sizeof(HashTable))) == NULL)
		return FALSE;

	(*table)->Buckets = Bucketsize;

	//initialize the buckets in the table

	(*table)->List = (DoubleList *) malloc(sizeof(DoubleList));

	for (int i = 0; i < Bucketsize; i++)
	{
		InitDoubleList(&((*table)->List[i]));
	}
	return TRUE;

}