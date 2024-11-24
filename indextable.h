#ifndef _INDEXTABLE_H_
#define _INDEXTABLE_H_

typedef struct {
	int n_max;
	int n_curr;
	dynamic_word_t *words;
} *index_table_t;


index_table_t init_index_table( int n_max );

#endif
