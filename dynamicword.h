#ifndef _DYNAMICWORD_H_
#define _DYNAMICWORD_H_

typedef struct {
	char *word_string;
	int n_curr;
	int n_max;
	int *line_numbers_vect;
} *dynamic_word_t;


dynamic_word_t init_dynamic_word( char *word_string, int n_max );

int add_to_dynamic_word( dynamic_word_t word_in, int line_number );

void disp_dynamic_word( dynamic_word_t word_in );

void destroy_dynamic_word( dynamic_word_t word_in );

#endif
