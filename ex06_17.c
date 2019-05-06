#include <stdio.h>
#define SIZE 10

int whatIsThis( const int b[], int p );

int main()
{
  int x;

  int a[ SIZE ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  x = whatIsThis( a, SIZE );

  printf( "Result is %d.\n", x );


  return 0;
}


int whatIsThis( const int x[], int p )
{
  if ( p == 1 ) {
    
    printf( "x[ %d ] = %d\n", p ,x[ 0 ] );
    return x[ 0 ];
    
  } else {

    int a = x[ p - 1 ];
    int b = whatIsThis ( x, p - 1 );
    printf( "x[ %d - 1 ] = %d, whatIsThis( x,  %d - 1 ) = %d.\n", p, a, p, b );

    printf( " %d + %d = %d.\n", a, b, a + b );
    return a + b ;
    
  }
  
}
