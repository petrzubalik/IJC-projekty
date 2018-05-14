#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "htab.h"

bool htab_remove(htab_t *t, char *key)
{	// vypocitani indexu pomoci hashovaci funkce
	unsigned int index = hash_function(key) % t->arr_size;
	// ulozeni seznamu do pomocneho seznamu
	htab_listitem * tmp = t->htab_list[index];
	htab_listitem * previous = t->htab_list[index];	
	// pruchod seznamem
	while(tmp != NULL)
	{
		// pokud se neshoduji klice, jedu dal
		if ((strcmp(tmp->key, key)) != 0)
		{
			previous = tmp;
			tmp = tmp->next;
		} else 
		{	
			

			previous->next = tmp->next;
			
			return true;
		}
	}
	return false;

}
