#include <stdio.h>
#include <stdlib.h>

#include "searchwords.h"
#include "indextable.h"
#include "indextable.h"
#include "mainutilities.h"

int main( int argc, char **argv ) {
	// Program call
	// ./a.out [file_path] word1 word2 .... wordn
	
	FILE *file_in = argc > 1 ? fopen( argv[1], "r" ) : stdin;

	if( NULL == file_in ) {
		fprintf( stderr, "%s: nie udalo sie otworzyc pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}

	if ( argc < 3 ) {
		fprintf( stderr, "%s: blad: nie podano slow do wyszukania\n", argv[0] );
		return EXIT_FAILURE;
	}
	
	int n_max = 2;
	index_table_t index_table = init_index_table( n_max );

	int i;
	for( i = 2; i < argc; i++ ) {
		add_word_to_index_table( index_table, argv[i], n_max );
	}

	disp_index_table( index_table );

	fill_index_table( index_table, file_in );

	disp_index_table( index_table );
	

	return 0;
}
