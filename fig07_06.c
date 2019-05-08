/* Fig. 7.6: fig07_06.c
   Cube a variable using call-by-value */
#include <stdio.h>

int cubeByValue( int n );

int main( void )
{

  int number = 5;

  printf( "The original value of number is %d", number );

  number = cubeByValue( number );

  printf( "\nThe new value of number is %d\n", number );

  return 0;
}


int cubeByValue( int n )
{
  return n * n * n ;
}
