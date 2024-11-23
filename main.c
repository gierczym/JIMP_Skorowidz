#include <stdio.h>
#include <stdlib.h>

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

	

	return 0;
}
