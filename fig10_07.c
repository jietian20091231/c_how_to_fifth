#include <stdio.h>
#include <limits.h>

void displayBits( unsigned int value );

int main( void )
{ 
  unsigned int x;

  printf( "Enter an unsigned integer: " );
  scanf( "%u", &x );

  displayBits( x );


  return 0;
}


void displayBits( unsigned int value )
{
  unsigned int c;

  unsigned int displayMask = 1 << ( CHAR_BIT * sizeof( unsigned ) - 1 );

  printf( "%10u = ", value );

  for( c = 0; c < CHAR_BIT * sizeof( unsigned ); c++ ) {
    putchar( value & displayMask ? '1' : '0' );
    value <<= 1;

    if( ( c + 1 ) % 8 == 0 )
      putchar( ' ' );
  }

  putchar( '\n' );
  
}
