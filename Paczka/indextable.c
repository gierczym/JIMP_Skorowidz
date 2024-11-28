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
	return index_table;
}

int add_word_to_index_table( index_table_t index_in, char *word_string, int n_max ) {
	if( index_in->n_curr == index_in->n_max ) {
		dynamic_word_t *tmp = realloc( index_in->words, 2 * index_in->n_max * sizeof * index_in->words );
		if( NULL == tmp ) {
			fprintf( stderr, "add_word_to_index_table: [!] nie udalo sie przealokowac pamieci na index_in->words\n" );
			return 1;
		}
		index_in->words = tmp;
		index_in->n_max = 2 * index_in->n_max;
		index_in->words[index_in->n_curr] = init_dynamic_word( word_string, n_max );
		index_in->n_curr++;
	} else {
		index_in->words[index_in->n_curr] = init_dynamic_word( word_string, n_max );
		if( index_in->words[index_in->n_curr] == NULL ) printf("NULL\n");
		index_in->n_curr++;
	}
	return 0;
}


void disp_index_table( index_table_t index_in ) {
	int i;
	for( i = 0; i < index_in->n_curr; i++ )
		disp_dynamic_word( index_in->words[i] );
}

void destroy_index_table( index_table_t index_in ) {
	free( index_in-> words );
	free( index_in );
}
