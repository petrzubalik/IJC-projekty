/** 
 * Petr Zubalik - xzubal04@stud.fit.vutbr.cz
 * tail.c
 * IJC - DU2
 * prelozeno - gcc 5.4.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1024+1 // implementacni limit pro delku radku (+'\n')

void my_tail(FILE *f, int n);

int main(int argc, char const *argv[])
{
	int n = 10;
	FILE *f = stdin;

	if (argc > 4)
	{
		fprintf(stderr, "Zadan spatny pocet parametru!\n");
		return -1;
	} else if (argc == 2)
	{
		if ((f = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr, "Soubor '%s' se nepodarilo otevrit!\n", argv[1]);
			return -1;
		}
	} else if (argc == 4)
	{		
		if (strcmp(argv[1], "-n") == 0)
		{
			n = (int) strtol(argv[2], NULL, 10);
		} else {
			fprintf(stderr, "Ocekavany argument je '-n' s parametrem 'cele_kladne_cislo'!\n");
			return -1;
		}
		if (n < 0)
		{
			fprintf(stderr, "Zadany pocet radku nemuze byt zaporny!\n");
			return -1;
		}
		if ((f = fopen(argv[3],"r")) == NULL)
		{
			fprintf(stderr, "Soubor '%s' se nepodarilo otevrit!\n", argv[3]);
			return -1;
		}
	}
	
	my_tail(f, n);
	fclose(f);

	return 0;
}

void my_tail(FILE *filename, int n)
{
	char tmp_arr[LIMIT];
	char **array;
	int count = 0;
	
	while((fgets(tmp_arr, LIMIT, filename)) != NULL)
		count++;

	array = (char **) malloc(n * sizeof(char *));
	for (int i = 0; i < n; i++)
	{
		array[i] = malloc(LIMIT*sizeof(char));
	}

	rewind(filename);
	int index = 0;
	while((fgets(array[index], LIMIT, filename)) != NULL)
	{
		index++;
		
		if (index == n)
		{
			index = 0;
		}
	}
	
	if(count <= n)
	{	
		for (int j = 0; j < count; j++)
		{
			printf("%s", array[j]);
		}
	} else {
		int counter = 0;
		int reset = 0;
		for (int k = 0; k < n; k++)
		{	
			printf("%s", array[index]);
			index++;
			counter++;
			if ((index == n) && (reset == 0))
			{	
				reset = 1;
				index = 0;
			}
		}
	}
	
	for(int i = 0; i < n; i++)
		free(array[i]);

	free(array);


	return;
}