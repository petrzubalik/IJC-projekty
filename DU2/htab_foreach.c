#include <stdlib.h>
#include "htab.h"

void htab_foreach(htab_t *t, void (*func)(const char *key, unsigned int *data))
{	// pruchod polem ukazatelu 
	for (unsigned int i = 0; i < t->arr_size; i++)
	{	// ulozeni seznamu prvku do pomocneho seznamu
		htab_listitem * tmp = t->htab_list[i];
		// pruchod seznamem
		while(tmp != NULL)
		{	// pro kazdy prvek seznamu volam funkci 'print'
			func(tmp->key, &(tmp->data));
			tmp = tmp->next; // posun na dalsi prvek
		}
	}

	return;
}
