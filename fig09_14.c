#include <stdio.h>

int main( void )
{

  int c = 1427;
  double p = 1427.00;

  printf( "%#o\n", c );
  printf( "%#x\n", c );
  printf( "%#X\n", c );
  printf( "\n%g\n", p );
  printf( "%#g\n", p );  

  return 0;
}
