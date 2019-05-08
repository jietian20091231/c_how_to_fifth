/* Fig. 7.7: fig07_07.c
   Cube a variable using call-by-refernece with a pointer number */
#include <stdio.h>

void cubeByReference( int *nPtr );

int main( void )
{

  int number = 5;
  printf( "The original value of number is %d, storage address is %p\n", number, &number );

  cubeByReference( &number );

  printf( "\nThe new value of number is %d\n", number );

  return 0;
}


/* calculate cube of *nPtr; modifies variable number in main */
void cubeByReference( int *nPtr )
{
  printf( "function cubeByRefernece parameter address is %p\n", nPtr );
  *nPtr = *nPtr * *nPtr * *nPtr;
}
