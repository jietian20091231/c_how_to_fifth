#include <stdio.h>
#include <limits.h>

void displayBits( unsigned int value );

int main( void )
{
  unsigned int a;
  unsigned int b;
  unsigned int mask;
  unsigned int setBits;

  a = 65535;
  mask = 1;
  printf( "The result of combining the following\n" );
  displayBits( a );
  displayBits( mask );
  printf( "using the bitwise AND operator & is\n" );
  displayBits( a & mask );

  a = 15;
  setBits = 241;
  printf( "\nThe result of combining the following\n" );
  displayBits( a );
  displayBits( setBits );
  printf( "using the bitwise inclusive OR operator | is\n" );
  displayBits( a | setBits );

  a = 139;
  b = 199;
  printf( "\nThe result of combining the following\n" );
  displayBits( a );
  displayBits( b );
  printf( "using the bitwise exclusive OR operator ^ is\n" );
  displayBits( a ^ b );

  a = 21845;
  printf( "\nThe result of combining the following\n" );
  displayBits( a );
  printf( "is\n" );
  displayBits( ~a );


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
