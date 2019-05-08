/* Fig. 7.11: fig07_11.c
   Printing a string one character at a time using
   a non-constant pointer to constant data */

#include <stdio.h>
#include <string.h>

void printCharacters( const char *sPtr );

int main( void )
{

  char string[] = "print characters of a string";

  printf( "The string is:\n" );
  printCharacters( string );
  printf( "\n" );

  printf( "string = %s\n", string );

  return 0;
}

/* sPtr cannot modify the character to which it points,
   i.e., sPtr is a "read-only" pointer */
void printCharacters( const char* sPtr )
{

  for ( ; *sPtr != '\0'; sPtr++ ) {
    printf( "%c", *sPtr );
  }


  /*
  const char* hello = "hello, world\n";
  memset( sPtr, 0, strlen( sPtr ) );
  strcpy( sPtr, hello );
  */
  
}
