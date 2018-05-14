#include "htab.h"
#include <stdlib.h>

htab_t * htab_move(unsigned int newsize, htab_t *t2)
{	// inicializace nove tabulky
	htab_t *table = htab_init(newsize);
	//pomocne promenne pro ukladani dat
	htab_listitem *item;	
	htab_listitem *tmp;
	// cyklus na pruchod vsech prvku v poli ukazatelu
	for (unsigned int i = 0; i < t2->arr_size; i++)
	{
		tmp = t2->htab_list[i];
		// pruchod seznamu prvku
		while(tmp != NULL)
		{	// vytvoreni prvku v tabulce
			item = htab_lookup_add(table, tmp->key);
			item->data = tmp->data;	// zkopirovani dat 
			// posun na dalsi prvek
			tmp = tmp->next;
		}
	}
	// vymazani prvku z puvodni tabulky
	htab_clear(t2);
	// vraceni nove tabulky
	return table;


}
