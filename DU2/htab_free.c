#include <stdlib.h>
#include "htab.h"

void htab_free(htab_t * t)
{	// uvolneni obsahu tabulky
	htab_clear(t);
	// uvolneni tabulky samotne 
	free(t);
}
