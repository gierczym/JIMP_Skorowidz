#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mainutilities.h"

#define BUFSIZE 8192

int fill_index_table_words( index_table_t index_in, words_list_t list ) {
	int i;
	int n_max = 2;
	for( i = 0; i < list->n_curr; i++ )
		if( add_word_to_index_table( index_in, list->words[i], n_max ) != 0 )
			fprintf( stderr, "fill_index_table_words: [!] blad przy wywolaniu funkcji add_to_index_table\n" );
}


int fill_index_table_lines( index_table_t index_in, FILE *in ) {

	char buf[BUFSIZE];
	
	int no_lines = 0;
	char *word;
	int i;

	while( fgets( buf, BUFSIZE, in ) != NULL ) {
		no_lines++;

		word = find_word( buf );
		while( word != NULL ) {
			for( i = 0; i < index_in->n_curr; i++ ) {
				if( strcmp( index_in->words[i]->word_string, word ) == 0 )
					if( add_to_dynamic_word( index_in->words[i], no_lines ) != 0)
						fprintf( stderr, "fill_index_table: [!] blad przy wywolaniu funkcji add_to_dynamic_word\n" );
			}
			word = find_word( NULL );
		}

	}

	return 0;
}


int compare_alpha( const void *a, const void *b ) {
	dynamic_word_t *ptrd_word1 = (dynamic_word_t *)a;
	dynamic_word_t *ptrd_word2 = (dynamic_word_t *)b;
	dynamic_word_t d_word1 = *ptrd_word1;
	dynamic_word_t d_word2 = *ptrd_word2;
	return strcmp( d_word1->word_string, d_word2->word_string );
}

int compare_lines( const void *a, const void *b ) {
	dynamic_word_t *ptrd_word1 = (dynamic_word_t *)a;
	dynamic_word_t *ptrd_word2 = (dynamic_word_t *)b;
	dynamic_word_t d_word1 = *ptrd_word1;
	dynamic_word_t d_word2 = *ptrd_word2;
	return d_word1->n_curr - d_word2->n_curr;
}

void sort_index_table( index_table_t index_in, int (*f)(const void *a, const void *b) ) {
	qsort( index_in->words, index_in->n_curr, sizeof * index_in->words, f );
}
