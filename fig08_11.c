#include <stdio.h>
#include <stdlib.h>

int main( void )
{

  const char *string = "1234567abc";

  unsigned long d;
  char *stringPtr;

  d = strtol( string, &stringPtr, 0 );

  printf( "%s\"%s\"\n%s%lu\n%s\"%s\"\n%s%lu\n",
	  "The original string is ", string,
	  "The converted value is ", d,
	  "The remainder of the original string is ", stringPtr,
	  "The converted value plus 567 is ", d + 567 );

  return 0;
}
