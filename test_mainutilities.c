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
	
	int n_max = 2;
	index_table_t index_table = init_index_table( n_max );

	words_list_t words_list = init_words_list( n_max );
	fill_words_list( words_list, file_in );
	
	fill_index_table_words( index_table, words_list );
	
	fseek( file_in, 0, SEEK_SET );
	fill_index_table_lines( index_table, file_in );

	disp_index_table( index_table );
	
	destroy_words_list( words_list );
	destroy_index_table( index_table );
	fclose( file_in );
	

	return 0;
}
