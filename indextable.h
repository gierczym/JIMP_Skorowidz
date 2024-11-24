#ifndef _INDEXTABLE_H_
#define _INDEXTABLE_H_

typedef struct {
	int n_max;
	int n_curr;
	dynamic_word_t *words;
} *index_table_t;


index_table_t init_index_table( int n_max );

int add_word_to_index_table( index_table_t index_in, char *word_string, int n_max );

void disp_index_table( index_table_t index_in );

void destroy_index_table( index_table_t index_in );

#endif
