#ifndef _WORDSLIST_H_
#define _WORDSLIST_H_

#include "searchwords.h"

typedef struct {
	int n_curr;
	int n_max;
	char **words;
} *words_list_t;

words_list_t init_words_list( int n_max );

int add_to_words_list( words_list_t list, char *word );

int fill_words_list( words_list_t list, FILE *in );

void disp_words_list( words_list_t list );

#endif