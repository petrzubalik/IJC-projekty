#include <stdbool.h>

#ifndef HTAB_H
#define HTAB_H

#define LIMIT (127+1)	// implementacni limit pro delku slova
// struktura pro jednotlive prvky tabulky
typedef struct htab_item {
	unsigned int data;
	struct htab_item *next;
	char key[LIMIT];
} htab_listitem; 
// struktura pro tabulku
typedef struct htab {
	unsigned int arr_size;
	htab_listitem *htab_list[];
} htab_t;
// hashovaci funkce pro ziskani indexu
unsigned int hash_function(const char *); 
// funkce inicializuje tabulku 
htab_t * htab_init(unsigned int);
// presune data z jedne tabulky do druhe (ktera se vytvori)
htab_t * htab_move(unsigned int, htab_t *);
// zjisti pocet prvku tabulky
unsigned int htab_size(htab_t *);
// vraci pocet ukazatelu v poli ukazatelu
unsigned int htab_bucket_count(htab_t *);
// vyhleda v tabulce prvek podle daneho klice nebo ho vytvori
htab_listitem * htab_lookup_add(htab_t *, const char *);
// vyhleda prvek
htab_listitem * htab_find(htab_t *, const char *);
// pro kazdy prvek tabulky zavola funkci 'print', ktera vytiskne jeho data
void htab_foreach(htab_t *, void (*func)(const char *, unsigned int *));
// odstrani prvek z tabulky 
bool htab_remove(htab_t *, char *);
// zrusi vsechny prvky tabulky, tabulka zustane prazdna
void htab_clear(htab_t *);
// destruktor tabulky
void htab_free(htab_t *);
// tiskne data na stdout
void print(const char *, unsigned int *);

#endif /* HTAB_H */