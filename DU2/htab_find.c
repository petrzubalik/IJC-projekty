#include <stdlib.h>
#include <string.h>
#include "htab.h"

htab_listitem * htab_find(htab_t *t, const char *key)
{	// vypocet indexu pomoci hashovaci funkce
	unsigned int index = hash_function(key) % t->arr_size;
	// ulozeni seznamu na danem indexu do pomcneho seznamu
	htab_listitem *tmp = t->htab_list[index];
	// pruchod celym seznamem 
	while(tmp != NULL)	
	{	// pokud naleznu prvek se stejnym klicem, vracim ho
		if ((strcmp(key, tmp->key)) == 0)
		{
			return tmp;
		}
		tmp = tmp->next;	// posun na dalsi prvek
	}
	// pokud prvek nenajdu, vracim NULL
	return NULL;
}
