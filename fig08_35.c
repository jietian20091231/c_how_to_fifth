#include <stdio.h>
#include <string.h>


int main( void )
{

  char string[ 15 ] = "888888888888888";

  int intArray[ 16 ] = { 0 };

  printf( "string = %s\n", string );
  printf( "string after memset = %s\n", memset( string, 'b', 7 ) );

  memset( intArray, 1, 7 * sizeof( int ) );

  int i;
  for ( i = 0; i < 16; i++ ) {
    printf( "intArr[ %d ] = %d\n", i, intArray[ i ] );
  }
  

  return 0;
}
