#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* start declaring the list structure */
struct node{
	char* string;
	struct node* link;
};

typedef struct node list_t;

/* declaring hash structure */
struct hash_table{
	int size;	
	list_t **table;
};

typedef struct hash_table hash_table_t;

/* what all operations we can do on an hash table */
/*	1. create a hashtable
	2. more important one.. implement a better hash function
	3. should be able to free a table
	4. inserting a number of elements
	5. looking up for an element in the table
*/

/* prototypes for all above functions */

/* creating a hash table */
void create_hashtable(hash_table_t** hastable, int size);

/* hash function */
unsigned int hash(hash_table_t* hashtable,char* str);

/* looup in a hash table */
list_t* lookup(hash_table_t* hashtable, char* str);

/* inserting a string to the hash table */
void insert(hash_table_t** hashtable, char* str);

/* delete the table*/
void delete_table(hash_table_t** hashtable);
