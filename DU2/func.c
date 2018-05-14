#include <stdio.h>
#include "htab.h"

void print(const char *key, unsigned int *data)
{	// ulozeni poctu vyskytu do promenne
	unsigned int count = *data;
	printf("%s\t%u\n", key, count);		// tisk slova a pocet jeho vyskytu 
	return;
}