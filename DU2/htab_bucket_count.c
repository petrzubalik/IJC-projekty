#include "htab.h"

unsigned int htab_bucket_count(htab_t *t)
{	// vrati pocet ukazatelu v tabulce 
	return t->arr_size;
}
