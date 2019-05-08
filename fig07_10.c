/*Fig. 7.10: fig07_10.c
  Converting lowercase letters to uppercase letter
  using a non-constant pointer to non-constant data */

#include <stdio.h>
#include <ctype.h>

void convertToUpperCase( char *sPtr );

int main( void )
{

  char string[] = "characters and $32.98";

  printf( "The string before conversion is: %s", string );
  convertToUpperCase( string  );
  printf( "\nThe string after conversion is: %s\n", string );
  
  return 0;
}


void convertToUpperCase( char *sPtr )
{

  while ( *sPtr != '\0' ) {
    if ( islower( *sPtr ) ) {
      *sPtr = toupper( *sPtr );
    }

    sPtr++;
  }
}
