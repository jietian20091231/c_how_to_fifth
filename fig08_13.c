#include <stdio.h>
#include <string.h>

void reverse_recursive( const char* const sPtr );
void reverse_loop( const char* const sPtr );

int main( void )
{
  char sentence[ 80 ] = { 0 };
  printf( "Enter a line of text:\n" );
  gets( sentence );

  printf( "\nThe line printed backward is :\n" );
  reverse_loop( sentence );

  putchar( '\n' );

  return 0;
}

void reverse_recursive( const char* const sPtr )
{ 
  if ( sPtr[ 0 ] == '\0' ) {
    return;
  } else {
    reverse_recursive( &sPtr[ 1 ] );
    putchar( sPtr[ 0 ] );
  } 
}

void reverse_loop( const char* const sPtr )
{
  int len = strlen( sPtr );
  
  int i;

  for ( i = len - 1; i >= 0; i-- )
    putchar( *(sPtr + i ) );

  putchar( '\n' );
}
