#include <stdio.h>
#include <stdlib.h>


int main ( void )
{
  long i;
  i = atof( "1000000" );

  printf( "%s%ld\n%s%ld\n",
	  "The string \"1000000\" converted to integer is ", i,
	  "The converted value divided by 2 is ", i / 2 );

  return 0;
}
