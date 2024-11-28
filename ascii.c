#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	int i;

	for( i = 0; i <= 255; i++ ){
		printf(  "kod ASCII %3d: %c\n", i, i );
	}

	printf(  "kod ASCII %3d: %s\n", 'ą', "ą" );
	printf(  "kod ASCII %3d: %s\n", 'ę', "ę" );
	printf(  "kod ASCII %3d: %s\n", 'ł', "ł" );
	printf(  "kod ASCII %3d: %s\n", 'ć', "ć" );
	printf(  "kod ASCII %3d: %s\n", 'ź', "ź" );
	printf(  "kod ASCII %3d: %s\n", 'ż', "ż" );
	printf(  "kod ASCII %3d: %s\n", 'ó', "ó" );
	

	return 0;
}

