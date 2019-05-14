#include <stdio.h>
#include <string.h>

int main( void )
{
  const char *s = "This is a string";
  printf( "%s'%c'%s\"%s\"\n",
	  "The remainder of s after character ", 's',
	  " is found is ", memchr(s, 's', 16 ) );
 
  return 0;
}
