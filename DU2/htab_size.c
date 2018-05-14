#include "htab.h"
#include <stdlib.h>

unsigned int htab_size(htab_t *t)
{
	unsigned int n = 0;
	htab_listitem *tmp; 
	// projde tabulku a pro kazdy prvek v tabulce inkrementuje 'n'
	for (unsigned int i = 0; i < t->arr_size; i++)
	{
		tmp = t->htab_list[i];
		while(tmp != NULL)
		{
			n++;
			tmp = tmp->next;
		}
	}
	// po pruchodu tabulkou vrati pocet prvku 
	return n;
}
