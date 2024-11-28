#ifndef _MAINUTILITIES_H_
#define _MAINUTILITIES_H_

#include "searchwords.h"
#include "dynamicword.h"
#include "indextable.h"
#include "wordslist.h"

int fill_index_table_words( index_table_t index_in, words_list_t list );

int fill_index_table_lines( index_table_t index_in, FILE *in );


#endif
