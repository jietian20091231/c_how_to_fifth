/* Fig. 7.12: fig07_12.c
   Attempting to modify data through a
   non-constant pointer to constant data. */

#include <stdio.h>

void f( const int *xPtr );

int main(int argc, char *argv[])
{

  int y = 100;

  f( &y );

  printf("y = %d\n", y);
  
  return 0;
}


void f( const int *xPtr )
{
  *xPtr = 100;
}
