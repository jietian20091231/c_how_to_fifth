#include <stdio.h>
#include <stdlib.h>


int main ( void )
{
  int i;
  i = atof( "2593" );

  printf( "%s%d\n%s%d\n",
	  "The string \"2593\" converted to integer is ", i,
	  "The converted value minus 593 is ", i - 593 );

  return 0;
}
