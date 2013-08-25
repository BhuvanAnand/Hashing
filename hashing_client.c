#include "hashing.h"

int main(int argc, char* argv[]){
	hash_table_t *hashtable;
	int size = 0;
	
	printf("enter the size of hash table\n");
	scanf("%d", &size);

	/* create the hashtable now */
	create_hashtable(&hashtable, size);

	insert(&hashtable, "bangalore");
	insert(&hashtable, "chitradurga");
	insert(&hashtable, "tumkur");
	insert(&hashtable, "mysore");
	insert(&hashtable, "belgaum");


	/* lookup for an string */
	printf("is bangalore present: %s\n", (lookup(hashtable, "bangalore") != NULL)? "yes": "no");
	printf("is mangalore present: %s\n", (lookup(hashtable, "mangalore") != NULL)? "yes": "no");

	/* finally delete the table */
	delete_table(&hashtable);

	return 0;
}
