#include <stdio.h>
#include <string.h>
#include <math.h>

void praseHex( unsigned int n, char* hex, int bit );

int main( void )
{

  char hex[ 2 ] = { 0 };
  memset( hex, '0', sizeof( hex ) / sizeof( char ) - 1 );
  
  printf( "%+09d\n", 452 );
  printf( "%09d\n", 452 );
  printf( "%0X\n", 122 );
  printf( "#%s\n", hex );

  int i = 0;
  for ( i = 0; i < pow( 16 , sizeof( hex ) / sizeof( char ) - 1 ); i++ ) {
    memset( hex, '0', sizeof( hex ) / sizeof( char ) - 1 );
    praseHex( i, hex, sizeof( hex ) / sizeof( char ) );
    printf( "%d hex %s\n", i, hex );
  }

  return 0;
}

void praseHex( unsigned int n, char* hex, int bit )
{
  char tmp[ 8 ] = { 0 };
  sprintf( tmp, "%X", n );

  int j = 0;
  int i = bit - 1 - strlen( tmp );
  for( ; i < bit - 1; i++ ) {
    *( hex + i ) = *( tmp + j );
    j++;
  }
  
}
