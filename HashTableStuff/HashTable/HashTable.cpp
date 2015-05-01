// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "chtbl.h"
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
*                                                                            *
*  Define the size of the chained hash table.                                *
*                                                                            *
*****************************************************************************/

#define            TBLSIZ               11

/*****************************************************************************
*                                                                            *
*  ------------------------------ chtbl_init ------------------------------  *
*                                                                            *
*****************************************************************************/

int chtbl_init(CHTbl *htbl, int buckets, int(*h)(const void *key), int
	(*match)(const void *key1, const void *key2), void(*destroy)(void*data)) {

	int                i;

	/*****************************************************************************
	*                                                                            *
	*  Allocate space for the hash table.                                        *
	*                                                                            *
	*****************************************************************************/

	if ((htbl->table = (List *)malloc(buckets * sizeof(List))) == NULL)
		return -1;

	/*****************************************************************************
	*                                                                            *
	*  Initialize the buckets.                                                   *
	*                                                                            *
	*****************************************************************************/

	htbl->buckets = buckets;

	for (i = 0; i < htbl->buckets; i++)
		list_init(&htbl->table[i], destroy);

	/*****************************************************************************
	*                                                                            *
	*  Encapsulate the functions.                                                *
	*                                                                            *
	*****************************************************************************/

	htbl->h = h;
	htbl->match = match;
	htbl->destroy = destroy;

	/*****************************************************************************
	*                                                                            *
	*  Initialize the number of elements in the table.                           *
	*                                                                            *
	*****************************************************************************/

	htbl->size = 0;

	return 0;

}

/*****************************************************************************
*                                                                            *
*  ---------------------------- chtbl_destroy -----------------------------  *
*                                                                            *
*****************************************************************************/

void chtbl_destroy(CHTbl *htbl) {

	int                i;

	/*****************************************************************************
	*                                                                            *
	*  Destroy each bucket.                                                      *
	*                                                                            *
	*****************************************************************************/

	for (i = 0; i < htbl->buckets; i++) {

		list_destroy(&htbl->table[i]);

	}

	/*****************************************************************************
	*                                                                            *
	*  Free the storage allocated for the hash table.                            *
	*                                                                            *
	*****************************************************************************/

	free(htbl->table);

	/*****************************************************************************
	*                                                                            *
	*  No operations are allowed now, but clear the structure as a precaution.   *
	*                                                                            *
	*****************************************************************************/

	memset(htbl, 0, sizeof(CHTbl));

	return;

}

/*****************************************************************************
*                                                                            *
*  ----------------------------- chtbl_insert -----------------------------  *
*                                                                            *
*****************************************************************************/

int chtbl_insert(CHTbl *htbl, const void *data) {

	void               *temp;

	int                bucket,
		retval;

	/*****************************************************************************
	*                                                                            *
	*  Do nothing if the data is already in the table.                           *
	*                                                                            *
	*****************************************************************************/

	temp = (void *)data;

	if (chtbl_lookup(htbl, &temp) == 0)
		return 1;

	/*****************************************************************************
	*                                                                            *
	*  Hash the key.                                                             *
	*                                                                            *
	*****************************************************************************/

	bucket = htbl->h(data) % htbl->buckets;

	/*****************************************************************************
	*                                                                            *
	*  Insert the data into the bucket.                                          *
	*                                                                            *
	*****************************************************************************/

	if ((retval = list_ins_next(&htbl->table[bucket], NULL, data)) == 0)
		htbl->size++;

	return retval;

}

/*****************************************************************************
*                                                                            *
*  ----------------------------- chtbl_remove -----------------------------  *
*                                                                            *
*****************************************************************************/

