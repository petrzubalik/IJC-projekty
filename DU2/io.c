#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "io.h"
#include "htab.h"

int get_word(char *s, int max, FILE *f)
{	// pomocne promenne pro ulozeni slova
	int c = 0;	// nacitani znaku
	int i = 0;	// iterator
	int my_max = max - 1;	// maximalni delka slova
	int warning = 0;	// vypis varovani
	// nacitani jednoho slova
	while(((c = fgetc(f)) != EOF) && !(isspace(c)) && i < my_max )
	{	//ulozeni znaku do pole
		s[i] = c;
		i++;
	}
	// pokud je slovo delsi nez maximalni limit, vypisu jedno hlaseni a pokracuju
	if ((c != EOF) && (!isspace(c)) && (warning == 0))
	{
		// pokud je slovo delsi nez dany pocet znaku, vezme se jenom jeho orezana cast
		while(!isspace(c))
			c = fgetc(f);
		i = LIMIT ; // a vraci se maximalni delka + 1, aby se mohla vytisknout zprava
	}

	if (c == EOF)	
	{	// pokud narazim na konec souboru, vracim EOF
		return EOF;
	}
	// ukonceni retezce koncovou nulou 
	s[i] = '\0';
	
	// vraceni poctu znaku 
	return i;
}
