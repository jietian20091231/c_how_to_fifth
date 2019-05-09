#include <stdio.h>

void print_string( int argc, char* argv[] );

int main( void )
{

  const char *suit[ 4 ] = { "Hearts", "Diamond", "Clubs", "Spades" };
  print_string( 4, suit );

  return 0;
}

void print_string( int argc, char* argv[] )
{
  int i;
  for ( i = 0; i < argc; i++ ) {
    printf( "argv[ %d ] = %s\n", i, *( argv + i ) );
  }
  printf( "\n" );
}
