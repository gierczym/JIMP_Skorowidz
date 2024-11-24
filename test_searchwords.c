#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "searchwords.h"

char* createstr( char *str ) {
	char *tmp = malloc( (strlen(str)+1) * sizeof *tmp );
	return strcpy( tmp, str );

}

int main() {
	
	char *test_string;
	test_string = createstr("To, jest lancuch\\ testowy. Sprawdzam czy slowa zostana !   nalezycie # #odsepraowane");

	char *word;
	
	printf("%s\n", test_string);
	word = find_word( test_string );

	
	while( word != NULL ) {
		printf( "%s\n", word );
		word = find_word( NULL );
	}

	return 0;
}
