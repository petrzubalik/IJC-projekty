#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "htab.h"

htab_listitem * htab_lookup_add(htab_t *t, const char *key)
{	// vypocitani hashe
	unsigned int hash = hash_function(key);
	hash = hash % t->arr_size;
	// ulozeni seznamu prvku do pomocneho seznamu	
	htab_listitem *tmp = t->htab_list[hash];
	//pruchod seznamem
	while(tmp != NULL)
	{	
		if ((strcmp(tmp->key, key)) == 0)
		{	// pokud se klice shoduji, inkrementuju pocet vyskytu a vracim prvek
			tmp->data += 1; 
			return tmp;
		}
		if (tmp->next == NULL)
		{	// prvek se stejnym klicem nenalezen
			break;
		}
		// posun na dalsi prvek
		tmp = tmp->next; 
	}
	//alokace noveho prvku	
	htab_listitem *item = malloc(sizeof(htab_listitem));

	if (item == NULL)
	{	// alokace se nezdarila, vracim NULL
		return NULL;
	}
	// zkopirovani hledaneho klice do prvku
	strncpy(item->key, key, strlen(key));
	item->data = 1; // nastaveni poctu vyskytu na 1

	if (tmp != NULL)
	{	// zarazeni na konec seznamu
		tmp->next = item;
	} else { 
		t->htab_list[hash] = item;	// zarazeni na konec seznamu
	}
	// vraceni nalezeneho nebo noveho prvku
	return item;
}
