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
		fprintf( stderr, "init_dynamic_word: [!] nie udalo sie zaalokowac pamieci na line_numbers_vect\n" );
		return NULL;
	}

	return dynamic_word;
}

int add_to_dynamic_word( dynamic_word_t word_in, int line_number ) {
	if ( word_in->n_curr == word_in->n_max ) {
		int *tmp = realloc( word_in->line_numbers_vect, 2 * word_in->n_max * sizeof *word_in->line_numbers_vect );
		if( NULL == tmp ) {
			fprintf( stderr, "add_to_dynamic_word: [!] nie udalo sie zaalokowac pamieci na line_numbers_vect\n" );
			return 1;
		}
		word_in->n_max = 2 * word_in->n_max;
		word_in->line_numbers_vect = tmp;
		word_in->line_numbers_vect[word_in->n_curr] = line_number;
		word_in->n_curr++;
	} else {
		word_in->line_numbers_vect[word_in->n_curr] = line_number;
		word_in->n_curr++;
	}
	
	return 0;
	
}

void disp_dynamic_word( dynamic_word_t word_in ) {
	if( 0 == word_in->n_curr ) {
		printf( "Nie znaleziono slowa \"%s\"\n", word_in->word_string );
	} else {
		printf( "Slowo \"%s\" znaleziono %d-razy, numery linii: [", word_in->word_string, word_in->n_curr );
		int i;
		for( i = 0; i < word_in->n_curr; i++ ) {
			printf( " %d", word_in->line_numbers_vect[i] );
		}
		printf( " ]\n" );
	}
}

void destroy_dynamic_word( dynamic_word_t word_in ) {
	free( word_in->line_numbers_vect );
	free( word_in );
}
