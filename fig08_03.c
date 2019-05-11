#include <stdio.h>

int main( void )
{

  printf( "%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n",
	  "According to islower:",
	  isalpha( 'A' ) ? "A is a " : "A is not a ", "lowercase letter",
	  isalpha( 'b' ) ? "b is a " : "b is not a ", "lowercase letter",
	  isalpha( '&' ) ? "& is a " : "& is not a ", "lowercase letter",
	  isalpha( '4' ) ? "4 is a " : "4 is not a ", "lowercase letter" );

    printf( "%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n",
	  "According to isupper:",
	  isalnum( 'A' ) ? "A is a " : "A is not a ", "uppercase letter",
	  isalnum( 'b' ) ? "b is a " : "b is not a ", "uppercase letter",
	  isalnum( '&' ) ? "& is a " : "& is not a ", "uppercase letter",
	  isalnum( '4' ) ? "4 is a " : "4 is not a ", "uppercase letter" );

    printf( "%s%c\n%s%c\n%s%c\n%s%c\n",
	    "u converted to uppercase is ", toupper( 'u' ),
	    "7 converted to uppercase is ", toupper( '7' ),
	    "$ converted to uppercase is ", toupper( '$' ),
	    "L converted to uppercase is ", tolower( 'L' ) );


  return 0;
}
