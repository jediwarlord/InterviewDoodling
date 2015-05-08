#include "LinkedList.h"

typedef struct _HashTable
{
	int size;
	int Buckets;
	DoubleList* List;

} HashTable;


struct entry_s {
	char *key;
	char *value;
	struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
	int size;
	struct entry_s **table;
};

typedef struct hashtable_s hashtable_t;




/* Create a new hashtable. */
hashtable_t *ht_create(int size);

/* Insert a key-value pair into a hash table. */
void ht_set(hashtable_t *hashtable, char *key, char *value);

/* Retrieve a key-value pair from a hash table. */
char *ht_get(hashtable_t *hashtable, char *key);

BOOL initHashTable(HashTable ** table, int Bucketsize);
int HaskKey(char * _key);
BOOL insetHashTable(HashTable* table, void * data);
BOOL lookupTable(HashTable* table, void * data);