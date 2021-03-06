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




char * strdup(const char * s)
{
	size_t len = 1 + strlen(s);
	char *p = NULL;
	p = (char *) malloc(len);

	if (p == NULL)
	{
		return NULL;

	}
	else
	{
		return (char *) memcpy(p, s, len);
	}
	
}

hashtable_t *ht_create(int size) {

	hashtable_t *hashtable = NULL;
	int i;

	if (size < 1) return NULL;

	/* Allocate the table itself. */
	if ((hashtable = (hashtable_t *)malloc(sizeof(hashtable_t))) == NULL) {
		return NULL;
	}

	/* Allocate pointers to the head nodes. */
	if ((hashtable->table = (entry_s **) malloc(sizeof(entry_t *) * size)) == NULL) {
		return NULL;
	}
	for (i = 0; i < size; i++) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;
}

/* Hash a string for a particular hash table. */
int ht_hash(hashtable_t *hashtable, char *key) {

	unsigned long int hashval = 0;
	int i = 0;

	/* Convert our string to an integer */
	while (hashval < ULONG_MAX && i < strlen(key)) {
		hashval = hashval << 8;
		hashval += key[i];
		i++;
	}

	return hashval % hashtable->size;
}

/* Create a key-value pair. */
entry_t *ht_newpair(char *key, char *value) {
	entry_t *newpair;

	if ((newpair = (entry_s *) malloc(sizeof(entry_t))) == NULL) {
		return NULL;
	}

	if ((newpair->key = _strdup(key)) == NULL) {
		return NULL;
	}

	if ((newpair->value = _strdup(value)) == NULL) {
		return NULL;
	}

	newpair->next = NULL;

	return newpair;
}


bool ht_insertList(hashtable_t *hashtable, entry_s ** Bucket, entry_s *NewValue, int bin)
{
	//insert new key value pair in the list. 
	entry_s * temp = NULL;
	entry_s * last = NULL;

	//check to see if the list is in the beginning.
	if (*Bucket == NULL)
	{
		//we're eat the beginning of this bucket.
		*Bucket = NewValue;
		NewValue->next = NULL;
		hashtable->table[bin] = *Bucket;
	}
	else
	{
		//find the last node in this bucket at add or replace existing entry 
		//with the newValue if it already exists.
		temp = *Bucket; // start of the node.
		while (temp != NULL)
		{
			//check to see if is a duplicate for a key
			if (temp->key != NULL && strcmp(NewValue->key, temp->key) == 0)
			{
				//there is a duplicate so lets replace it here and return from here as well.
				//free the key value pair but replicate it's links first.
				free(temp->value);
				temp->value = _strdup(NewValue->value);
				free(NewValue->key);
				free(NewValue->value);
				free(NewValue);
				return 0;
				break;
			}
			else
			{ // no duplicate on this iteration so keep going till the end of the list
				last = temp; // track the last node we moved from
				temp = temp->next;
			}

		} //exiting means we have found the end of the list and should add it here

		//growing a pair ;) 
		last->next = NewValue;
		NewValue->next = NULL;

		//increase the size of the hash table. 
		hashtable->size++;
		return 0;
	}



}



/* Insert a key-value pair into a hash table. */
void ht_set(hashtable_t *hashtable, char *key, char *value) {
	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;

	bin = ht_hash(hashtable, key);



	next = hashtable->table[bin];

	ht_insertList(hashtable, &next, ht_newpair(key, value), bin);

	//while (next != NULL && next->key != NULL && strcmp(key, next->key) > 0) {
	//	last = next;
	//	next = next->next;
	//}

	///* There's already a pair.  Let's replace that string. */
	//if (next != NULL && next->key != NULL && strcmp(key, next->key) == 0) {

	//	free(next->value);
	//	next->value = _strdup(value);

	//	/* Nope, could't find it.  Time to grow a pair. */
	//}
	//else {
	//	newpair = ht_newpair(key, value);

	//	/* We're at the start of the linked list in this bin. */
	//	if (next == hashtable->table[bin]) {
	//		newpair->next = next;
	//		hashtable->table[bin] = newpair;

	//		/* We're at the end of the linked list in this bin. */
	//	}
	//	else if (next == NULL) {
	//		last->next = newpair;

	//		/* We're in the middle of the list. */
	//	}
	//	else  {
	//		newpair->next = next;
	//		last->next = newpair;
	//	}
	//}
}

/* Retrieve a key-value pair from a hash table. */
char *ht_get(hashtable_t *hashtable, char *key) {
	int bin = 0;
	entry_t *pair;

	bin = ht_hash(hashtable, key);

	/* Step through the bin, looking for our value. */
	pair = hashtable->table[bin];
	while (pair != NULL && pair->key != NULL && strcmp(key, pair->key) > 0) {
		pair = pair->next;
	}

	/* Did we actually find anything? */
	if (pair == NULL || pair->key == NULL || strcmp(key, pair->key) != 0) {
		return NULL;

	}
	else {
		return pair->value;
	}

}