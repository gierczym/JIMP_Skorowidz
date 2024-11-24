#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamicword.h"

int main() {
	
	printf( "==================================\n" );
	printf( "=   TESTUJE MODUL: dynamicword   =\n" );
	printf( "==================================\n" );
	printf( "\n" );
	printf( "--- SCENARIUSZ NR 1: wywolanie funkcji inicjalizujacej\n" );

	int n_max = 2;
	char *test_string = "slowo_testowe";
	dynamic_word_t dynamic_word = init_dynamic_word( test_string, n_max );
	
	if( NULL == dynamic_word ) {
		printf( "FAILED: nie udalo sie zaalokować pamieci na element dynamic_word\n" );
	} else {
		printf( "inicjalizowanie wektora linii o rozmiarze: %d\n", n_max );
		printf( "%s: dynamic_word->word_string: \"%s\", powinno byc \"%s\"\n",
			       	strcmp(test_string, dynamic_word->word_string) == 0 ? "[PASSED]" : "[FAILED]",
	     			test_string,
		     		dynamic_word->word_string );
		
		printf( "%s: dynamic_word->n_curr: %d, powinno byc %d\n",
			       	dynamic_word->n_curr == 0 ? "[PASSED]" : "[FAILED]",
	     			0,
		     		0 );
		
		printf( "%s: dynamic_word->n_max: %d, powinno byc %d\n",
			       	n_max == dynamic_word->n_max ? "[PASSED]" : "[FAILED]",
	     			n_max,
	     			dynamic_word->n_max );
		
		printf( "wypisuje elementy wektora line_numbers_vect\n"
			"powinno sie udać wypisac n_max = %d elementow\n"
			"o losowych wartosciach bez segmentation fault\n", n_max );
	}
	
	int i;
	printf( ">>> [" );
	for( i = 0; i < n_max; i++ ) {
		printf( " %d", dynamic_word->line_numbers_vect[i] );
	}
	printf( " ] - [PASSED]\n" );
	
	printf( "\n" );
	printf( "--- SCENARIUSZ NR 2: dodawanie i wymisywanie numerow linii\n" );
	printf( "Cel: Nie znaleziono slowa \"%s\"\n", test_string );
	disp_dynamic_word( dynamic_word );
	int *test_vector = malloc( 3 * n_max * sizeof(int) );
	printf( "Wektor testowy (cel:wynik): [");
	for( i = 0; i < 3 * n_max; i++ ){
		printf( " %d:", i );
		if( add_to_dynamic_word( dynamic_word, i ) != 0 ) {
			printf( "[FAILED]: funkcja add_to_dynamic_word zwrocila blad podczas dodawania elementu\n" );
		} else {
			printf( "%d", dynamic_word->line_numbers_vect[i] );
		}
	}
	printf(" ]\n");
	printf( "Testuj wyswietlanie:\n" );
	disp_dynamic_word( dynamic_word );
	
	destroy_dynamic_word( dynamic_word );



	return 0;
}
