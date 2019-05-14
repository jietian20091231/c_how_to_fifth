#include <stdio.h>
#include <string.h>

int main( void )
{
  const char *string1 = "abcdefghijklmnopqrstuvwxyz";
  const char *string2 = "four";
  const char *string3 = "boston";

  printf( "%s length is %lu\n", string1, strlen( string1 ) );
  printf( "%s length is %lu\n", string2, strlen( string2 ) );
  printf( "%s length is %lu\n", string3, strlen( string3 ) );  
}
