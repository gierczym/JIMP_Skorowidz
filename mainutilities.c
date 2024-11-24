#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "searchwords.h"
#include "dynamicword.h"
#include "indextable.h"
#include "mainutilities.h"

#define BUFSIZE 8192

int fill_index_table( index_table_t index_in, FILE *in ) {

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
