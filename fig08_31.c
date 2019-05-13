#include <stdio.h>
#include <string.h>


int main( void )
{

  char s1[ 17 ] = { 0 };
  char s2[] = "Hello, world! This is my first C programming.";

  memcpy( s1, s2, 16 );

  printf( "%s\n%s\"%s\"\n",
	  "After s2 is copied into s1 with memcpy,",
	  "s1 contains ", s1 );

  memset( s1, 0, 17 );

  strncpy( s1, s2, 16 );

  printf( "s1 = %s\n", s1 );

  return 0;
}
