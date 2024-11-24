#include <stdio.h>
#include <stdlib.h>

#include "dynamicword.h"
#include "indextable.h"

/*
typedef struct {
	int n_curr;
	int n_max;
	dynamic_word_t *words;
} *index_table_t;
*/

index_table_t init_index_table( int n_max ) {
	index_table_t index_table = malloc( sizeof * index_table );
	if( NULL == index_table ) {
		fprintf( stderr, "init_index_table: [!] nie udalo sie zaalokowac pamieci na typ index_table_t\n" );
		return NULL;
	}
	index_table->n_curr = 0;
	index_table->n_max  = n_max;
	index_table->words = malloc( n_max * sizeof * index_table->words );
	if( NULL == index_table->words ) {
		fprintf( stderr, "init_index_table: [!] nie udalo sie zaalokowac pamieci na index_table->words\n" );
		return NULL;
	}
}
