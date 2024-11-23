#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamicword.h"

int main() {
	
	printf( "==================================\n" );
	printf( "=   TESTUJĘ MODUŁ: dynamicword   =\n" );
	printf( "==================================\n" );
	printf( "\n" );
	printf( "--- SCENARIUSZ NR 1: wywołanie funkcji inicjalizującej\n" );

	int n_max = 10;
	char *test_string = "słowo_testowe";
	dynamic_word_t dynamic_word = init_dynamic_word( test_string, n_max );
	
	if( NULL == dynamic_word ) {
		printf( "FAILED: nie udało się zaalokować pamięci na element dynamic_word\n" );
	} else {
		printf( "inicjalizowanie wektora linii o rozmiarze: %d\n", n_max );
		printf( "%s: dynamic_word->word_string: \"%s\", powinno być \"%s\"\n",
			       	strcmp(test_string, dynamic_word->word_string) == 0 ? "PASSED" : "FAILED",
	     			test_string,
		     		dynamic_word->word_string );
		
		printf( "%s: dynamic_word->n_curr: %d, powinno być %d\n",
			       	dynamic_word->n_curr == 0 ? "PASSED" : "FAILED",
	     			0,
		     		0 );
		
		printf( "%s: dynamic_word->n_max: %d, powinno być %d\n",
			       	n_max == dynamic_word->n_max ? "PASSED" : "FAILED",
	     			n_max,
	     			dynamic_word->n_max );
		
		printf( "wypisuję elementy wektora line_numbers_vect\n"
			"powinno się udać wypisać n_max = %d elementow\n"
			"o losowych wartościach bez segmentation fault\n", n_max );
	}
	
	int i;
	printf( ">>> [" );
	for( i = 0; i < n_max; i++ ) {
		printf( " %d", dynamic_word->line_numbers_vect[i] );
	}
	printf( " ]\n" );



	return 0;
}
