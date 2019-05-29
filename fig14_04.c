#include <stdio.h>
#include <stdlib.h>

void print( void );

int main( void ) {

	int answer;

	atexit( print );
	printf( "Enter 1 to terminate program with function exit\n"
			"Enter 2 to terminate program with function normally\n" );

	scanf( "%d", &answer );

	if( 1 == answer ) {
		printf( "\nTerminating program with function exit\n" );
		exit( EXIT_SUCCESS );
	}

	printf( "\nTerminating program by reaching the end of main\n" );

	return 0;

}


void print( void ) {
	printf( "Executing function print at prorgram "
			"termination\nProgram terminated\n" );
}
