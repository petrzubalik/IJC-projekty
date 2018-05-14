/**
* Petr Zubalik - xzubal04, 1BIT
* steg-decode.c
* IJC - DU 1
* preklad - gcc 5.4.0 
*/

#include <stdio.h>
#include "error.h"
#include "bit_array.h"
#include "ppm.h"
#include "eratosthenes.h"
#include <ctype.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
	if (argc < 2 && argc > 3)
	{
		error_msg("Program na vstupu ocekava pouze 1 argument");
	}
	//vytvorim pomocne pole pro indexovani pomoci eratostenova sita
	ba_create(array, MAXLIMIT);
	eratosthenes(array);

	struct ppm *tmp = ppm_read(argv[1]);

	if (tmp != NULL)
	{
		;
	} else {
		error_msg("Soubor '%s' neni ve spravnem formatu 'P6' !", argv[1]);
	}
	
	// ch[2] je pomocna promenna (char)
	short ch[2] = {0};
	char konec = 0;
	int index = 0;
	for (int i = 0; tmp->data[i]; i++)
	{	//pokud je bit nastaven na 1, pokracuju dal v cyklu
		if (BA_GET_BIT_(array,i) == 1)
		{
			continue;
		}
		//pomoci vymaskovani ziskam LSB a ulozim ho na dany bit v pomocne promenne ch(char)
		BA_SET_BIT_(ch, index, tmp->data[i] & 1);
		
		index++;
		//jakmile mam vsech 8 bitu nastavenych, vytisknu znak 
		if (index == CHAR_BIT)
		{
			putchar(ch[1]);
			
			if (ch[1] == '\0')
			{	//pokud je znak '\0' ukoncim cyklus
				konec = '\0';
				break;
			}

			if (!isprint(ch[1]))
			{
				error_msg("Zprava obsahuje netisknutelne znaky");
			}

			index = 0;
			//putchar('\n');
		}

	}
	putchar('\n');
	if (konec != '\0')
	{
		error_msg("Zprava v souboru '%s' nebyla ukoncen znakem '\0'", argv[1]);
	}
	//uvolneni pameti
	free(tmp);

	return 0;
}
