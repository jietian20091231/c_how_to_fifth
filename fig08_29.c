#include <stdio.h>
#include <string.h>


int main( void )
{

  char string[] = "This is a sentence with 7 tokens";
  char clone[ sizeof( string ) / sizeof( char ) ];
  char *tokenPtr;

  strcpy( clone, string );

  printf( "%s\n%s\n\n%s\n",
	  "The string to be tokenized is : ", string,
	  "The tokens are:" );

  tokenPtr = strtok( clone, " " );

  while( tokenPtr != NULL ) {
    printf( "%s\n", tokenPtr );
    tokenPtr = strtok( NULL, " " );
  }

  printf( "string = %s\n", string );

  return 0;
}
