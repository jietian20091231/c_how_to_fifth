#include <stdio.h>

void copy1( char * const s1, const char * const s2 );
void copy2( char *s1, const char *s2 );

int main( void )
{
  char string1[ 10 ] = { 0 };
  char *string2 = "hello";
  char string3[ 10 ] = { 0 };
  char string4[] = "Good Bye";
  

  return 0;
}


void copy1( char * const s1, const char * const s2 )
{
  int i;
  for ( i = 0; ( s1[ i ] = s2[ i ]) != '\0'; i++) {
    ;
  }
}


void copy2( char *s1, const char *s2 )
{
  for ( ; ( *s1 = *s2 ) != '\0'; s1++, s2++ ) {
    ;
  }
}

