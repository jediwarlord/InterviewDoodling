#include "LinkedList.h"

typedef struct _HashTable
{
	int size;
	int Buckets;
	DoubleList* List;

} HashTable;

BOOL initHashTable(HashTable ** table, int Bucketsize);
int HaskKey(char * _key);
BOOL insetHashTable(HashTable* table, void * data);
BOOL lookupTable(HashTable* table, void * data);