#include <stdio.h>
#include <string.h>


int main( void )
{

  char x[] = "Home Sweet Home";

  printf( "&x[ 5 ] =%s\n", &x[ 5 ] );

  printf( "%s%s\n", "The string in array x before memove is: ", x );
  printf( "%s%s\n", "The string in array x after memove is: ",
	  ( char* ) memmove( x, &x[ 5 ], 10 ) );

  return 0;
}
