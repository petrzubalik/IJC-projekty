#include <stdio.h>
#include <stdlib.h>
#include "htab.h"

void htab_clear(htab_t *t)
{
	htab_listitem *tmp;
	for (unsigned int i = 0; i < t->arr_size; i++)
	{
		tmp = t->htab_list[i];

		if(tmp == NULL)
		{
			continue;
		}

		while(tmp != NULL)
		{
			htab_listitem *current = tmp;
			tmp = tmp->next;
			free(current);
			
		}
	}

}
