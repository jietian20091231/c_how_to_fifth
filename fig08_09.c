#include <stdio.h>
#include <stdlib.h>

int main( void )
{

  const char *string = "51.2% are admitted";

  double d;
  char *stringPtr;

  d = strtod( string, &stringPtr );

  printf( "The string \"%s\" is converted to the\ndouble value %.2f and the string \"%s\"\n", string, d, stringPtr );

  return 0;
}