int chtbl_remove(CHTbl *htbl, void **data) {

	ListElmt           *element,
		*prev;

	int                bucket;

	/*****************************************************************************
	*                                                                            *
	*  Hash the key.                                                             *
	*                                                                            *
	*****************************************************************************/

	bucket = htbl->h(*data) % htbl->buckets;

	/*****************************************************************************
	*                                                                            *
	*  Search for the data in the bucket.                                        *
	*                                                                            *
	*****************************************************************************/

	prev = NULL;

	for (element = list_head(&htbl->table[bucket]); element != NULL; element =
		list_next(element)) {

		if (htbl->match(*data, list_data(element))) {

			/***********************************************************************
			*                                                                      *
			*  Remove the data from the bucket.                                    *
			*                                                                      *
			***********************************************************************/

			if (list_rem_next(&htbl->table[bucket], prev, data) == 0) {

				htbl->size--;
				return 0;

			}

			else {

				return -1;

			}

		}

		prev = element;

	}

	/*****************************************************************************
	*                                                                            *
	*  Return that the data was not found.                                       *
	*                                                                            *
	*****************************************************************************/

	return -1;

}

/*****************************************************************************
*                                                                            *
*  ----------------------------- chtbl_lookup -----------------------------  *
*                                                                            *
*****************************************************************************/

int chtbl_lookup(const CHTbl *htbl, void **data) {

	ListElmt           *element;

	int                bucket;

	/*****************************************************************************
	*                                                                            *
	*  Hash the key.                                                             *
	*                                                                            *
	*****************************************************************************/

	bucket = htbl->h(*data) % htbl->buckets;

	/*****************************************************************************
	*                                                                            *
	*  Search for the data in the bucket.                                        *
	*                                                                            *
	*****************************************************************************/

	for (element = list_head(&htbl->table[bucket]); element != NULL; element =
		list_next(element)) {

		if (htbl->match(*data, list_data(element))) {

			/***********************************************************************
			*                                                                      *
			*  Pass back the data from the table.                                  *
			*                                                                      *
			***********************************************************************/

			*data = list_data(element);
			return 0;

		}

	}

	/*****************************************************************************
	*                                                                            *
	*  Return that the data was not found.                                       *
	*                                                                            *
	*****************************************************************************/

	return -1;

}


//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}




/*****************************************************************************
*                                                                            *
*  ------------------------------ match_char ------------------------------  *
*                                                                            *
*****************************************************************************/



static int match_char(const void *char1, const void *char2) {

	/*****************************************************************************
	*                                                                            *
	*  Compare two characters.                                                   *
	*                                                                            *
	*****************************************************************************/

	return (*(const char *)char1 == *(const char *)char2);

}

/*****************************************************************************
*                                                                            *
*  -------------------------------- h_char --------------------------------  *
*                                                                            *
*****************************************************************************/

static int h_char(const void *key) {

	/*****************************************************************************
	*                                                                            *
	*  Define a simplistic hash function.                                        *
	*                                                                            *
	*****************************************************************************/

	return *(const char *)key % TBLSIZ;

}

/*****************************************************************************
*                                                                            *
*  ------------------------------ print_table -----------------------------  *
*                                                                            *
*****************************************************************************/

static void print_table(const CHTbl *htbl) {

	ListElmt           *element;

	int                i;

	/*****************************************************************************
	*                                                                            *
	*  Display the chained hash table.                                           *
	*                                                                            *
	*****************************************************************************/

	fprintf(stdout, "Table size is %d\n", chtbl_size(htbl));

	for (i = 0; i < TBLSIZ; i++) {

		fprintf(stdout, "Bucket[%03d]=", i);

		for (element = list_head(&htbl->table[i]); element != NULL; element =
			list_next(element)) {

			fprintf(stdout, "%c", *(char *)list_data(element));

		}

		fprintf(stdout, "\n");

	}

	return;

}

/*****************************************************************************
*                                                                            *
*  --------------------------------- main ---------------------------------  *
*                                                                            *
*****************************************************************************/

