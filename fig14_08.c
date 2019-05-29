#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>


void signalHandler( int singalValue );

int main( void )
{

	int i;
	int x;

	signal( SIGINT, signalHandler );
	srand( clock() );

	for ( i = 0; i < 100; i++ ) {
		x = 1 + rand() % 50;

		if ( 25 == x ) {
			raise( SIGINT );
		}

		printf( "%4d" , i );

		if ( i % 10 == 0  ) {
			printf( "\n" );
		}
	}

	printf( "\n" );

	return 0;

}



void signalHandler( int singalValue )
{
	int response;

	printf( "%s%d%s\n%s",
			"\nInterrupt signal ( ", singalValue, " ) received. ",
			"Do you wish to continue ( 1 = yes or 2 = no )? " );
	scanf( "%d", &response );

	while ( response != 1 && response != 2 ) {
		printf( " ( 1 = yes or 2 = no )? " );
		scanf( "%d", &response );
	}

	if ( 1 == response ) {
		signal( SIGINT, signalHandler );
	} else {
		exit( EXIT_SUCCESS );
	}
}
