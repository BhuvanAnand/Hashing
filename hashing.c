#include "hashing.h"

/* create hash table */
void create_hashtable(hash_table_t** hashtable, int size){
	if(size < 1){
		/* invalid size for the hashtable */
		*hashtable = NULL;
		return;
	}

	/* allocate the memory for the hash table */
	*hashtable = (hash_table_t*)malloc(sizeof(hash_table_t));

	/* allocate the memory for the table */
	(*hashtable) ->table = (list_t**)malloc(sizeof(list_t*) * size);

	/* initialize the elements of the hash table */
	
	/* initialize the size */
	(*hashtable) ->size = size;

	/* initialize the table */
	int i = 0;
	for(i = 0; i < size; i++){
		(*hashtable) ->table[i] = NULL;	
	}
}

/* hashing function */
unsigned int hash(hash_table_t* hashtable, char* str){
	/* initialize the hash value */
	unsigned int hashval = 0;

	/* how to compute the hash value */
	/*
		1. for each character in the string multiply the old hash
		   by 31 and add the current character.
		2. multiplying is costly!!! so inorder to multiply the old
		   hash by 31, shift the old hash value by 5 which is 
		   equivalent to multiplying it by 32, so subtract it by 
		   old value. result is multiplying old value by 31.
		3. add the current char value to the hash.
	*/
	for(; (*str) != '\0'; str++){
		hashval = (*str) + ((hashval << 5) - hashval);
	}

	/* now return hashval % hashtable size so it will fit into 
	   necessary size */
	return (hashval % (hashtable ->size));
}	

/* lookup the hashtable */
list_t* lookup(hash_table_t* hashtable, char* str){
	list_t* list;

	/* get the hashvalue for the string */
	int hashval = hash(hashtable, str);
	
	/* go to the currect list based on the hashvalue 
	   in that list, find if the str is present.
	   if yes, return pointer to that node containing the string
	   if no, return null
	*/
	for(list = hashtable ->table[hashval]; list != NULL; list = list ->link){
		if(strcmp(str, list ->string) == 0){
			return list;
		}
	}
		
	/* string not found */
	return NULL;
}

/* insert to table */
void insert(hash_table_t** hashtable, char* str){
	list_t* node;
	list_t* exists;
	int hashval = hash((*hashtable), str);

	/* allocate the memory for the node */
	node = (list_t*)malloc(sizeof(list_t));

	/* check if the node already exist */
	exists = lookup((*hashtable), str);
	
	if(exists != NULL){
		/* node already exists */
		/* do nothing.. just return */
		return;
	}

	/* node doesnt exist, insert a new node */
	node ->string = strdup(str);
	node ->link = (*hashtable) ->table[hashval];
	(*hashtable) ->table[hashval] = node;
	
	return;
}

/* delete the table */
void delete_table(hash_table_t** hashtable){
	/* you have used the resource to create the table */
	/* its time to return it!! */

	int i = 0;
	list_t *list;
	list_t *temp;

	/* if hash table is empty */
	if((*hashtable) == NULL){
		return;
	}

	/* release all resources */
	for(i = 0; i < (*hashtable) ->size; i++){
		list = (*hashtable) ->table[i];

		/* free all node in the list */
		while(list != NULL){
			temp = list;
			list = list ->link;
			free(temp ->string);
			free(temp);
		}
	}

	/* now free the hash table */
	free((*hashtable) ->table);
	free((*hashtable));
	return;
}
