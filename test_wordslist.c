#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordslist.h"

int main( int argc, char **argv ) {
	
	FILE *in = argc > 1 ? fopen( argv[1], "r" ) : stdin;
	
	if( NULL == in ) {
		fprintf( stderr, "%s: nie udalo sie otworzyc pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}
	
	int n_max = 5;
	words_list_t words_list = init_words_list( n_max );
	
	fill_words_list( words_list, in );
	
	disp_words_list( words_list );
	
	fclose( in );
	
	
	return 0;
}