int main(int argc, char **argv) {

	CHTbl              htbl;

	char               *data,
		c;

	int                retval,
		i;

	/*****************************************************************************
	*                                                                            *
	*  Initialize the chained hash table.                                        *
	*                                                                            *
	*****************************************************************************/

	if (chtbl_init(&htbl, TBLSIZ, h_char, match_char, free) != 0)
		return 1;

	/*****************************************************************************
	*                                                                            *
	*  Perform some chained hash table operations.                               *
	*                                                                            *
	*****************************************************************************/

	for (i = 0; i < TBLSIZ; i++) {

		if ((data = (char *)malloc(sizeof(char))) == NULL)
			return 1;

		*data = ((5 + (i * 6)) % 23) + 'A';

		if (chtbl_insert(&htbl, data) != 0)
			return 1;

		print_table(&htbl);

	}

	for (i = 0; i < TBLSIZ; i++) {

		if ((data = (char *)malloc(sizeof(char))) == NULL)
			return 1;

		*data = ((3 + (i * 4)) % 23) + 'a';

		if (chtbl_insert(&htbl, data) != 0)
			return 1;

		print_table(&htbl);

	}

	if ((data = (char *)malloc(sizeof(char))) == NULL)
		return 1;

	*data = 'd';

	if ((retval = chtbl_insert(&htbl, data)) != 0)
		free(data);

	fprintf(stdout, "Trying to insert d again...Value=%d (1=OK)\n", retval);

	if ((data = (char *)malloc(sizeof(char))) == NULL)
		return 1;

	*data = 'G';

	if ((retval = chtbl_insert(&htbl, data)) != 0)
		free(data);

	fprintf(stdout, "Trying to insert G again...Value=%d (1=OK)\n", retval);

	fprintf(stdout, "Removing d, G, and S\n");

	c = 'd';
	data = &c;

	if (chtbl_remove(&htbl, (void **)&data) == 0)
		free(data);

	c = 'G';
	data = &c;

	if (chtbl_remove(&htbl, (void **)&data) == 0)
		free(data);

	c = 'S';
	data = &c;

	if (chtbl_remove(&htbl, (void **)&data) == 0)
		free(data);

	print_table(&htbl);

	if ((data = (char *)malloc(sizeof(char))) == NULL)
		return 1;

	*data = 'd';

	if ((retval = chtbl_insert(&htbl, data)) != 0)
		free(data);

	fprintf(stdout, "Trying to insert d again...Value=%d (0=OK)\n", retval);

	if ((data = (char *)malloc(sizeof(char))) == NULL)
		return 1;

	*data = 'G';

	if ((retval = chtbl_insert(&htbl, data)) != 0)
		free(data);

	fprintf(stdout, "Trying to insert G again...Value=%d (0=OK)\n", retval);

	print_table(&htbl);

	fprintf(stdout, "Inserting X and Y\n");

	if ((data = (char *)malloc(sizeof(char))) == NULL)
		return 1;

	*data = 'X';

	if (chtbl_insert(&htbl, data) != 0)
		return 1;

	if ((data = (char *)malloc(sizeof(char))) == NULL)
		return 1;

	*data = 'Y';

	if (chtbl_insert(&htbl, data) != 0)
		return 1;

	print_table(&htbl);

	c = 'X';
	data = &c;

	if (chtbl_lookup(&htbl, (void **)&data) == 0)
		fprintf(stdout, "Found an occurrence of X\n");
	else
		fprintf(stdout, "Did not find an occurrence of X\n");

	c = 'Z';
	data = &c;

	if (chtbl_lookup(&htbl, (void **)&data) == 0)
		fprintf(stdout, "Found an occurrence of Z\n");
	else
		fprintf(stdout, "Did not find an occurrence of Z\n");

	/*****************************************************************************
	*                                                                            *
	*  Destroy the chained hash table.                                           *
	*                                                                            *
	*****************************************************************************/

	fprintf(stdout, "Destroying the hash table\n");
	chtbl_destroy(&htbl);

	return 0;

}


