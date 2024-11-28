#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "searchwords.h"

int myisalnum( int c ) {
	static char *str = "ąęłźćżóćśń";
	static int i;
	for( i = 0; i < strlen(str); i++)
		if( c == *(str+i) )
			return 1;
	
	return isalnum(c);
}

char* find_word( char *str) {
	static char *eos = NULL;
	static char *curr = NULL;


	if( NULL == str ) { //search for word
		if( NULL == eos ) {
			fprintf( stderr, "find_word: [!] zle wywolanie find_word, tokeny nie zainicjowane\n" );
		}
		while( *curr != '\0' )
			curr++;

		if( curr == eos ) {
			eos = NULL;
			return NULL;
		}

		while( curr != eos ) {
			curr++;
			if( myisalnum(*curr) )
				return curr;
		}

	} else { //initialize function
		curr = NULL;
		int inword = 0;
		while( *str != '\0' ) {
			if( myisalnum(*str) ) {
				inword = 1;
				if( NULL == curr )
					curr = str;
			} else {
				if( inword == 1 )
					*str = '\0';
				inword = 0;
			}
			str++;
		}
		eos = str;

		return curr;
	}
}
