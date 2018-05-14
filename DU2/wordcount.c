#include "htab.h"
#include "io.h"
#include <stdio.h>
#include <stdbool.h>
/* 	velikost pole ukazatelu -- zalezi na velikosti zpracovavanych dat,
	cim vetsi toto pole bude, tim rychleji se bude v tabulce vyhledavat. 
	V dnesni dobe neni nedostatek pameti velkym problemem, takze muzeme volit
	velikost tabulky velkou.
*/
#define TAB_SIZE 1000

int main()
{	
	htab_t *table;
	char s[LIMIT] = {0};
	int my_max = LIMIT - 1;
	int word = 0;
	int warning = 0;

	FILE *f = stdin;
	
	table = htab_init(TAB_SIZE);	
	while (1)
	{	// ziskani slova 
		word = get_word(s, LIMIT, f);
		if (word == LIMIT && warning == 0)
		{
			fprintf(stderr, "Nacitane slovo bylo delsi nez '%d' znaku, bude se pokracovat se slovy orezanymy!\n", my_max);
			warning = 1;
		}
		if (s[0] != '\0')
		{	// pridani do tabulky
			htab_lookup_add(table, s);
		} else {
			continue; 
		}
		// pokud narazim na EOF, koncim cyklus
		if (word == EOF)
		{
			break;
		}
	}
	// volani funkce pro kazdy prvek tabulky
	htab_foreach(table, print);
	// uvolneni pameti
	htab_free(table);

	return 0;
}
