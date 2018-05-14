#include <stdlib.h>
#include "htab.h"

htab_t * htab_init(unsigned int size)
{	//alokace pameti pro tabulku
	htab_t *hash_table = malloc(sizeof(*hash_table) + size * sizeof(hash_table->htab_list[0]));
	
	if (hash_table == NULL) 
	{	// pokud se nepodari alokovat pamet vypise err hlaseni a vrati NULL
		return NULL;
	}
	//ulozeni velikosti do tabulky
	hash_table->arr_size = size;

	
	for (unsigned int i = 0; i < size; i++)
	{	// kazdy ukazatel v poli je prazdny
		hash_table->htab_list[i] = NULL;
	}
	// vraceni alokovane tabulky
	return hash_table;
}
