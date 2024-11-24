#include <stdio.h>
#include <stdlib.h>

#include "dynamicword.h"
#include "indextable.h"

int main( int argc, char **argv ) {
	
	if( argc < 2 ) {
		fprintf( stderr, "%s: [!] blad: nie podano argumentow\n", argv[0] );
		return EXIT_FAILURE;
	}

	int n_max = 2;
	index_table_t index_table = init_index_table( n_max );

	int i;
	for( i = 1; i < argc; i++ ) {
		if( add_word_to_index_table( index_table, argv[i], n_max ) != 0 ) {
			fprintf( stderr, "%s: [!] blad podczas wywolania funkcji add_word_to_index_table\n", argv[0] );
			return EXIT_FAILURE;
		}
	}

	printf( "=== wyswietlanie po dodaniu slow ===\n");
	disp_index_table( index_table );
	printf( "\n" );

	int j;
	for( i = 0; i < index_table->n_curr; i++) {
		for( j = 0; j < 10 * n_max; j++ )
			if( add_to_dynamic_word( index_table->words[i], j ) != 0 ) {
				fprintf( stderr, "%s: [!] blad: nie udalo sie dodac linii %d-tej do slowa %d-tego\n", argv[0], j, i );
			}
	}
	printf( "=== wyswietlanie po dodaniu linii ===\n");
	disp_index_table( index_table );
	
	destroy_index_table( index_table );

	return 0;
}
