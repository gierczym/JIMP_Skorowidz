#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordslist.h"

#define BUFSIZE 8192

/*
typedef struct {
	int n_curr;
	int n_max;
	char **words;
} *words_list_t;
*/

words_list_t init_words_list( int n_max ) {
	words_list_t list = malloc( sizeof *list );
	if( NULL == list ) {
		fprintf( stderr, "init_words_list: nie udalo sie zaalokowac pamieci na typ words_list_t\n" );
		return NULL;
	}
	list->n_curr = 0;
	list->n_max = n_max;
	list->words = malloc( n_max * sizeof * list->words );
	if( NULL == list->words ) {
		fprintf( stderr, "init_words_list: nie udalo sie zaalokowac pamieci na words\n" );
		return NULL;
	}
	
	return list;
	
}

int add_to_words_list( words_list_t list, char *word ) {
	if( list->n_curr == list->n_max ) {
		char **tmp = realloc( list->words, 2 * list->n_max * sizeof(char *) );
		if( NULL == tmp ) {
			fprintf( stderr, "add_to_words_list: nie udalo sie zaalokowac pamieci na words\n" );
			return EXIT_FAILURE;
		}
		list->words = tmp;
		list->n_max = 2 * list->n_max;
		char *tmpword = malloc( (strlen(word)+1) * sizeof(char) );
		if( NULL == tmpword ) {
			fprintf( stderr, "add_to_words_list: nie udalo sie zaalokowac pamieci na word\n" );
			return EXIT_FAILURE;
		}
		list->words[list->n_curr] = tmpword;
		int i;
		for( i = 0; i <= strlen(word); i++ ) {
			*(list->words[list->n_curr]+i) = *(word+i);
		}
		list->n_curr++;
	} else {
		char *tmpword = malloc( (strlen(word)+1) * sizeof(char) );
		if( NULL == tmpword ) {
			fprintf( stderr, "add_to_words_list: nie udalo sie zaalokowac pamieci na word\n" );
			return EXIT_FAILURE;
		}
		list->words[list->n_curr] = tmpword;
		int i;
		for( i = 0; i <= strlen(word); i++ ) {
			*(list->words[list->n_curr]+i) = *(word+i);
		}
		list->n_curr++;
	}
	return 0;
}

int fill_words_list( words_list_t list, FILE *in ) {
	char buf[BUFSIZE];
	int i;
	char *word;
	
	int lines = 0;
	int new_word;
	while( fgets(buf, BUFSIZE, in) != NULL ) {
			lines++;
			word = find_word( buf );
			if( list->n_curr == 0) {
					add_to_words_list( list, word );
			}
			while( word != NULL ) {
				new_word = 1;
				for( i = 0; i < list->n_curr; i++ ) {
					if( strcmp(word, list->words[i]) == 0 )
						new_word = 0;
				}
				if( new_word == 1) {
					if( strcmp(word, "") != 0 )
						add_to_words_list( list, word );
				}
				word = find_word( NULL );
			}
	}
}

void disp_words_list( words_list_t list ) {
	int i;
	for( i = 0; i < list->n_curr; i++ ) {
		printf( "Slowo %3d: %s\n", i+1, list->words[i] );
	}
}
