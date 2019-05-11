#include <stdio.h>

int main( void )
{
  char c;
  char sentence[ 5 ] = { 0 };
  char* pSentence = sentence;
  int i = 0;

  int len = sizeof( sentence ) / sizeof( char );

  for ( i = 0; i< len; i++ )
    printf( "sentence[ %d ] = %p, %p\n", i, pSentence++, sentence + i );

  i = 0;

  puts( "Enter a line of text:" );
  while ( ( c = getchar() ) != '\n' ) {
    if ( i >= ( sizeof( sentence ) / sizeof( char ) - 1 ) ) break;
    int j = i++;
    sentence[ j ] = c;
    printf( "sentence[ %d ] = %d( %p )\n", j, sentence[ j ], &sentence[ j ] );
  }
  
  printf( "sentence[ %d ] = %d( %p )\n", i, sentence[ i ], &sentence[ i ] );
  sentence[ i ] = '\0';
  

  puts( "\nThe line enterted was :" );
  puts( sentence  );

  putchar( '\n' );

  return 0;
}
