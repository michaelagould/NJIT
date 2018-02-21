#include <stdlib.h>
#include <string.h>


/*
** Make a copy of a string in dynamically allocated memory. Note:
** caller is responsible for checking whether the memory was
** allocated! This allows the caller to respond to an error in
** any way they wish.
*/
char* make_a_copy( char *str ) {
	char *new_str = NULL;
	if (str != NULL) {
		new_str = malloc( (strlen( str ) + 1) * sizeof( *str ) );
		if ( new_str != NULL )
			strcpy( new_str, str );
	}

	return new_str;
}