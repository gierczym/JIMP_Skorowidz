#include <stdio.h>
#include <stdlib.h>

#include "dynamicword.h"

/*
typedef struct {
	char *word_string;
	int n_curr;
	int n_max;
	int *line_numbers_vect;
} *dynamic_word_t;

*/

dynamic_word_t init_dynamic_word( char *word_string, int n_max ) {

	dynamic_word_t dynamic_word = malloc( sizeof * dynamic_word );
	if( NULL == dynamic_word ) {
		fprintf( stderr, "init_dynamic_word: [!] nie udalo sie zaalokowac pamieci na typ dynamic_word_t\n" );
		return NULL;
	}

	dynamic_word->word_string = word_string;
	dynamic_word->n_curr = 0;
	dynamic_word->n_max = n_max;
	dynamic_word->line_numbers_vect = malloc( n_max * sizeof *dynamic_word->line_numbers_vect );
	if( NULL == dynamic_word->line_numbers_vect ) {
		fprintf( stderr, "init_dynamic_word: [!] nie udalo sie zaalokowac pamieci na typ line_numbers_vect\n" );
		return NULL;
	}

	return dynamic_word;
}


